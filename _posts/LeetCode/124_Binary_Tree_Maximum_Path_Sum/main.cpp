#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    int sum = std::numeric_limits<int>::min();
    int maxPathSum(TreeNode* root)
    {
        map<TreeNode*, int> maxpath_memo;
        ///init memoization
        initMemo(maxpath_memo, root);

        //dynamix pragramming with memoization
        memoMaxPathSum(root, maxpath_memo);
        return sum;
    }

    /**
    * @name     memoMaxPathSum
    * @brief    dfs with memoization
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-27 12:56:38
    * @return
    *
    **/
    int memoMaxPathSum(TreeNode* node, map<TreeNode*, int>& memo)
    {
        if (node == NULL) {
            return 0;
        }

        if (memo.at(node) != std::numeric_limits<int>::min()) {
            return memo.at(node);
        }

        int left_path = memoMaxPathSum(node->left, memo);
        int right_path = memoMaxPathSum(node->right, memo);

        vector<int> values;
        values.push_back(node->val);
        values.push_back(node->val + left_path);
        values.push_back(node->val + right_path);
        values.push_back(node->val + right_path + left_path);

        //std::cout << "left max: " << left_path << "\tright_path:" << right_path << "\tvalue:" << node->val << "\n";
        int x = *max_element(values.begin(), values.end());

        //int x= max(node->val, max(node->val + left_path, max(node->val + right_path, max(node->val + left_path + right_path, node->val))));
        sum = max(sum, x);

        int max_path = node->val + max(left_path, max(right_path, 0));
        memo.at(node) = max_path;

        return max_path;
    }

    /**
    * @name     initMemo
    * @brief    level traversal to init memoization by 
                minimum value
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-27 12:55:48
    * @return
    *
    **/
    void initMemo(map<TreeNode*, int>& memo, TreeNode* root)
    {
        //层级遍历 初始化备忘
        queue<TreeNode*> myqueue;
        TreeNode* current = root;
        if (current) {
            myqueue.push(current);

            while (!myqueue.empty()) {
                current = myqueue.front();
                //current->val = std::numeric_limits<int>::min();
                memo[current] = std::numeric_limits<int>::min();
                myqueue.pop();
                if (current->left != NULL) {
                    myqueue.push(current->left);
                }
                if (current->right != NULL) {
                    myqueue.push(current->right);
                }
            }
        }
    }
};

void trimLeftTrailingSpaces(string& input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string& input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    })
                    .base(),
        input.end());
}

TreeNode* stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
};

int main()
{
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        int ret = Solution().maxPathSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }

    return 0;
}