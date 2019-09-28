/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/ExchangeMoney
* @fileName    exchangecoins1.cpp
* @brief       暴力搜索
*
* @author  lydia <vera71@126.com>
* @date    2019-08-06 22:03:28
*
**/

#include <vector>
#include <iostream>

using namespace std;
int exchangemoney(vector<int> arr, vector<int>& size, int aim);
int process(vector<int> arr, vector<int>& size, int index, int aim);

const int maxsize = 100;
int main()
{
    vector<int> arr{ 5, 10, 25, 1 };
    vector<int> size;
    size.resize(arr.size());
    int aim = 20;
    int ways = exchangemoney(arr, size, aim);
    cout << "ways: " << ways << "\n";
    return 0;
};

int exchangemoney(vector<int> arr, vector<int>& size, int aim)
{
    if (aim < 0 || arr.size() == 0) {
        return 0;
    }
    return process(arr, size, 0, aim);
};

int process(vector<int> arr, vector<int>& size, int index, int aim)
{
    int res = 0;
    if (index == arr.size()) {
        int sum = 0;
        for (int s : size) {
            sum += s;
        }
        if (sum <= maxsize && aim == 0) {
            for (int s : size) {
                cout << s << "\t";
            }
            cout << "\n";
            res = 1;
        } else {
            res = 0;
        }
    } else {
        for (int i = 0; arr[index] * i <= aim; i++) {
            size[index] = i;
            res += process(arr, size, index + 1, aim - arr[index] * i);
        }
    }
    return res;
};