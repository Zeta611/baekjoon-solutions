#include <algorithm>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a, a + n);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int b;
        std::cin >> b;

        int *lower = std::lower_bound(a, a + n, b);
        int *upper = std::upper_bound(lower, a + n, b);
        std::cout << std::distance(lower, upper)
                  << (i != m - 1 ? ' ' : '\n');
    }

    delete[] a;

    return 0;
}
