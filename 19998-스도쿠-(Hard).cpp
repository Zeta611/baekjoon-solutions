#include <cstdio>
#include <iostream>

constexpr int MAX_DEPTH{500};
constexpr int MAX_NAME{4};
constexpr int WIDTH{9};
constexpr int SQU_SIZE{WIDTH * WIDTH};
constexpr int COL_SIZE{SQU_SIZE * 4};
constexpr long MAX_NODES{COL_SIZE * WIDTH * SQU_SIZE + 1};

struct Node {
    Node *up, *down, *next, *prev;
    union {
        Node *col;
        struct {
            char name[MAX_NAME];
            int len;
        } d;
    } d;
} nodes[MAX_NODES];
long ncnt{1};
Node *root{nodes};
Node *solution[MAX_DEPTH];

void add_row_node(long col, long offset)
{
    if (offset) {
        nodes[ncnt].prev = nodes[ncnt - offset].prev;
        nodes[ncnt - offset].prev->next = &nodes[ncnt];
        nodes[ncnt - offset].prev = &nodes[ncnt];
    } else {
        nodes[ncnt].prev = &nodes[ncnt];
    }

    ++nodes[col].d.d.len;
    nodes[ncnt].d.col = &nodes[col];
    nodes[ncnt].up = nodes[col].up;
    nodes[col].up->down = &nodes[ncnt];
    nodes[col].up = &nodes[ncnt++];
}

void init()
{
    ncnt = 1;
    root->next = root->prev = root;

    // First 81 columns representing 9*9 positions;
    // Second 81 columns representing row*num;
    // Third 81 columns representing col*num;
    // Last 81 columns representing box*num.
    for (const char *fmt : {"%d,%d", "R%d%d", "C%d%d", "B%d%d"}) {
        for (int i{1}; i <= WIDTH; ++i) {
            for (int j{1}; j <= WIDTH; ++j) {
                std::snprintf(nodes[ncnt].d.d.name, MAX_NAME, fmt, i, j);
                nodes[ncnt].prev = &nodes[ncnt - 1];
                nodes[ncnt - 1].next = &nodes[ncnt];
                nodes[ncnt].up = &nodes[ncnt];
                ++ncnt;
            }
        }
    }
    nodes[COL_SIZE].next = root;
    root->prev = &nodes[COL_SIZE];

    // Input rows
    for (long row{0}; row < WIDTH; ++row) {
        for (long col{0}; col < WIDTH; ++col) {
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
                nodes[ncnt - 4].prev->next = &nodes[ncnt - 4];
            }
        }
    }

    for (long c{1}; c <= COL_SIZE; ++c) {
        nodes[c].up->down = &nodes[c];
    }
}

int answer[WIDTH][WIDTH];
void print_solution(int k)
{
    for (int i{0}; i < k; ++i) {
        Node *n{solution[i]};
        do {
            if (n->d.col->d.d.name[1] == ',') {
                answer[n->d.col->d.d.name[0] - '1']
                      [n->d.col->d.d.name[2] - '1'] =
                          n->next->d.col->d.d.name[2] - '0';
                break;
            }
            n = n->next;
        } while (n != solution[i]);
    }

    for (int row{0}; row < WIDTH; ++row) {
        for (int col{0}; col < WIDTH; ++col) {
            std::cout << answer[row][col] << (col == WIDTH - 1 ? '\n' : ' ');
        }
    }
}

void cover(Node *col)
{
    col->next->prev = col->prev;
    col->prev->next = col->next;
    for (Node *row{col->down}; row != col; row = row->down) {
        for (Node *n{row->next}; n != row; n = n->next) {
            n->up->down = n->down;
            n->down->up = n->up;
            --n->d.col->d.d.len;
        }
    }
}

void uncover(Node *col)
{
    for (Node *row{col->up}; row != col; row = row->up) {
        for (Node *n{row->prev}; n != row; n = n->prev) {
            ++n->d.col->d.d.len;
            n->up->down = n;
            n->down->up = n;
        }
    }
    col->next->prev = col;
    col->prev->next = col;
}

Node *select()
{
    long min{MAX_NODES};
    Node *n{nullptr};
    for (Node *col{root->next}; col != root; col = col->next) {
        if (col->d.d.len < min) {
            min = col->d.d.len;
            n = col;
        }
    }
    return n;
}

bool found{false};
void search(long k = 0)
{
    if (found) {
        return;
    }
    if (root->next == root) {
        found = true;
        print_solution(k);
        return;
    }
    Node *col{select()};
    if (!col) {
        return;
    }
    cover(col);
    for (Node *row{col->down}; row != col; row = row->down) {
        solution[k] = row;
        for (Node *n{row->next}; n != row; n = n->next) {
            cover(n->d.col);
        }
        search(k + 1);
        for (Node *n{row->prev}; n != row; n = n->prev) {
            uncover(n->d.col);
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
