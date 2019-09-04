/**************************************************************************
*
*   Copyright (C) 2019 by lydia <vera71@126.com>
*
*   All Rights Reserved
*
**************************************************************************/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <cstddef>
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

/**
* @brief 构造一棵二叉搜索树
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-09 17:02:23
* @return
*
**/
class BinarySearchTree {
public:
    ///构造函数
    BinarySearchTree()
        : root(nullptr){};
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
    virtual ~BinarySearchTree()
    {
        makeEmpty();
    };

    BiNode* findMin() const //const函数不修改类的内部状态
    {
        return findMin(root);
    };
    BiNode* findMax() const
    {
        return findMax(root);
    };
    BiNode* find(int x) const
    {
        return find(x, root);
    };
    bool isEmpty() const
    {
        return root == nullptr;
    };

    void makeEmpty()
    {
        makeEmpty(root);
    };
    void insert(int x)
    {
        insert(x, root);
    };
    void remove(int x)
    {
        remove(x, root);
    };
    void removeMin()
    {
        removeMin(root);
    };

    //深拷贝
    //函数返回值的内容不能被修改(引用，即原来的变量不能被修改)
    const BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
        if (this != &rhs) {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    };

protected:
    BiTree root;
    virtual bool insert(int x, BiNode*& t) const
    {
        if (t == nullptr) {
            t = new BiNode(x, nullptr, nullptr);
        } else if (x < t->data) {
            insert(x, t->lChild);
        } else if (x > t->data) {
            insert(x, t->rChild);
        } else {
            std::cerr << "ERROR!!Duplicate Element\n";
            return false;
        }
        return true;
    };
    virtual bool remove(int x, BiNode*& t) const
    {
        if (t == nullptr) {
            std::cout << "This node dost not exist!\n";
            return false;
        } else if (x < t->data) {
            remove(x, t->lChild);
        } else if (x > t->data) {
            remove(x, t->rChild);
        } else if (t->lChild != nullptr && t->rChild != nullptr) {
            //相等且存在左右孩子
            //Step1.找到右孩子的最小节点(比左孩子的所有节点都大，比右孩子所有节点都小，提为新的根节点)
            t->data = findMin(t->rChild)->data;
            //Step2.删除右孩子的最小节点
            removeMin(t->rChild);
            //Step3.do nothing
        } else {
            //左孩子或者右孩子右一个为空,孩子上移一层
            BiNode* oldNode = t;
            t = (t->lChild != nullptr) ? t->lChild : t->rChild;
            delete oldNode;
        }
    };
    virtual bool removeMin(BiNode*& t) const
    {
        if (t == nullptr) {
            std::cerr << "Empty tree!\n";
            return false;
        } else if (t->lChild != nullptr) {
            //有左孩子
            removeMin(t->lChild);
        } else {
            //没有左孩子，最小的就是根节点，删除根节点
            BiNode* tmp = t;
            t = t->rChild;
            delete tmp;
        }
        return false;
    };

    BiNode* findMin(BiNode* t) const
    {
        if (t == nullptr) {
            std::cerr << "Empty tree\n";
        }
        while (t->lChild) {
            t = t->lChild;
        }
        return t;
    };
    BiNode* findMax(BiNode* t) const
    {
        if (t == nullptr) {
            std::cerr << "Empty tree\n";
        }
        while (t->rChild) {
            t = t->rChild;
        }
        return t;
    };
    BiNode* find(int x, BiNode* t) const
    {
        while (t != nullptr) {
            if (x < t->data) {
                t = t->lChild;
            } else if (x > t->data) {
                t = t->rChild;
            } else { //Match
                return t;
            }
        }
        return nullptr;
    };
    void makeEmpty(BiNode*& t) const
    {
        if (t != nullptr) {
            makeEmpty(t->lChild);
            makeEmpty(t->rChild);
        }
        t = nullptr;
    };
    //内部函数
    BiNode* clone(BiNode* t) const
    {
        if (t == nullptr) {
            return nullptr;
        } else {
            return new BiNode(t->data, clone(t->lChild), clone(t->rChild));
        }
    };
};
#endif
