#include <cstdio>
#include <iostream>

constexpr int MAX_DEPTH{500};
constexpr int MAX_NAME{4};
constexpr int WIDTH{9};
constexpr int SQU_SIZE{WIDTH * WIDTH};
constexpr int COL_SIZE{SQU_SIZE * 4};
constexpr int MAX_NODES{COL_SIZE * WIDTH * SQU_SIZE + 1};

struct Node {
    int up, down, next, prev;
    union {
        int col;
        struct {
            char name[MAX_NAME];
            int len;
        } d;
    } d;
} nodes[MAX_NODES];
int ncnt{1};
int solution[MAX_DEPTH];

void add_row_node(int col, int offset)
{
    if (offset) {
        nodes[ncnt].prev = nodes[ncnt - offset].prev;
        nodes[nodes[ncnt - offset].prev].next = ncnt;
        nodes[ncnt - offset].prev = ncnt;
    } else {
        nodes[ncnt].prev = ncnt;
    }

    ++nodes[col].d.d.len;
    nodes[ncnt].d.col = col;
    nodes[ncnt].up = nodes[col].up;
    nodes[nodes[col].up].down = ncnt;
    nodes[col].up = ncnt++;
}

void init()
{
    ncnt = 1;
    nodes[0].next = nodes[0].prev = 0;

    // First 81 columns representing 9*9 positions;
    // Second 81 columns representing row*num;
    // Third 81 columns representing col*num;
    // Last 81 columns representing box*num.
    for (const char *fmt : {"%d,%d", "R%d%d", "C%d%d", "B%d%d"}) {
        for (int i{1}; i <= WIDTH; ++i) {
            for (int j{1}; j <= WIDTH; ++j) {
                std::snprintf(nodes[ncnt].d.d.name, MAX_NAME, fmt, i, j);
                nodes[ncnt].prev = ncnt - 1;
                nodes[ncnt - 1].next = ncnt;
                nodes[ncnt].up = ncnt;
                ++ncnt;
            }
        }
    }
    nodes[COL_SIZE].next = 0;
    nodes[0].prev = COL_SIZE;

    // Input rows
    for (int row{0}; row < WIDTH; ++row) {
        for (int col{0}; col < WIDTH; ++col) {
            int digit;
            std::cin >> digit;
            for (int d{1}; d <= WIDTH; ++d) {
                if (digit && digit != d) {
                    continue;
                }
                // position
                add_row_node(WIDTH * row + col + 1, 0);
                // row*digit
                add_row_node(SQU_SIZE + WIDTH * row + d, 1);
                // col*digit
                add_row_node(2 * SQU_SIZE + WIDTH * col + d, 2);
                // box*digit
                add_row_node(3 * SQU_SIZE + WIDTH * (row / 3 * 3 + col / 3) + d,
                             3);
                nodes[nodes[ncnt - 4].prev].next = ncnt - 4;
            }
        }
    }

    for (int c{1}; c <= COL_SIZE; ++c) {
        nodes[nodes[c].up].down = c;
    }
}

int answer[WIDTH][WIDTH];
void print_solution(int k)
{
    for (int i{0}; i < k; ++i) {
        int n{solution[i]};
        do {
            if (nodes[nodes[n].d.col].d.d.name[1] == ',') {
                answer[nodes[nodes[n].d.col].d.d.name[0] - '1']
                      [nodes[nodes[n].d.col].d.d.name[2] - '1'] =
                          nodes[nodes[nodes[n].next].d.col].d.d.name[2] - '0';
                break;
            }
            n = nodes[n].next;
        } while (n != solution[i]);
    }

    for (int row{0}; row < WIDTH; ++row) {
        for (int col{0}; col < WIDTH; ++col) {
            std::cout << answer[row][col] << (col == WIDTH - 1 ? '\n' : ' ');
        }
    }
}

void cover(int col)
{

    nodes[nodes[col].next].prev = nodes[col].prev;
    nodes[nodes[col].prev].next = nodes[col].next;
    for (int row{nodes[col].down}; row != col; row = nodes[row].down) {
        for (int n{nodes[row].next}; n != row; n = nodes[n].next) {
            nodes[nodes[n].up].down = nodes[n].down;
            nodes[nodes[n].down].up = nodes[n].up;
            --nodes[nodes[n].d.col].d.d.len;
        }
    }
}

void uncover(int col)
{
    for (int row{nodes[col].up}; row != col; row = nodes[row].up) {
        for (int n{nodes[row].prev}; n != row; n = nodes[n].prev) {
            ++nodes[nodes[n].d.col].d.d.len;
            nodes[nodes[n].up].down = n;
            nodes[nodes[n].down].up = n;
        }
    }
    nodes[nodes[col].next].prev = col;
    nodes[nodes[col].prev].next = col;
}

int select()
{
    int min{MAX_NODES};
    int n{-1};
    for (int col{nodes[0].next}; col; col = nodes[col].next) {
        if (nodes[col].d.d.len < min) {
            min = nodes[col].d.d.len;
            n = col;
        }
    }
    return n;
}

bool found{false};
void search(int k = 0)
{
    if (found) {
        return;
    }
    if (!nodes[0].next) {
        found = true;
        print_solution(k);
        return;
    }
    int col{select()};
    if (col == -1) {
        return;
    }
    cover(col);
    for (int row{nodes[col].down}; row != col; row = nodes[row].down) {
        solution[k] = row;
        for (int n{nodes[row].next}; n != row; n = nodes[n].next) {
            cover(nodes[n].d.col);
        }
        search(k + 1);
        for (int n{nodes[row].prev}; n != row; n = nodes[n].prev) {
            uncover(nodes[n].d.col);
        }
    }
    uncover(col);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    search();
}
