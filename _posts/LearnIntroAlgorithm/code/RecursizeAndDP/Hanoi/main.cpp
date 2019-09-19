/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-09 18:16:01
 * @Author: lydia
 * @Date: 2019-08-09 15:50:48
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int Hanoi(int n, char a, char b, char c)
    {
        if (n == 1) {
            Move(1, a, c);
        } else {
            Hanoi(n - 1, a, c, b);
            Move(n, a, c);
            Hanoi(n - 1, b, a, c);
        }

        return times;
    };

private:
    void Move(int n, char from, char to)
    {
        times++;
        cout << "move " << from << " to " << to << "\n";
    }

private:
    int times = 0;
};
int main()
{
    Solution sol;
    int times = sol.Hanoi(7, 'A', 'B', 'C');
    std::cout << "times : " << times << "\n";
    return 1;
}