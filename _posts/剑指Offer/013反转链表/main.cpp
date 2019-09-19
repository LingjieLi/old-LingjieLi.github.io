/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/013反转链表
* @fileName    main.cpp
* @brief    输入一个链表，反转链表后，输出新链表的表头。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-13 11:33:10
*
**/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {

        print(pHead);
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }
        if (pHead->next->next == nullptr) {
            ListNode* newHead = pHead->next;
            pHead->next->next = pHead;
            pHead->next = nullptr;

            return newHead;
        }
        ListNode* curNode = pHead->next; //当前节点
        ListNode* lastNode = pHead; //未来curNode的下一个
        ListNode* nextNode = pHead->next->next; //原来curNode的下一个

        while (curNode != nullptr && nextNode != nullptr) {

            ListNode* tmp = nextNode->next;

            curNode->next = lastNode;
            nextNode->next = curNode;

            lastNode = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }
        curNode->next = lastNode;
        pHead->next = nullptr;

        print(curNode);
        return curNode;
    }

    void print(ListNode* pHead)
    {
        ListNode* curNode = pHead;
        while (curNode != nullptr) {
            cout << curNode->val << "\t";
            curNode = curNode->next;
        }
        cout << "\n";
    }
};

int main()
{
    int tmp;
    cin >> tmp;
    ListNode* pHead = new ListNode(tmp);
    ListNode* curNode = pHead;

    if (cin.get() != '\n') {
        while (cin >> tmp) {
            curNode->next = new ListNode(tmp);
            curNode = curNode->next;
            if (cin.get() == '\n') {
                break;
            }
        }
    }

    Solution* sol = new Solution;
    sol->ReverseList(pHead);
}