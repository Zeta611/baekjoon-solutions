#include <iomanip>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long fct{1};
    for (int i{1}; i <= n; ++i) {
        fct = fct * i;
        while (fct >= 10 && !(fct % 10)) {
            fct /= 10;
        }
        fct %= 1'000'000'000'000;
    }

    std::cout << std::setfill('0') << std::setw(5) << fct % 100'000 << '\n';
}
