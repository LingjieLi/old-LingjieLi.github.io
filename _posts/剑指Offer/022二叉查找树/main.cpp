/**
* @projectName E:\LingjieLi.github.io\_posts\剑指Offer\022二叉查找树
* @fileName    main.cpp
* @brief       二叉查找树
*
* @author  lydia <vera71@126.com>
* @date    2019-09-18 14:55:17
*
**/
//Binary Search Tree

#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int key;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    BSTNode* parent = nullptr;

    BSTNode(int _key)
        : key(_key){};
};

class BSTree {
private:
    BSTNode* pRoot; //根节点

public:
    BSTree(){};
    ~BSTree(){};

    //遍历
    vector<int> preOrder();
    vector<int> inOrder();
    vector<int> postOrder();

    //查找
    BSTNode* search(int key);
    BSTNode* iterativeSearch(int key);

    //查找特殊节点
    int minimum();
    //查找最大节点
    int maxmum();

    //后继节点，比它大的最小节点
    BSTNode* successor(BSTNode* x);

    //前驱节点，比它小的最大节点
    BSTNode* presuccessor(BSTNode* x);

    void insert(int key);
    void remove(int key);

    //销毁二叉树
    void destory();

    //打印二叉树
    void print();
};

void BSTree::preOrder() {}

int main()
{
    return 0;
};