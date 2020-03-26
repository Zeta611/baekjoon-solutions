#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> point;

enum class state {
    LAKE,
    UNCULTIVABLE,
    CULTIVABLE,
    CULTIVATED,
    FLOURISHED
};

enum class color { GREEN, RED };

struct cell {
    state state = state::LAKE;
    std::optional<color> color = std::nullopt;
    std::optional<int> distance = std::nullopt;
};

int solve(cell[50][50], int, int, const std::vector<point>&, int, int);
int maximum_flowers(const cell[50][50], int, int, const std::vector<point>&);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int rows, columns, greens, reds;
    std::cin >> rows >> columns >> greens >> reds;

    cell garden[50][50];
    std::vector<point> cultivable_cells;

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            int raw_state;
            std::cin >> raw_state;
            auto st = static_cast<state>(raw_state);
            garden[y][x].state = st;
            if (st == state::CULTIVABLE) {
                cultivable_cells.push_back(point(x, y));
            }
        }
    }

    std::cout
        << solve(garden, rows, columns, cultivable_cells, greens, reds)
        << '\n';

    return 0;
}

int solve(
    cell garden[50][50],
    int rows,
    int columns,
    const std::vector<point>& cultivable_cells,
    int greens,
    int reds
) {
    int result = -1;

    std::function<void(int,color,std::vector<point>::size_type)> inner;
    inner = [&](int left, auto color, auto progress) {
        if (left == 0) {
            switch (color) {
            case color::GREEN:
                inner(reds, color::RED, 0);
                break;
            case color::RED:
                result = std::max(
                    result,
                    maximum_flowers(garden, rows, columns, cultivable_cells)
                );
                break;
            }
        } else {
            for (auto i = progress; i < cultivable_cells.size(); ++i) {
                const auto cultivable = cultivable_cells[i];
                const int x = cultivable.first, y = cultivable.second;
                auto& cell = garden[y][x];
                if (cell.state != state::CULTIVABLE) { continue; }

                cell.state = state::CULTIVATED;
                cell.color = color;
                cell.distance = 0;

                inner(left - 1, color, i + 1);

                cell.state = state::CULTIVABLE;
                cell.color = std::nullopt;
                cell.distance = std::nullopt;
            }
        }
    };

    inner(greens, color::GREEN, 0);
    return result;
}

int maximum_flowers(
    const cell garden[50][50],
    int rows,
    int columns,
    const std::vector<point>& cultivable_cells
) {
    cell copy[50][50];
    std::memcpy(copy, garden, sizeof copy);

    auto visit = [&](point point, color color, int distance) -> bool {
        const int x = point.first, y = point.second;
        if (!(0 <= x && x < columns && 0 <= y && y < rows)) return false;

        auto& cell = copy[y][x];
        switch (cell.state) {
        case state::CULTIVABLE: case state::UNCULTIVABLE:
            cell.state = state::CULTIVATED;
            cell.color = color;
            cell.distance = distance;
            return true;

        case state::CULTIVATED: {
            const auto other_color = cell.color.value();
            const int other_distance = cell.distance.value();
            if (color != other_color && distance == other_distance) {
                cell.state = state::FLOURISHED;
            }
            return false;
        }

        case state::LAKE: case state::FLOURISHED:
            return false;
        }
    };

    auto adjs = [&](point p, color color, int distance) -> std::vector<point> {
        constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        std::vector<point> result;
        for (int i = 0; i < 4; ++i) {
            const auto to_visit = point(p.first + dx[i], p.second + dy[i]);
            if (visit(to_visit, color, distance)) {
                result.push_back(to_visit);
            }
        }
        return result;
    };

    auto bfs = [&]() {
        std::queue<point> green_queue, red_queue;

        for (auto cell : cultivable_cells) {
            const auto curr = copy[cell.second][cell.first];
            if (curr.state == state::CULTIVATED) {
                switch (curr.color.value()) {
                case color::GREEN:
                    green_queue.push(cell);
                    break;
                case color::RED:
                    red_queue.push(cell);
                    break;
                }
            }
        }

        int current_distance = 0;
        while (!(green_queue.empty() && red_queue.empty())) {
            point front;

            auto predicate1 = [&]() -> bool {
                if (green_queue.empty()) { return false; }
                front = green_queue.front();
                const auto cell = copy[front.second][front.first];
                return cell.state == state::CULTIVATED &&
                    cell.distance.value() == current_distance;
            };
            auto predicate2 = [&]() -> bool {
                if (green_queue.empty()) { return false; }
                front = green_queue.front();
                const auto cell = copy[front.second][front.first];
                return cell.state == state::FLOURISHED;
            };
            auto predicate3 = [&]() -> bool {
                if (red_queue.empty()) { return false; }
                front = red_queue.front();
                const auto cell = copy[front.second][front.first];
                return cell.state == state::CULTIVATED &&
                    cell.distance.value() == current_distance;
            };

            if (predicate1()) {
                green_queue.pop();
                int new_distance = current_distance + 1;
                for (auto cell : adjs(front, color::GREEN, new_distance)) {
                    green_queue.push(cell);
                }
            } else if (predicate2()) {
                green_queue.pop();
            } else if (predicate3()) {
                red_queue.pop();
                int new_distance = current_distance + 1;
                for (auto cell : adjs(front, color::RED, new_distance)) {
                    red_queue.push(cell);
                }
            } else {
                ++current_distance;
            }
        }
    };

    bfs();

    int count = 0;
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            if (copy[y][x].state == state::FLOURISHED) {
                ++count;
            }
        }
    }
    return count;
}
