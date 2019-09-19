/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/011二叉树中和为某一值的路径
* @fileName    main.cpp
* @brief  输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结* 点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
* @author  lydia <vera71@126.com>
* @date    2019-09-12 17:35:25
*
**/
#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> route;
        if (root) {
            dfs(root, expectNumber, route, res);
        }
        // multimap<int, vector<int>> temp;
        // for (auto val : res) {
        //     temp.insert(pair<int, vector<int>>(val.size(), val));
        // }
        // res.clear();
        // for (auto val : temp) {
        //     res.push_back(val.second);
        // }
        return res;
    }

private:
    bool dfs(TreeNode* root, int expectNumber, vector<int>& route, vector<vector<int>>& res)
    {
        //cout << "Node " << root->val << "\texpectNumber " << expectNumber << "\n";
        if (root->left == nullptr && root->right == nullptr && expectNumber == root->val) {
            route.push_back(root->val);
            res.push_back(route);
            route.pop_back();
            return true;
        }

        bool lflag = false, rflag = false;
        if (root->left != nullptr) {
            route.push_back(root->val);
            lflag = dfs(root->left, expectNumber - root->val, route, res);
            route.pop_back();
        }

        if (root->right != nullptr) {
            route.push_back(root->val);
            rflag = dfs(root->right, expectNumber - root->val, route, res);
            route.pop_back();
        }
        return lflag || rflag;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(-3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(3);

    int exceptNumber = 7;

    Solution* sol = new Solution;
    vector<vector<int>> route = sol->FindPath(root, exceptNumber);

    for (vector<int> r : route) {
        for (int val : r) {
            cout << val << "\t";
        }
        cout << endl;
    }
    return 0;
}
