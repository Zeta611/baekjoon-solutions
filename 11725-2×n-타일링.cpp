#include <iostream>
#include <utility>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int fi{1};
    int fj{1};
    while (n--) {
        fi = std::exchange(fj, (fi + fj) % 10'007);
    }
    std::cout << fi << '\n';
}
