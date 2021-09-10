#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

int rec_cnt;
char records[100][101];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    std::cin.ignore();

    std::string line;
    char buf[101];
    while (t--) {
        getline(std::cin, line);
        std::istringstream iss(line);

        rec_cnt = 0;
        while (iss >> records[rec_cnt]) {
            ++rec_cnt;
        }

        while (true) {
            std::cin >> buf;
            std::cin >> buf;
            if (!strcmp(buf, "does")) {
                getline(std::cin, line);
                break;
            }

            std::cin >> buf;
            for (int i{0}; i < rec_cnt; ++i) {
                if (!strcmp(buf, records[i])) {
                    records[i][0] = '\0';
                }
            }
        }

        int i{0};
        while (i < rec_cnt) {
            for (; i < rec_cnt && records[i][0] == '\0'; ++i)
                ;
            for (; i < rec_cnt && records[i][0] != '\0'; ++i) {
                std::cout << records[i] << ' ';
            }
        }
    }
}
