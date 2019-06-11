#include <iostream>

template <typename Type>
struct BiNode {
    Type data;
    BiNode<Type>* lChild = nullptr;
    BiNode<Type>* rChild = nullptr;
    BiNode(Type _data, BiNode* lc = nullptr, BiNode* rc = nullptr)
        : data(_data)
        , lChild(lc)
        , rChild(rc){};
};

/**
* @className BinaryTree
* @brief    二叉树类2.0
*
* @author  lydia <vera71@126.com>
* @date    2019-06-09 20:22:01
*
**/
template <typename Type>
class BinaryTree {
private:
    BiNode<Type>* root;

public:
    BinaryTree()
        : root(nullptr){};
    BinaryTree(Type _data)
        : root(new BiNode<Type>(_data)){};
    ///判断是否为空树
    bool isEmpty() const
    {
        return root == nullptr;
    };
    ///判断一个节点是否是左孩子
    bool isLeftChild(BiNode<Type>* p) const
    {
        return p == getParent(p)->lChild;
    };
    ///判断一个节点是否是右孩子
    bool isRightChild(BiNode<Type>* p) const
    {
        return p == getParent(p)->rChild;
    };
    ///取得树根
    BiNode<Type>* getRoot() const
    {
        return root;
    };
    ///取得一个节点的父节点指针
    BiNode<Type>* getParent(BiNode<Type>* p)
    {
        return parent(root, p);
    };
    ///取得一个节点的左子树根指针
    BiNode<Type>* leftChild(BiNode<Type>* p) const
    {
        return p == nullptr ? nullptr : p->lChild;
    };
    ///取得一个节点的右子树根指针
    BiNode<Type>* rightChild(BiNode<Type>* p) const
    {
        return p == nullptr ? nullptr : p->rChild;
    };
    ///取得一个节点的左兄弟指针
    BiNode<Type>* leftSibling(BiNode<Type>* p) const
    {
        if (p != nullptr) {
            BiNode<Type>* q = parent(root, p);
            if (q != nullptr || p == q->lChild) {
                return nullptr;
            } else {
                return q->rChild;
            }
        }
        return nullptr;
    };
    ///取得一个节点的右兄弟指针
    BiNode<Type>* rightSibling(BiNode<Type>* p) const
    {
        if (p != nullptr) {
            BiNode<Type>* q = parent(root, p);
            if (q != nullptr || p == q->rChild) {
                return nullptr;
            } else {
                return q->rChild;
            }
        }
        return nullptr;
    };
    ///返回一个节点的数据
    Type retrieve(BiNode<Type>* p) const
    {
        if (p == nullptr) {
            std::cerr << "Null pointer!\n";
            return 0;
        }
        return p->data;
    };
    ///设置一个节点的数据
    bool Assign(BiNode<Type>* p, const Type _data)
    {
        if (p == nullptr) {
            std::cout << "Null pointer\n";
            return false;
        } else {
            p->data = _data;
        }
    }
    ///插入左孩子到当前节点下
    bool insertLeftChild(BiNode<Type>* p, const Type _data)
    {
        BiNode<Type>* temp = new BiNode<Type>(_data);
        temp->lChild = p->lChild;
        p->lChild = temp;
    };
    ///插入右孩子到当前节点下
    bool insertRightChild(BiNode<Type>* p, const Type& _data)
    {
        BiNode<Type>* temp = new BiNode<Type>(_data);
        temp->rChild = p->rChild;
        p->rChild = temp;
    };
    ///删除当前节点的右孩子
    bool deleteLeftChild(BiNode<Type>* p)
    {
        Destroy(p->rChild);
    };
    ///删除当前节点的左孩子
    bool deleteRightChild(BiNode<Type>* p)
    {
        Destroy(p->lChild);
    };
    ///先序遍历
    virtual void PreOrderTraverse(BiNode<Type>* root) const {};
    ///中序遍历
    virtual void InOrderTraverse(BiNode<Type>* root) const {};
    ///后序遍历
    virtual void PostOrderTraverse(BiNode<Type>* root) const {};
    ///层次遍历
    virtual void LevelOrderTraverse(BiNode<Type>* root) const {};
    ///返回节点的父亲指针
    BiNode<Type>* parent(BiNode<Type>* root, BiNode<Type>* p) const {};
    ///清除树
    void Destroy(BiNode<Type>* root)
    {
        if (root != nullptr) {
            Destroy(root->lChild);
            Destroy(root->rChild);
            delete root;
        }
    };

    ~BinaryTree()
    {
        Destroy(root);
        root = nullptr;
    };
};
