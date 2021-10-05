#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string dict[100'001];
    std::unordered_map<std::string, int> rev_dict;
    for (int i{1}; i <= n; ++i) {
        std::string name;
        std::cin >> name;
        dict[i] = name;
        rev_dict[name] = i;
    }

    while (m--) {
        std::string query;
        std::cin >> query;
        if (query[0] >= '0' && query[0] <= '9') {
            std::cout << dict[stoi(query)] << '\n';
        } else {
            std::cout << rev_dict[query] << '\n';
        }
    }
}
