#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        this->pre = pre;
        this->vin = vin;
        TreeNode* curNode = nullptr;
        pRoot = nullptr;
        if (pre.size() > 0) {
            int Root_No = 0;
            int Start = 0;
            int End = vin.size();
            bool isLeft = false;
            dfs(Root_No, Start, End, isLeft, curNode);
        }
        return pRoot;
    }

private:
    void dfs(int Root_No, int Start, int End, bool isLeft, TreeNode* curNode)
    {
        int Root_Val = pre[Root_No]; //根的值
        vector<int>::iterator root_it = find(vin.begin() + Start, vin.begin() + End, Root_Val);

        int lchild_size = root_it - (vin.begin() + Start);
        int rchild_size = vin.begin() + End - root_it - 1;
        int Root_No2 = root_it - vin.begin(); //在中序中的序号

        if (curNode == nullptr) {
            curNode = new TreeNode(Root_Val);
            pRoot = curNode;
        } else if (isLeft) {
            curNode->left = new TreeNode(Root_Val);
            curNode = curNode->left;
        } else {
            curNode->right = new TreeNode(Root_Val);
            curNode = curNode->right;
        }

        if (lchild_size > 0) {
            dfs(Root_No + 1, Start, Root_No2, true, curNode);
        }
        if (rchild_size > 0) {
            dfs(Root_No + lchild_size + 1, Root_No2 + 1, End, false, curNode);
        }
    }

    vector<int> pre;
    vector<int> vin;
    TreeNode* pRoot;
};

int main()
{
    vector<int> pre{ 1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> vin{ 4, 7, 2, 1, 5, 3, 8, 6 };
    Solution* sol = new Solution;
    sol->reConstructBinaryTree(pre, vin);
    return 0;
}