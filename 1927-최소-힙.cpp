#include <algorithm>
#include <iostream>

constexpr int MAX_SIZE{100'000};
inline bool cmp(int a, int b) { return a > b; }
class Heap
{
    int container[MAX_SIZE];
    int size{0};

    inline static int parent(int i) { return (i - 1) >> 1; }
    inline static int right(int i) { return (i + 1) << 1; }
    inline static int left(int i) { return (i << 1) + 1; }

    void heapify(int i)
    {
        const int l{left(i)};
        const int r{right(i)};
        int m{l < size && cmp(container[i], container[l]) ? l : i};
        if (r < size && cmp(container[m], container[r])) {
            m = r;
        }
        if (m != i) {
            std::swap(container[i], container[m]);
            heapify(m);
        }
    }

  public:
    inline bool empty() const { return size == 0; }
    inline int top() const { return container[0]; }

    void update_key(int i, int x)
    {
        container[i] = x;
        int p{parent(i)};
        while (i && cmp(container[p], container[i])) {
            std::swap(container[i], container[p]);
            i = p;
            p = parent(i);
        }
    }

    void push(int x)
    {
        container[size] = x;
        update_key(size++, x);
    }

    void pop()
    {
        container[0] = container[--size];
        heapify(0);
    }
} heap;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    while (n--) {
        int x;
        std::cin >> x;
        if (x) {
            heap.push(x);
        } else {
            if (heap.empty()) {
                std::cout << "0\n";
            } else {
                std::cout << heap.top() << '\n';
                heap.pop();
            }
        }
    }
}
