#include <iostream>
#include <vector>

using namespace std;

class MinPathSum {
public:
    static int minpathsum1(vector<vector<int>> map, vector<pair<int, int>>& route)
    {
        route.clear();
        if (map.size() == 0) {
            return -1;
        }
        int rows = map.size();
        int cols = map[0].size();

        vector<vector<int>> dp;
        dp.resize(rows);
        for (vector<int>& vec : dp) {
            vec.resize(cols);
        }

        dp[0][0] = 0;
        for (int r = 1; r < rows; r++) {
            dp[r][0] = dp[r - 1][0] + map[r][0];
        }

        for (int c = 0; c < cols; c++) {
            dp[0][c] = dp[0][c - 1] + map[0][c];
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + map[r][c];
            }
        }

        ///get route
        int r = rows - 1, c = cols - 1;
        route.insert(route.begin(), pair<int, int>(r, c));
        while (r != 0 || c != 0) {
            if ((dp[r - 1][c] < dp[r][c - 1] && r != 0) || c == 0) {
                route.insert(route.begin(), pair<int, int>(r - 1, c));
                r--;
            } else {
                route.insert(route.begin(), pair<int, int>(r, c - 1));
                c--;
            }
        }

        return dp[rows - 1][cols - 1];
    };
    static int minpathsum1(vector<vector<int>> map){};
    static int minpathsum2(vector<vector<int>> map)
    {
        if (map.size() == 0) {
            return -1;
        }
        int rows = map.size();
        int cols = map[0].size();
        bool flag = true; //横向增长
        flag = rows > cols ? true : false;
        int length = min(rows, cols);
        int dim2 = max(rows, cols);
        vector<int> arr;
        arr.resize(length);
        arr[0] = map[0][0];
        for (int l = 1; l < length; l++) {
            arr[l] = flag ? map[0][l] + arr[l - 1] : map[l][0] + arr[l - 1];
        }

        for (int i = 1; i < dim2; i++) {
            ///更新一行
            arr[0] = arr[0] + (flag ? map[i][0] : map[0][i]);
            for (int l = 1; l < length; l++) {
                arr[l] = min(arr[l - 1], arr[l]) + (flag ? map[i][l] : map[l][i]);
            }
        }

        return arr[length - 1];
    };
};

int main()
{
    vector<vector<int>> M = {
        { 1, 3, 5, 9 },
        { 8, 6, 3, 4 },
        { 5, 0, 6, 5 }
    };
    vector<pair<int, int>> route;
    int length1 = MinPathSum::minpathsum1(M, route);
    int length2 = MinPathSum::minpathsum2(M);

    std::cout << "method 1: "
              << "minnum route length : " << length1 << "\n";

    std::cout << "method 2: "
              << "minnum route length : " << length2 << "\n";

    for (auto p : route) {
        cout << "(" << p.first << "," << p.second << ") ->";
    }
    std::cout << "\n";
    return 1;
}