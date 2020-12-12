#ifndef _TREE_NODE_
#define _TREE_NODE_
#include <memory.h>

template <class T>
class TreeNode
{
private:
    T value;
    TreeNode<T> *father;
    TreeNode<T> *left;
    TreeNode<T> *right;
    int height;

public:
    explicit TreeNode(const T &value);

    TreeNode(T &value, TreeNode<T> *father, TreeNode<T> *left, TreeNode<T> *right, int height);

    ~TreeNode();

    T *getValue();

    void setValue(T *new_value);

    TreeNode<T> *getFather() const;

    void setFather(TreeNode *new_father);

    TreeNode<T> *getLeft() const;

    void setLeft(TreeNode *new_left);

    TreeNode<T> *getRight() const;

    void setRight(TreeNode *new_right);

    const int getHeight() const;

    void setHeight(int new_height);
};

template <class T>
TreeNode<T>::TreeNode(T &value, TreeNode<T> *father, TreeNode<T> *left, TreeNode<T> *right, int height) : value(value), father(father), left(left), right(right), height(height) {}

template <class T>
TreeNode<T>::TreeNode(const T &value)
    : value(value), father(nullptr), left(nullptr), right(nullptr), height(0) {}

template <class T>
TreeNode<T>::~TreeNode()
{
}

template <class T>
T *TreeNode<T>::getValue()
{
    return &value;
}

template <class T>
void TreeNode<T>::setValue(T *new_value)
{
    value = *new_value;
}

template <class T>
TreeNode<T> *TreeNode<T>::getFather() const
{
    return father;
}

template <class T>
void TreeNode<T>::setFather(TreeNode *new_father)
{
    father = new_father;
}

template <class T>
TreeNode<T> *TreeNode<T>::getLeft() const
{
    return left;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode *new_left)
{
    left = new_left;
}

template <class T>
TreeNode<T> *TreeNode<T>::getRight() const
{
    return right;
}

template <class T>
void TreeNode<T>::setRight(TreeNode *new_right)
{
    right = new_right;
}

template <class T>
const int TreeNode<T>::getHeight() const
{
    return height;
}

template <class T>
void TreeNode<T>::setHeight(int new_height)
{
    height = new_height;
}

#endif
