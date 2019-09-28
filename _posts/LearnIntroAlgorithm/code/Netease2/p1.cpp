/*
 * @Description: 二进制回文数
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-07 19:18:46
 * @Author: lydia
 * @Date: 2019-09-07 19:05:39
 */

#include <iostream>
#include <string>

using namespace std;

string toBinary{

};
bool HuiWen(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
};
int main()
{
    int T;
    cin >> T;

    int num;
    string res;
    for (int i = 0; i < T; i++) {
        cin >> num;
        res = toBinary(num);
        if (HuiWen(res)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}