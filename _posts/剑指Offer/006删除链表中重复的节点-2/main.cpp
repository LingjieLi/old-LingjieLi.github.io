/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
#include <iostream>
#include <string>

using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
class Solution {
public:
    //删除重复的节点
    //(left,right]
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }
        ListNode* nullHead = new ListNode(pHead->val - 1);
        nullHead->next = pHead;

        string msg = "init";
        print(pHead, msg);

        //(left,right]
        ListNode* left = nullHead;
        ListNode* right = nullHead->next;
        while (left != nullptr && left->next != nullptr && right != nullptr && right->next != nullptr) {
            if (left->next->val != right->next->val) {
                //cout << left->next->val << "!=" << right->next->val << "\n";
                left = left->next;
                right = right->next;
            } else { //相等
                //cout << left->next->val << "==" << right->next->val << "\n";
                while (right != nullptr && right->next != nullptr && left->next->val == right->next->val) { //右边界后移
                    right = right->next;
                }
                if (right == nullptr || right->next == nullptr) { //删除(left,
                    //cout << "删除(left,:(" << left->val << ",\n";
                    left->next = nullptr;
                } else { //删除(left,right]
                    //cout << "删除(left,right]:(" << left->val << "," << right->val << "]\n";
                    left->next = right->next;
                    right = right->next;
                }
            }
        }
        //print(nullHead->next, "result");
        return nullHead->next;
    }

    void print(ListNode* pHead, string msg = "")
    {
        cout << msg << ":\n";

        ListNode* curNode = pHead;
        if (curNode != nullptr) {
            cout << curNode->val;
            curNode = curNode->next;
        }
        while (curNode != nullptr) {
            cout << "->" << curNode->val;
            curNode = curNode->next;
        }
        cout << "\n";
    }
};

int main()
{
    ListNode* pHead = nullptr;
    ListNode* cNode = nullptr;
    int val;
    int length = 0;
    cin >> length;
    for (int i = 0; i < length; i++) {
        cin >> val;
        if (pHead == nullptr) {
            pHead = new ListNode(val);
            cNode = pHead;
        } else {
            cNode->next = new ListNode(val);
            cNode = cNode->next;
        }
    }

    Solution* sol = new Solution;
    pHead = sol->deleteDuplication(pHead);
}