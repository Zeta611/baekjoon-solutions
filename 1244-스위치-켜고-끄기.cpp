#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s;
    std::cin >> s;
    std::string str;
    copy_n(std::istream_iterator<char>(std::cin), s, back_inserter(str));
    reverse(begin(str), end(str));
    std::bitset<100> switches{str};

    int n;
    std::cin >> n;
    while (n--) {
        int sex, m;
        std::cin >> sex >> m;

        switch (sex) {
        case 1:
            for (int i{m}; i <= s; i += m) {
                switches[i - 1].flip();
            }
            break;

        case 2:
            switches[m - 1].flip();
            for (int i{m - 1}, j{m + 1};
                 i >= 1 && j <= s && switches[i - 1] == switches[j - 1];
                 --i, ++j) {
                switches[i - 1].flip();
                switches[j - 1].flip();
            }
            break;

        default:
            break;
        }
    }

    for (int i{0}; i < s; ++i) {
        std::cout << switches[i] << (i == s - 1 || i % 20 == 19 ? '\n' : ' ');
    }
}
