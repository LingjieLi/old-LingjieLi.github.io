#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int _val)
        : val(_val)
    {
    }
};
TreeNode* createTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    // root->right->left = new TreeNode(6);

    // root->right->left->right = new TreeNode(7);

    return root;
};

vector<int> prederTravel(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<TreeNode*> mysatck;
    TreeNode* curNode = root;
    //mysatck.push(curNode);

    while (!mysatck.empty() || curNode != nullptr) {
        while (curNode != nullptr) {
            mysatck.push(curNode);
            res.push_back(curNode->val);
            curNode = curNode->left;
        }

        curNode = mysatck.top();
        mysatck.pop();
        curNode = curNode->right;
    }

    return res;
};
vector<int> inorderTravel(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<TreeNode*> mystack;
    TreeNode* curNode = root;

    while (!mystack.empty() || curNode != nullptr) {
        while (curNode != nullptr) {
            //res.push_back(curNode->val);
            mystack.push(curNode);
            curNode = curNode->left;
        }

        curNode = mystack.top();
        res.push_back(curNode->val);
        mystack.pop();
        curNode = curNode->right;
    }

    return res;
}
vector<int> postTravel(TreeNode* root)
{
    stack<int> resstack;
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    TreeNode* curNode = root;
    stack<TreeNode*> mystack;
    while (!mystack.empty() || curNode != nullptr) {
        while (curNode != nullptr) {
            mystack.push(curNode);
            resstack.push(curNode->val);
            curNode = curNode->right;
        }

        curNode = mystack.top();
        mystack.pop();
        curNode = curNode->left;
    }

    while (!resstack.empty()) {
        res.push_back(resstack.top());
        resstack.pop();
    }

    return res;
};

vector<int> levelTravel(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr) {
        return res;
    }

    queue<TreeNode*> myqueue;
    TreeNode* curNode = root;
    myqueue.push(curNode);

    while (!myqueue.empty()) {

        curNode = myqueue.front();
        res.push_back(curNode->val);
        myqueue.pop();

        if (curNode->left != nullptr) {
            myqueue.push(curNode->left);
        }
        if (curNode->right != nullptr) {
            myqueue.push(curNode->right);
        }
    }
};

void printvec(const vector<int>& data, string msg)
{
    cout << msg << ":\n";
    for (int val : data) {
        cout << val << "\t";
    }
    cout << "\n";
}

int main()
{
    TreeNode* root = createTree();
    string msg = "preorder";
    vector<int> result = prederTravel(root);
    printvec(result, msg);

    msg = "inorder";
    result = inorderTravel(root);
    printvec(result, msg);

    msg = "post";
    result = postTravel(root);
    printvec(result, msg);

    msg = "level";
    result = levelTravel(root);
    printvec(result, msg);
}