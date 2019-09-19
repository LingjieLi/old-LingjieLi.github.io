/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/015整数中1出现的次数
* @fileName    main.cpp
* @brief        求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因* 此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出* 现的次数）。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-13 16:08:50
*
**/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        vector<int> num;
        int number_Length = numberLengh(n, num);

        for (int val : num) {
            cout << val << "\t";
        }
        cout << "\n";

        vector<int> sed;
        sed.push_back(0);
        string str = "9";
        for (int i = 1; i < number_Length; i++) {
            sed.push_back(std::stoi(str));
            str.push_back('9');
        }
        int res = 0;
        for (int i = 0; i < number_Length; i++) {
            int size = 0;
            size += n - sed[i];
            if (size % 10 == 0) {
                res += size / 10;
            } else {
                res += size / 10 + 1;
            }
            cout << "有" << size << "个数有第" << i + 1 << "位\n";
        }

        return res;
    }

private:
    int numberLengh(int n, vector<int>& num)
    {
        int length = 0;
        while (n != 0) {
            num.push_back(n % 10);
            n = n / 10;
            length++;
        }

        return length;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution* sol = new Solution;
    int res = sol->NumberOf1Between1AndN_Solution(n);
    cout << res << "\n";
    return 0;
}