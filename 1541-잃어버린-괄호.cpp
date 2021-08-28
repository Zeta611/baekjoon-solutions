#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int max_eval(std::vector<int> &operands, std::vector<char> &operators)
{
    auto it{begin(operators)};
    while ((it = find(it, end(operators), '+')) != end(operators)) {
        const auto j{next(begin(operands), distance(begin(operators), it))};
        *j += *(j + 1);
        operands.erase(j + 1);
        operators.erase(it);
    }
    return accumulate(cbegin(operands) + 1, cend(operands), operands[0],
                      std::minus<int>());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> operands;
    std::vector<char> operators;
    operands.reserve(25);
    operators.reserve(24);

    std::string str;
    std::getline(std::cin, str);
    std::istringstream iss{str};

    int n;
    char op;
    iss >> n;
    operands.push_back(n);
    while (!iss.eof()) {
        iss >> op >> n;
        operators.push_back(op);
        operands.push_back(n);
    }

    std::cout << max_eval(operands, operators) << '\n';
}
