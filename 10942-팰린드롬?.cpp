#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

int numbers[2000];
int dp[2000][2000];

bool palindrome(int s, int e)
{
    int &val{dp[s - 1][e - 1]};
    if (val >= 0) {
        return val;
    }

    if (s >= e) {
        return val = true;
    }
    if (numbers[s - 1] == numbers[e - 1]) {
        return val = palindrome(s + 1, e - 1);
    } else {
        return val = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(dp, -1, sizeof dp);

    int n;
    std::cin >> n;
    copy_n(std::istream_iterator<int>(std::cin), n, std::begin(numbers));

    int m;
    std::cin >> m;
    while (m--) {
        int s, e;
        std::cin >> s >> e;
        std::cout << palindrome(s, e) << '\n';
    }
}
