#include <cstring>
#include <iostream>
#include <list>
#include <tuple>

using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        this->rows = rows;
        this->cols = cols;
        this->length = strlen(str);

        find = new bool[rows * cols];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                //  cout << matrix[getIndex(r, c)] << "\t";
                find[getIndex(r, c)] = false;
            }
            // cout << "\n";
        }

        bool has = false;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[getIndex(r, c)] == str[0]) {
                    res.push_back(make_tuple(r, c));
                    find[getIndex(r, c)] = true;
                    if (!hasPathX(matrix, str, 0, r, c)) {
                        res.pop_back();
                        find[getIndex(r, c)] = false;
                    } else {
                        has = true;
                        //cout << "find route,route:\n";
                        //printAndClearRoute(res, matrix);
                    }
                }
            }
        }

        return has;
    }

    bool hasPathX(char* matrix, char* str, int idx, int r, int c)
    {
        int i = getIndex(r, c);
        bool isLeft = false;
        bool isRight = false;
        bool isUp = false;
        bool isDown = false;
        //cout << r << "," << c << "," << idx << "\t" << matrix[i] << "," << str[idx] << "\n";
        if (matrix[i] == str[idx] && idx == length - 1) {
            return true;
        } else if (matrix[i] == str[idx]) {
            //选择一个方向移动
            //left
            if (c > 0 && !find[getIndex(r, c - 1)]) {
                //cout << "turn left\t";
                res.push_back(make_tuple(r, c - 1));
                find[getIndex(r, c - 1)] = true;
                isLeft = hasPathX(matrix, str, idx + 1, r, c - 1);
                if (!isLeft) {
                    res.pop_back();
                    find[getIndex(r, c - 1)] = false;
                }
            }
            //right
            if (c < cols - 1 && !find[getIndex(r, c + 1)]) {
                //cout << "turn right\t";
                res.push_back(make_tuple(r, c + 1));
                find[getIndex(r, c + 1)] = true;
                isRight = hasPathX(matrix, str, idx + 1, r, c + 1);
                if (!isRight) {
                    res.pop_back();
                    find[getIndex(r, c + 1)] = false;
                }
            }
            //up
            if (r > 0 && !find[getIndex(r - 1, c)]) {
                //cout << "turn up\t";
                res.push_back(make_tuple(r - 1, c));
                find[getIndex(r - 1, c)] = true;
                isUp = hasPathX(matrix, str, idx + 1, r - 1, c);
                if (!isUp) {
                    res.pop_back();
                    find[getIndex(r - 1, c)] = false;
                }
            }
            //down
            if (r < rows - 1 && !find[getIndex(r + 1, c)]) {
                //cout << "turn down\t";
                res.push_back(make_tuple(r + 1, c));
                find[getIndex(r + 1, c)] = true;
                isDown = hasPathX(matrix, str, idx + 1, r + 1, c);
                if (!isDown) {
                    res.pop_back();
                    find[getIndex(r + 1, c)] = false;
                }
            }
            return (isLeft || isRight || isUp || isDown);
        } else {
            return false;
        }
    }

private:
    int getIndex(int r, int c)
    {
        return r * cols + c;
    }

    void printAndClearRoute(list<tuple<int, int>>& res, const char* matrix)
    {
        while (!res.empty()) {
            int r = std::get<0>(res.front()), c = std::get<1>(res.front());
            char ch = matrix[getIndex(r, c)];
            cout << r << "," << c << ": " << ch << "\n";
            res.pop_front();
        }
    }
    void printRoute(const list<tuple<int, int>>& res)
    {
        for (list<tuple<int, int>>::const_iterator cit = res.cbegin(); cit != res.cend(); cit++) {
            cout << std::get<0>(*cit) << "," << std::get<1>(*cit) << "\n";
        }
    }

private:
    int rows, cols, length;
    list<tuple<int, int>> res;
    bool* find = nullptr;
};

int main()
{
    Solution* sol = new Solution;

    char* matrix = "ABCESFCSADEE";
    int rows = 3;
    int cols = 4;
    char* str = "ABCCED";

    bool res = sol->hasPath(matrix, rows, cols, str);
    cout << res << "\n";

    return 0;
}