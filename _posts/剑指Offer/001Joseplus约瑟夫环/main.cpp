/*
 * @Description: 约瑟夫环
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-07 15:37:24
 * @Author: lydia
 * @Date: 2019-09-07 14:55:04
 */
#include <iostream>
#include <limits>
using namespace std;

struct ListNode {
    int val;
    bool isDelete = false;
    struct ListNode* next = nullptr;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Joseplus {
public:
    Joseplus(int n, int _idx)
        : num(n)
        , idx(_idx)
    {
        if (n > 0) {
            pHead = new ListNode(1);
        }
        ListNode* cNode = pHead;
        for (int i = 2; i <= n; i++) {
            cNode->next = new ListNode(i);
            cNode = cNode->next;
        }
        cNode->next = pHead;
    };
    int begin()
    {
        int size = num;
        ListNode* cNode = pHead;

        while (size != 1) {
            for (int j = 1; j < idx; j++) {
                cNode = getNext(cNode);
            }
            if (cNode == nullptr) {
                break;
            }
            cNode->isDelete = true;
            // cout << "delete : " << cNode->val << "\n";
            cNode = getNext(cNode);
            size--;
        }
        if (getNext(cNode) == nullptr) {
            return numeric_limits<int>::min();
        } else {
            return getNext(cNode)->val;
        }
    }

    ListNode* getNext(ListNode* cNode)
    {
        int round = 0;
        cNode = cNode->next;
        ///最多循环一圈
        while (cNode != nullptr && cNode->isDelete && round <= num) {
            cNode = cNode->next;
            round++;
        }
        if (cNode->isDelete) {
            return nullptr;
        }
        return cNode;
    }

    void print()
    {
        ListNode* cNode = pHead;
        for (int i = 0; i < num * 2; i++) {
            if (cNode != nullptr) {
                cout << cNode->val << "->";
                cNode = cNode->next;
            }
        }
        cout << "\n";
    };

private:
    int num = 0;
    int idx = 0;
    ListNode* pHead = nullptr;
};

int main()
{

    Joseplus* jose = new Joseplus(15, 4);
    //jose->print();
    //模拟约瑟夫环
    int res = jose->begin();
    cout << "joseplue output: " << res << "\n";
    return 0;
}