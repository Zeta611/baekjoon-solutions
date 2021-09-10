#include <iostream>

bool thue_morse(long long k)
{
    if (k == 0) {
        return false;
    }

    long long n{k};
    long long m{1};
    while (n) {
        n >>= 1;
        m <<= 1;
    }
    m >>= 1;
    return !thue_morse(k - m);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long k;
    std::cin >> k;
    std::cout << thue_morse(k - 1) << '\n';
}
