//层序遍历转中序遍历
#include <iostream>
#include <vector>

using namespace std;

void trans(int level_size, const vector<int>& level, vector<int>& inorder)
{
    int start = 1; //*2
    int start_no = level.size() / 2; // /2
    int dis = 2; //*2
    int cur_level = level_size;
    int length = level.size() / 2 + 1; // /2
    inorder.resize(level.size());

    while (cur_level >= 1) {
        cout << "\n"
             << cur_level << "\t" << start << "\t" << dis << "\t" << start_no << "\t" << length << "\n";
        int _start = start;
        for (int i = start_no; i < start_no + length; i++) {
            cout << level[i] << "\t";
            inorder[i] = _start;
            _start += dis;
        }
        length /= 2;
        start_no /= 2;
        dis *= 2;
        start *= 2;
        cur_level--;
    }
};

int main()
{
    vector<int> level{ 1, 2, 3, 4, 5, 6, 7 };
    vector<int> inorder;

    int N = 3;
    trans(N, level, inorder);
    cout << "\n--------------\n";

    vector<int> res(level.size() + 1);

    for (int i = 0; i < inorder.size(); i++) {
        res[inorder[i]] = level[i];
    }

    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}