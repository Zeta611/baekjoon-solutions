#include <iostream>

int _fct[1001]{1};
int fct(int n)
{
    int &f{_fct[n]};
    if (f) {
        return f;
    }

    f = n * fct(n - 1);
    while (f >= 10 && !(f % 10)) {
        f /= 10;
    }
    return f = f % 10'000;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << fct(n) % 10 << '\n';
    }
}
