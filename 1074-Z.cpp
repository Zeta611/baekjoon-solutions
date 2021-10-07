#include <iostream>

template <int N> struct Pow2 {
    consteval Pow2()
    {
        for (int i{1}; i < N; ++i) {
            val[i] = val[i - 1] * 2;
        }
    }
    constexpr int operator[](int n) const { return val[n]; }

  private:
    int val[N]{1};
};
constexpr Pow2<29> pow2;

int order(int n, int r, int c)
{
    if (!r && !c) {
        return 0;
    }

    const int quarter{pow2[2 * (n - 1)]};
    if (r < pow2[n - 1]) {
        if (c < pow2[n - 1]) {
            return order(n - 1, r, c);
        } else {
            return quarter + order(n - 1, r, c - pow2[n - 1]);
        }
    } else {
        if (c < pow2[n - 1]) {
            return 2 * quarter + order(n - 1, r - pow2[n - 1], c);
        } else {
            return 3 * quarter + order(n - 1, r - pow2[n - 1], c - pow2[n - 1]);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r, c;
    std::cin >> n >> r >> c;
    std::cout << order(n, r, c) << '\n';
}
