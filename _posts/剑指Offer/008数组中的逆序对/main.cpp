/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/007最大连续子序列和/008数组中的逆序对
* @fileName    main.cpp
* @brief
* 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
* 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
* @author  lydia <vera71@126.com>
* @date    2019-09-12 13:54:33
*
**/

#include <vector>
#include <iostream>

using namespace std;

//暴力解法50%
/*class Solution {
public:
    int InversePairs(vector<int> data)
    {
        if (data.size() <= 1) {
            return 0;
        }
        int fast = 1;
        int slow = 0;
        int count = 0;
        for (; slow < data.size() - 1; slow++) {
            for (fast = slow + 1; fast < data.size(); fast++) {
                if (data[slow] > data[fast])
                    count++;
            }
        }
        return count;
    }
};*/

class Solution {
public:
    //归并排序时间复杂度O(nlogn),空间复杂度O(n)
    int InversePairs(vector<int> data)
    {
        vector<int> space = data;
        int left = 0, right = data.size() - 1;
        int count = mergerSort(data, space, left, right);
        print(data);
        print(space);
        return count;
    }

private:
    //[left,right]
    //统计逆序对数目
    //归并排序
    int mergerSort(vector<int>& data, vector<int>& space, int left, int right)
    {
        //cout << left << "->" << right << ":\n";
        // print(data);
        // print(space);
        int count = 0;
        if (right - left > 1) {
            int mid = (left + right) / 2; //mid偏左
            int lcount = mergerSort(data, space, left, mid) % 1000000007;
            int rcount = mergerSort(data, space, mid + 1, right) % 1000000007;
            int mcount = merge(data, space, left, mid, right) % 1000000007;
            count = (lcount + rcount + mcount) % 1000000007;
        } else {
            if (data[left] > data[right]) {

                space[left] = data[right];
                space[right] = data[left];

                //swap
                int temp = data[left];
                data[left] = data[right];
                data[right] = temp;

                count = 1;
            }
        }
        //cout << count << "\n";
        return count;
    };
    //[left,right]
    int merge(vector<int>& data, vector<int>& space, int left, int mid, int right)
    {
        //cout << left << "->" << right << ":";
        // print(data);
        // print(space);
        //cout << "\n";
        int first = left;
        int second = mid + 1;
        int idx = left;
        int count = 0;
        while (first <= mid && second <= right) {
            if (data[first] > data[second]) {
                space[idx] = data[second];
                count = count + mid - first + 1;
                if (count >= 1000000007) //数值过大求余
                    count %= 1000000007;
                second++;
            } else {
                space[idx] = data[first];
                first++;
            }
            idx++;
        }
        while (first <= mid) {
            space[idx] = data[first];
            idx++;
            first++;
        }
        while (second <= right) {
            space[idx] = data[second];
            idx++;
            second++;
        }

        for (int l = left; l <= right; l++) {
            data[l] = space[l];
        }
        return count;
    };
    void print(vector<int>& data)
    {
        for (int val : data) {
            cout << val << "\t";
        }
        cout << endl;
    }
};
int main()
{
    /*vector<int> data{ 364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575 };*/
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 0 };
    Solution* sol
        = new Solution;
    int res = sol->InversePairs(data);
    cout << res << "\n";
}