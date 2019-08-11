/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/ExchangeMoney
* @fileName    exchangecoins2.cpp
* @brief       带备忘的暴力搜索
*
* @author  lydia <vera71@126.com>
* @date    2019-08-06 22:03:41
*
**/
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> notes;

int exchangemoney(vector<int> arr, vector<int>& size, int aim);
int process(vector<int> arr, vector<int>& size, int index, int aim, vector<vector<int>>& notes);

int main()
{
    vector<int> arr{ 5, 10, 25, 1 };
    vector<int> size;
    int maxnum = 8;
    int aim = 40;

    int ways = exchangemoney(arr, size, aim);
    std::cout << "ways : " << ways << "\n";
    return 0;
}

int exchangemoney(vector<int> arr, vector<int>& size, int aim)
{
    if (aim < 0 || arr.size() == 0) {
        return 0;
    }

    ///notes[i][j]=0 未被访问过
    ///notes[i][j]=-1 计算过 返回值为0
    notes.resize(arr.size() + 1);
    for (vector<int>& vec : notes) {
        vec.resize(aim + 1);
    }

    return process(arr, size, 0, aim, notes);
};

int process(vector<int> arr, vector<int>& size, int index, int aim, vector<vector<int>>& notes)
{
    int res = 0;
    if (index == arr.size()) {
        res = aim == 0 ? 1 : 0;
    } else {
        int mapValue = 0;
        for (int i = 0; arr[index] * i <= aim; i++) {
            mapValue = notes[index + 1][aim - arr[index] * i];
            if (mapValue != 0) {
                res += mapValue == -1 ? 0 : mapValue;
            } else {
                res += process(arr, size, index + 1, aim - arr[index] * i, notes);
            }
        }
    }
    notes[index][aim] = res == 0 ? -1 : res;
    return res;
}