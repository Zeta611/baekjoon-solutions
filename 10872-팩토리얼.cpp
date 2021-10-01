#include <iostream>

template <int N> struct Fct {
    consteval Fct()
    {
        for (int i{1}; i < N; ++i) {
            val[i] = val[i - 1] * i;
        }
    }

    constexpr int operator[](int i) const { return val[i]; }

  private:
    int val[N]{1};
};

constexpr auto fct{Fct<13>()};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << fct[n] << '\n';
}
