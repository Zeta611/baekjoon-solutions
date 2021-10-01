#include <iostream>

template <int N> struct Five {
    consteval Five()
    {
        for (int i{1}; i < N; ++i) {
            val[i] = val[i - 1] * 5;
        }
    }

    constexpr int operator[](int i) const { return val[i]; }

  private:
    int val[N]{1};
};
constexpr auto fives{Five<13>()};

int fct0(int m)
{
    int last{-1};

    int lo{5};
    int hi{500'000'000};
    while (lo <= hi) {
        const int mid{(lo + hi) / 2};

        int cnt{0};
        for (int i{1}; i < 13; ++i) {
            cnt += mid / fives[i];
        }

        if (cnt == m) {
            last = mid;
        }
        if (cnt < m) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return last;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;
    std::cout << fct0(m) << '\n';
}
