#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address)
    {
        std::vector<int> position;
        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                position.push_back(i);
            }
        }

        for (int i = 0; i < position.size(); i++) {
            int pos = position[i] + i * 2;
            address.insert(pos, 1, '[');
            address.insert(pos + 2, 1, ']');
        }

        return address;
    }
};

int main()
{
    Solution sol;
    string res = "8.8.8.8";
    std::cout << "input:" << res << "\n";
    res = sol.defangIPaddr(res);
    std::cout << "output:" << res << "\n";
    return 1;
}