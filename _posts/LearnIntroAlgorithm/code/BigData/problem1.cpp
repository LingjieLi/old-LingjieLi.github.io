/*
 * @Description: problem 1:判断一个整数是否在20亿数中
 * https://mp.weixin.qq.com/s?__biz=MzIzMTE1ODkyNQ==&mid=2649409856&idx=1&sn=448772acaf9b2f1a87f4d7c1caf4caa9&chksm=f0b60ca2c7c185b4cb93d0deffed461e6ba3e421e362c17102415e351a496792fa26e0282dc0&scene=21#wechat_redirect
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-04 10:08:55
 * @Author: lydia
 * @Date: 2019-09-04 09:16:24
 */

#include <iostream>
#include <vector>
#include <limits>
#include <bitset>
#include <algorithm>

const unsigned int length = std::numeric_limits<short>::max();

using namespace std;
int main()
{
    cout << "length =" << length << "\n";

    vector<short> testset{ 1, 2, 3, 70, 17, 9 };
    bitset<length> data; //32767位byte 每一位都是0

    for (uint32_t val : testset) {
        data[val] = 1;
    }

    int val;
    while (cin >> val) {
        if (data[val] == 1) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    return 0;
}