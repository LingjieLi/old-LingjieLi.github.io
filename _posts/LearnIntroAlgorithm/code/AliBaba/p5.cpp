/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-01 20:55:11
 * @Author: lydia
 * @Date: 2019-09-01 20:08:56
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int color; //颜色1红色
    int level = 0;
    int whiteLen = 0; //连续白色的个数
    Node* left = nullptr;
    Node* right = nullptr;
};
int main()
{
    int t, k;
    cin >> t >> k;
    cout << "t=" << t << "\n";

    /*int gId = 0;

    while (gId < t) { //t组数据

        int res = 0;
        int start, end;
        cin >> start >> end;

        stack<Node*> data;

        Node* tree = new Node;
        tree->color = -1;
        tree->level = 0;
        tree->whiteLen = 0;

        data.push(tree);

        while (!data.empty()) {
            Node* curNode = data.top();
            data.pop();

            if (curNode->level >= end) {
                continue;
            }

            if (curNode->whiteLen + end - curNode->level >= k) { //允许白色和红色

                curNode->left = new Node;
                curNode->left->color = 1;
                curNode->left->level = curNode->level + 1;
                curNode->left->whiteLen = curNode->whiteLen;

                if (curNode->left->level >= start && curNode->left->level <= end && curNode->left->whiteLen % k == 0) {
                    res++;
                }

                curNode->right = new Node;
                curNode->right->color = 0;
                curNode->right->level = curNode->level + 1;
                curNode->right->whiteLen = curNode->whiteLen + 1;

                if (curNode->right->level >= start && curNode->right->level <= end && curNode->right->whiteLen % k == 0) {
                    res++;
                }

                data.push(curNode->left);
                data.push(curNode->right);

            } else { //只能填充红色
                curNode->left = new Node;
                curNode->left->color = 1;
                curNode->left->level = curNode->level + 1;
                curNode->left->whiteLen = curNode->whiteLen;

                if (curNode->left->level >= start && curNode->left->level <= end && curNode->left->whiteLen % k == 0) {
                    res++;
                }

                data.push(curNode->right);
            }
        }

        gId++;
        cout << res << endl;
    }*/

    return 0;
}
