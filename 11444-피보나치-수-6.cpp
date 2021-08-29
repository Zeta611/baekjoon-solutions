#include <iostream>
#include <tuple>
constexpr long long MODULUS{1'000'000'007};

long long fibonacci(long long n)
{
    if (n <= 1) {
        return n;
    }

    n -= 2;
    long long m00{1};
    long long m01{1};
    long long m10{1};
    long long m11{0};

    long long a00{1};
    long long a01{1};
    long long a10{1};
    long long a11{0};
    while (n) {
        if (n % 2) {
            std::tie(m00, m01, m10, m11) =
                std::tuple((m00 * a00 + m01 * a10) % MODULUS,
                           (m00 * a01 + m01 * a11) % MODULUS,
                           (m10 * a00 + m11 * a10) % MODULUS,
                           (m10 * a01 + m11 * a11) % MODULUS);
        }
        std::tie(a00, a01, a10, a11) =
            std::tuple((a00 * a00 + a01 * a10) % MODULUS,
                       (a00 * a01 + a01 * a11) % MODULUS,
                       (a10 * a00 + a11 * a10) % MODULUS,
                       (a10 * a01 + a11 * a11) % MODULUS);
        n /= 2;
    }

    return m00;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    std::cout << fibonacci(n) << '\n';
}
