/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/010数据流中的中位数
* @fileName    main.cpp
* @brief
* 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么 * 中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-12 17:11:21
*
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        data.resize(data.size() + 1);
        int i = data.size() - 1;
        while (i > 0 && data[i - 1] > num) {
            data[i] = data[i - 1];
            i--;
        }
        data[i] = num;
        count++;
    }

    double GetMedian()
    {
        int mid = count / 2;
        if (count % 2 == 0) {
            return (data[mid] + data[mid - 1]) / 2.0;
        } else {
            return data[mid];
        }
    }

private:
    vector<int> data;
    int count = 0;
};

int main()
{
    int val;
    Solution* sol = new Solution;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        sol->Insert(val);
        cout << "median: " << sol->GetMedian() << "\n";
    }
}