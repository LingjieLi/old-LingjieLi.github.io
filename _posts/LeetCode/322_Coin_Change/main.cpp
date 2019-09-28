#include <iostream>
#include <sstream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int c_size = 0;
    bool coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end(), std::greater<int>()); //从大到小排序
        for (int val : coins) {
            std::cout << val << "\t";
        }
        std::cout << "\n";

        c_size = coins.size();

        int coin_index = 0;

        std::cout << "amount\tcoint\n";
        if (subcoinChange(coins, amount, coin_index)) {
            return true;
        }
        return false;
    }

    //硬币面值，金额，最大面值
    bool subcoinChange(vector<int>& coins, int amount, int coin_index)
    {
        if (amount != 0 && coin_index < c_size) {

            int cur_coin = coins[coin_index];
            int max_size = amount / cur_coin;

            std::cout << amount << "\t" << cur_coin << "\n";

            for (int size = max_size; size >= 0; size--) {
                if (subcoinChange(coins, amount - size * cur_coin, coin_index + 1)) {
                    amount -= size * cur_coin;
                    std::cout << size << "*" << cur_coin << "\n";
                    break;
                }
            }
        }
        if (amount != 0) {
            return false;
        } else {
            return true;
        }
    }
};

void trimLeftTrailingSpaces(string& input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string& input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    })
                    .base(),
        input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);

        bool ret = Solution().coinChange(coins, amount);
        std::cout << "could change? " << ret << std::endl;

        /*string out = to_string(ret);
        cout << out << endl;*/
    }
    return 0;
}