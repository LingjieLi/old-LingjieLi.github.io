/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 21:11:37
 * @Author: lydia
 * @Date: 2019-08-10 21:02:18
 */
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int value;
    Node* next = nullptr;
    Node(int data)
        : value(data){};
};
class Solution {
public:
    void CommonPart(Node* head1, Node* head2)
    {
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->value < head2->value) {
                head1 = head1->next;
            } else if (head1->value > head2->value) {
                head2 = head2->next;
            } else {
                cout << head1->value << " ";
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        cout << "\n";
    };
};

int main()
{
    vector<int> data1{ 1, 2, 3, 4, 8, 9, 10, 22, 23, 32, 14 };
    vector<int> data2{ 2, 3, 4, 32, 14, 43 };

    Node* head1 = new Node(data1[0]);
    Node* head2 = new Node(data2[0]);
    Node *p = head1, *q = head2;
    for (int i = 1; i < data1.size(); i++) {
        p->next = new Node(data1[i]);
        p = p->next;
    }

    for (int i = 1; i < data2.size(); i++) {
        q->next = new Node(data2[i]);
        q = q->next;
    }

    Solution sol;
    sol.CommonPart(head1, head2);
}