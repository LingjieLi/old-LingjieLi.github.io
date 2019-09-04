/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LeetCode/590_N-ary_Tree_Postorder_Traversal
* @fileName    N-aryPosterOrderTraversal.cpp
* @brief       多叉树后序遍历
*
* @author  lydia <vera71@126.com>
* @date    2019-05-30 19:41:19
*
**/
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<int> postorder(Node* root)
    {
        vector<int> list;
        Node* BN = root;
        stack<Node*> mystack;

        stack<Node*> resultstack;

        while (BN || mystack.empty()) {
            while (BN) {
                mystack.push(BN);
                resultstack.push(BN);
                int child_size = (BN->children).size();
                if (child_size) {
                    BN = (BN->children)[child_size - 1];
                    vector<Node*>::iterator it = BN->children.begin() + child_size - 1;
                    BN->children.erase(it);
                } else {
                    BN = nullptr;
                }
            }
            BN = mystack.top();
            mystack.pop();
            int child_size = (BN->children).size();
            if (child_size) {
                BN = (BN->children)[child_size - 1];
                vector<Node*>::iterator it = BN->children.begin() + child_size - 1;
                BN->children.erase(it);
            } else {
                BN = nullptr;
            }
        }

        while (!resultstack.empty()) {
            list.push_back(resultstack.top()->val);
            resultstack.pop();
        }
        return list;
    }

    static Node* createTree(std::string filename)
    {
        std::ifstream fin(filename);
        if (fin.is_open()) {
            //prepare
            std::string line;
            std::stringstream ss;
            int nodesize = 0;
            ss.str("");
            ss.clear();

            getline(fin, line);
            ss.str(line);
            ss >> nodesize;
            while (getline(fin, line)) {
                ss.str("");
                ss.clear();
                ss.str(line);
                        }

            fin.close();
        }
    }
};
int main()
{
    Solution sol;
    //sol.postorder();
    return 0;
}