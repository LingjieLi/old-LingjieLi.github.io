/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/017机器人的运动范围
* @fileName    main.cpp
* @brief       地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标* 和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。但是，它不能进入方格（35, 38）* ，因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？
*
* @author  lydia <vera71@126.com>
* @date    2019-09-14 20:41:38
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        this->threshold = threshold;
        this->rows = rows;
        this->cols = cols;
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        if (0 < rows && 0 < cols && getDigitSum(0, 0) <= threshold && !visited[0][0]) {
            visited[0][0] = true;
            movingCountCore(0, 0);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (visited[r][c])
                    count++;
            }
        }

        return count;
    }

private:
    bool movingCountCore(int r, int c)
    {
        bool isLeft = false;
        bool isRight = false;
        bool isUp = false;
        bool isDown = false;
        //cout << r << "," << c << "\n";
        //left
        // if (r > 0 && getDigitSum(r - 1, c) <= threshold && !visited[r - 1][c]) {
        //     visited[r - 1][c] = true;
        //     isLeft = movingCountCore(r - 1, c);
        //     if (!isLeft) {
        //         visited[r - 1][c] = false;
        //     }
        // }
        //right
        if (r < rows - 1 && getDigitSum(r + 1, c) <= threshold && !visited[r + 1][c]) {
            visited[r + 1][c] = true;
            isRight = movingCountCore(r + 1, c);
            // if (!isRight) {
            //     visited[r + 1][c] = false;
            // }
        }
        //up
        // if (c > 0 && getDigitSum(r, c - 1) <= threshold && !visited[r][c - 1]) {
        //     visited[r][c - 1] = true;
        //     isUp = movingCountCore(r, c - 1);
        //     if (!isUp) {
        //         visited[r][c - 1] = false;
        //     }
        // }
        //down
        if (c < cols - 1 && getDigitSum(r, c + 1) <= threshold && !visited[r][c + 1]) {
            visited[r][c + 1] = true;
            isDown = movingCountCore(r, c + 1);
            // if (!isDown) {
            //     visited[r][c + 1] = false;
            // }
        }

        return isLeft || isRight || isUp || isDown;
    }
    int getDigitSum(int r, int c)
    {
        int sum = 0;
        while (r > 0) {
            sum += r % 10;
            r /= 10;
        }
        while (c > 0) {
            sum += c % 10;
            c /= 10;
        }
        return sum;
    }

private:
    vector<vector<bool>> visited;
    int threshold;
    int rows, cols;
};
int main()
{
    Solution* sol = new Solution;
    int threshold = 0;
    int rows = 10, cols = 10;
    int count = sol->movingCount(threshold, rows, cols);
    cout << count << "\n";
    return 0;
}