/**************************************************************************
*
*   Copyright (C) 2019 by lydia <vera71@126.com>
*
*   All Rights Reserved
*
**************************************************************************/
/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DataStructureChenHe/code
* @fileName    3BinaryTree.cpp
* @brief       二叉树的一些操作
*
* @author  lydia <vera71@126.com>
* @date    2019-05-29 16:42:56
*
**/

#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;
typedef struct BiNode {
    char data;
    BiNode* lChild = nullptr;
    BiNode* rChild = nullptr;
} BiNode, *BiTree;

int nodesize;

//创建一棵二叉树
BiTree createTree(string filename)
{
    std::ifstream fin(filename);
    if (fin.is_open()) {
        fin >> nodesize;
        BiNode* nodelist = new BiNode[nodesize]; //在堆上创建一块内存
        for (int i = 0; i < nodesize; i++) {
            char data, lc, rc;
            fin >> data >> lc >> rc;
            nodelist[i].data = data;
            if (lc != '-') {
                nodelist[i].lChild = nodelist + (lc - '0');
            } else {
                nodelist[i].lChild = nullptr;
            }

            if (rc != '-') {
                nodelist[i].rChild = nodelist + (rc - '0');
            } else {
                nodelist[i].rChild = nullptr;
            }

            //cout << nodelist[i].data << "\t" << nodelist[i].lChild << "\t" << nodelist[i].rChild << "\n";
        }

        fin.close();
        return nodelist;
    }
    return nullptr;
}

///Pre-Order Traversal 递归的先序遍历
void RecursivePreOrderTraversal(BiTree bitree)
{
    if (bitree) {
        cout << bitree->data << "\t";
        RecursivePreOrderTraversal(bitree->lChild);
        RecursivePreOrderTraversal(bitree->rChild);
    }
}

void NonRecursivePreOrderTraversal(BiTree bitree)
{
    stack<BiNode*> mystack;
    BiNode* BN = bitree;
    while (BN || !mystack.empty()) {
        while (BN) {
            mystack.push(BN);
            std::cout << BN->data << "\t";
            BN = BN->lChild;
        }
        BN = mystack.top();
        mystack.pop();
        BN = BN->rChild;
    }
}

///In-Order Traversal 递归的中序遍历
void RecursiveInOrderTraversal(BiTree bitree)
{
    if (bitree) {
        RecursiveInOrderTraversal(bitree->lChild);
        cout << bitree->data << "\t";
        RecursiveInOrderTraversal(bitree->rChild);
    }
}
void NonRecursiveInOrderTraversal(BiTree bitree)
{
    stack<BiNode*> mystack;
    BiNode* BN = bitree;
    while (BN || !mystack.empty()) {
        while (BN) {
            mystack.push(BN);
            BN = BN->lChild;
        }
        BN = mystack.top();
        mystack.pop();
        std::cout << BN->data << "\t";
        BN = BN->rChild;
    }
}

///Post-Order Traversal 递归的后序遍历
void RecursivePostOrderTraversal(BiTree bitree)
{
    if (bitree) {
        RecursivePostOrderTraversal(bitree->lChild);
        RecursivePostOrderTraversal(bitree->rChild);
        cout << bitree->data << "\t";
    }
}
void NonRecursivePostOrderTraversal(BiTree bitree)
{
    BiNode* BN = bitree;
    stack<BiNode*> mystack;
    stack<BiNode*> resultstack;
    while (BN || !mystack.empty()) {
        while (BN) {
            mystack.push(BN);
            resultstack.push(BN);
            BN = BN->rChild;
        }
        BN = mystack.top();
        mystack.pop();
        BN = BN->lChild;
    }

    while (!resultstack.empty()) {
        std::cout << resultstack.top()->data << "\t";
        resultstack.pop();
    }
}

///breadth-first traversal
void BreathFirstTraversal(BiTree bitree)
{
    BiNode* BN = bitree;
    queue<BiNode*> myqueue;
    if (bitree) {
        myqueue.push(BN);
    }
    while (!myqueue.empty()) {
        BN = myqueue.front();
        std::cout << BN->data << "\t";
        myqueue.pop();
        if (BN->lChild) {
            myqueue.push(BN->lChild);
        }
        if (BN->rChild) {
            myqueue.push(BN->rChild);
        }
    }
}

///后序遍历获取树的高度
int PostOrderGetHeight(BiTree bitree)
{
    if (bitree) {
        int lHeight, rHeight, maxHeight;
        lHeight = PostOrderGetHeight(bitree->lChild);
        rHeight = PostOrderGetHeight(bitree->rChild);
        maxHeight = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
        return maxHeight;
    } else {
        return 0;
    }
}
///广度优先遍历获取树的高度
// 需要一个辅助变量存储当前层的节点数量
int BreathFirstGetHeight(BiTree bitree)
{
    BiNode* BN = bitree;
    queue<BiNode*> myqueue;
    int height = 0;
    int nodesize = 0;
    if (BN) {
        myqueue.push(BN);
        nodesize = myqueue.size();

        while (!myqueue.empty()) {
            while (nodesize > 0) {
                BN = myqueue.front();
                myqueue.pop();
                if (BN->lChild) {
                    myqueue.push(BN->lChild);
                }
                if (BN->rChild) {
                    myqueue.push(BN->rChild);
                }
                nodesize--;
            }
            height++;
            nodesize = myqueue.size();
        }
    }
    return height;
}

int main()
{
    BiTree mytree = createTree("data.txt");

    std::cout << "Recursive Pre-Order Traversal:\n";
    RecursivePreOrderTraversal(mytree);
    std::cout << "\n";
    std::cout << "NonRecursive Pre-Order Traversal:\n";
    NonRecursivePreOrderTraversal(mytree);
    std::cout << "\n";

    std::cout << "Recursive In-Order Traversal:\n";
    RecursiveInOrderTraversal(mytree);
    std::cout << "\n";
    std::cout << "NonRecursive In-Order Traversal:\n";
    NonRecursiveInOrderTraversal(mytree);
    std::cout << "\n";

    std::cout << "Recursive Post-Order Traversal:\n";
    RecursivePostOrderTraversal(mytree);
    std::cout << "\n";
    std::cout << "NonRecursive Post-Order Traversal:\n";
    NonRecursivePostOrderTraversal(mytree);
    std::cout << "\n";

    std::cout << "Breadth First Traversal:\n";
    BreathFirstTraversal(mytree);
    std::cout << "\n";

    std::cout << "Tree Height:\n";
    int height = PostOrderGetHeight(mytree);
    std::cout << "post order height result: " << height << "\n";
    height = BreathFirstGetHeight(mytree);
    std::cout << "breath first height result: " << height << "\n";
    return 1;
}