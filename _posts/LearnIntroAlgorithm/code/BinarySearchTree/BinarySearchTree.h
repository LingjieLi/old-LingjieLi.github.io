#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <string>

typedef struct BiNode {
    int data;
    BiNode* lChild;
    BiNode* rChild;
    BiNode(int _data, BiNode* lc, BiNode* rc)
        : data(_data)
        , lChild(lc)
        , rChild(rc){};
} BiNode, *BiTree;

class BinarySearchTree {
private:
    BiTree root;

public:
    ///构造函数
    BinarySearchTree(BiTree _root)
        : root(_root){};
    /**
    * @brief   从文件构造一棵二叉查找树
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-07 16:31:01
    * @return
    *
    **/
    BinarySearchTree(std::string filename){};
    virtual ~BinarySearchTree(){};

    BiNode* findMin() const {};
    BiNode* findMax() const {};
    BiNode* find(int x) const {};
    bool isEmpty() const;
    
};
#endif
