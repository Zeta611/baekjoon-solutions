#include <iostream>
#include <limits>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;

    unsigned bitset{0};

    char op[7];
    unsigned x;
    while (m--) {
        std::cin >> op;

        switch (op[1]) {
        case 'd': // add
            std::cin >> x;
            bitset |= 1 << x;
            break;
        case 'e': // remove
            std::cin >> x;
            bitset &= ~(1 << x);
            break;
        case 'h': // check
            std::cin >> x;
            std::cout << !!(bitset & (1 << x)) << '\n';
            break;
        case 'o': // toggle
            std::cin >> x;
            bitset ^= 1 << x;
            break;
        case 'l': // all
            bitset = std::numeric_limits<unsigned>::max();
            break;
        case 'm': // empty
            bitset = 0;
            break;
        }
    }
}
