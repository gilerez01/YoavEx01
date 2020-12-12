#ifndef _AVL_TREE_
#define _AVL_TREE_
#include "TreeNode.h"
#include "NodeAlreadyExistsException.h"
#include "library.h"
#include "NodeDoesntExistsException.h"
#include <iostream>

/**
* AVL_Tree class
*
* The following methods are available:
*   constructor         - Creates new empty AVL_Tree.
*   find                - Find a TreeNode in the Tree.
*   insert              - Insert new TreeNode to the Tree.
*   remove              - Remove a requested TreeNode from the Tree.
*   getRoot             - Return the root of the Tree.
*   getRightMostVertex  - Return a pointer to the rightest TreeNode.
*   getLeftMostVertex   - Return a pointer to the leftestest TreeNode.
*   inOrder             - Print the Trees values in order.
*   deleteTree          - Deallocate all the allocated memory in the Tree.
*/

template <class T>
class AVL_Tree
{
private:
    TreeNode<T> *root;
    TreeNode<T> *rightMostLeaf;
    TreeNode<T> *leftMostLeaf;
    ///////////////////////////////////////////////////////////////
    // Auxiliary functions
    ///////////////////////////////////////////////////////////////
    
    /**
     * isLeaf: Check if the given vertex is a leaf.
     * 
     * @param
     *  TreeNode vertex.
     * 
     * @return
     *  True if vertex is a leaf.
     *  Otherwise false.
     */
    static bool isLeaf(const TreeNode<T> &vertex);
    
    /**
     * height: Calculate the height of the given vertex and return it.
     * 
     * @param
     *  TreeNode vertex.
     * 
     * @return
     *  The height of the vertex.
     */
    static int height(const TreeNode<T> *vertex);
    
    /**
     * BF : Calculate and return the given vertex balance factor.
     * 
     * @param
     *  TreeNode vertex.
     * 
     * @return
     *  The balance factor of the vertex. 
     */
    static int BF(const TreeNode<T> *vertex);
    
    /**
     * setSonAndFather: set vertex 2 as the son of vertex 1 and set the father of vertex 2 to be vertex 1.
     * 
     * @param
     *  vertex 1, vertex 2 and bool left son. 
     */
    static void setSonAndFather(TreeNode<T> *vertex1, TreeNode<T> *vertex2, bool left_son);
    
    /**
     * swap: swap vertex 1 with vertex 2
     * 
     * @param
     *  vertex 1, vertex 2.
     * 
     * @return
     *   vertex 2.
     */
    TreeNode<T> *swap(TreeNode<T> &vertex1, TreeNode<T> &vertex2);
    
    /**
     * swapAux1: just an auxiliary to the above swap
     */
    TreeNode<T> *swapAux1(TreeNode<T> &vertex1, TreeNode<T> &vertex2);
    
    /**
     * swapAux1: just an auxiliary to the above swap
     */
    TreeNode<T> *swapAux2(TreeNode<T> &vertex1, TreeNode<T> &vertex2);
    
    /**
     * LL_Roll: Do LL roll on the given vertex.
     * 
     * @param
     *  vertex
     * 
     * @return
     *  The new "root" of the sub Tree vertex.
     */
    TreeNode<T> *LL_Roll(TreeNode<T> *vertex);
    
    /**
     * LR_Roll: Do LR roll on the given vertex.
     * 
     * @param
     *  vertex
     * 
     * @return
     *  The new "root" of the sub Tree vertex.
     */
    TreeNode<T> *LR_Roll(TreeNode<T> *vertex);
    
    /**
     * RR_Roll: Do RR roll on the given vertex.
     * 
     * @param
     *  vertex
     * 
     * @return
     *  The new "root" of the sub Tree vertex.
     */
    TreeNode<T> *RR_Roll(TreeNode<T> *vertex);
    
    /**
     * RL_Roll: Do RL roll on the given vertex.
     * 
     * @param
     *  vertex
     * 
     * @return
     *  The new "root" of the sub Tree vertex.
     */
    TreeNode<T> *RL_Roll(TreeNode<T> *vertex);
    
    /**
     * step1Remove: auxiliary function for remove. Deals with the situation
     *              that the wanted vertex has less then two sons. 
     */
    TreeNode<T> *step1Remove(TreeNode<T> &wanted_vertex);
    
    /**
     * step1RemoveAux: auxiliary function for step1Remove.
     */
    static void step1RemoveAux(TreeNode<T> *left_son, TreeNode<T>* right_son, TreeNode<T>* father
                    , bool is_left_son_of_wanted, bool is_left_son_of_father);

    /**
     * step2Remove: auxiliary function for remove. Deals with the situation
     *              that the wanted vertex has two sons. 
     */
    TreeNode<T>* step2Remove(TreeNode<T> &wanted_vertex);
    
    /**
     * inOrder: Auxiliary function to inOrder().
     */
    void inOrder(TreeNode<T> *_root);
    
    /**
     * setRightMostVertex: Updates the rightest vertex.
     */
    void setRightMostVertex();
    
    /**
     * setLeftMostVertex: Updates the leftest vertex.
     */
    void setLeftMostVertex();

    void balancingAfterInsert(TreeNode<T> * vertex);

public:
    
    /**
     * constructor: Create new empty Tree.
     */
    AVL_Tree();
    
    ~AVL_Tree();

    /**
     * find: Find a TreeNode in the Tree.
     * 
     * @param
     *  T object
     * 
     * @Assumptions
     *  T has operator< and operator>.
     * 
     * @return
     *  A pointer to the TreeNode that contains the value object.
     *  If there are no such TreeNode returns null.
     */
    TreeNode<T> *find(const T &object) const;
    
    /**
     * insert: Insert new TreeNode to the Tree.
     * 
     * @param
     *  T object
     * 
     * @Assumptions
     *  T has operator< and operator>.
     * 
     */
    void insert(const T &object);
    
    /**
     * remove: Remove a requested TreeNode from the Tree.
     * 
     * @param
     *  T object.
     * 
     * @Assumptions
     *  T has operator< and operator>.
     */
    void remove(const T &object);
    
    /**
     * getRoot: Return the root of the Tree.
     */
    TreeNode<T> *getRoot() const;
    
    /**
     * getRightMostVertex: Return a pointer to the rightest TreeNode.
     */
    TreeNode<T> *getRightMostVertex() const;
    
    /**
     * getLeftMostVertex: Return a pointer to the leftest TreeNode.
     */
    TreeNode<T> *getLeftMostVertex() const;
    
    /**
     * inOrder: Print the Trees values in order. 
     * 
     * @Assumptions
     *  T has operator< and operator>.
     */
    void inOrder();
    
    /**
     * deleteTree: Deallocate all the allocated memory in the Tree.
     * 
     * @param
     *  The Tree root.
     */
    void deleteTree(TreeNode<T> *root);
};


////////////////////////////////////////
// The implementation
////////////////////////////////////////
template <class T>
AVL_Tree<T>::AVL_Tree() : root(NULL), rightMostLeaf(NULL), leftMostLeaf(NULL) {}

template <class T>
AVL_Tree<T>::~AVL_Tree()
{
    deleteTree(root);
}

template <class T>
void AVL_Tree<T>::deleteTree(TreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }
    TreeNode<T> *temp = root->getFather();
    deleteTree(root->getLeft());
    deleteTree(root->getRight());
    if(temp == NULL){
        delete root;
        this->root = NULL;
        this->leftMostLeaf = NULL;
        this->rightMostLeaf = NULL;
        return;
    }
    bool is_left_son = (temp->getLeft() == root);
    delete root;
    if(is_left_son){
    temp->setLeft(NULL);
    } else{
    temp->setRight(NULL);
    }
}

template <class T>
TreeNode<T> *AVL_Tree<T>::getRoot() const
{
    return root;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::getRightMostVertex() const
{
    return rightMostLeaf;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::getLeftMostVertex() const
{
    return leftMostLeaf;
}

template <class T>
bool AVL_Tree<T>::isLeaf(const TreeNode<T> &vertex)
{
    return (vertex.getLeft() == NULL && vertex.getRight() == NULL);
}

template <class T>
int AVL_Tree<T>::height(const TreeNode<T> *vertex)
{
    if (vertex == NULL)
    {
        return -1;
    }
    if (isLeaf(*vertex))
    {
        return 0;
    }
    if (vertex->getLeft() == NULL)
    {
        return vertex->getRight()->getHeight() + 1;
    }
    else if (vertex->getRight() == NULL)
    {
        return vertex->getLeft()->getHeight() + 1;
    }
    else
    {
        int h1 = vertex->getRight()->getHeight(), h2 = vertex->getLeft()->getHeight();
        if (h1 > h2)
        {
            return h1 + 1;
        }
        else
        {
            return h2 + 1;
        }
    }
}

template <class T>
TreeNode<T> *AVL_Tree<T>::step1Remove(TreeNode<T> &wanted_vertex)
{
    if (wanted_vertex.getValue() == root->getValue())
    {
        if (isLeaf(wanted_vertex))
        {
            root = NULL;
            rightMostLeaf = NULL;
            leftMostLeaf = NULL;
        }
        else
        {
            if (wanted_vertex.getLeft() != NULL)
            {
                root = wanted_vertex.getLeft();
            }
            else
            {
                root = wanted_vertex.getRight();
            }
            root->setFather(NULL);
        }
        delete &wanted_vertex;
        return NULL;
    }
    TreeNode<T> *father = wanted_vertex.getFather();
    TreeNode<T> *left_son = wanted_vertex.getLeft();
    TreeNode<T> *right_son = wanted_vertex.getRight();
    bool is_left_son_of_father = (father->getLeft() == &wanted_vertex);
    bool is_left_son_of_wanted = (wanted_vertex.getLeft() != NULL);
    step1RemoveAux(left_son,right_son,father,is_left_son_of_wanted,is_left_son_of_father);
    delete &wanted_vertex;
    return father;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::step2Remove(TreeNode<T> &wanted_vertex)
{
    TreeNode<T> *temp = wanted_vertex.getRight();
    TreeNode<T> *temp_father = temp->getFather();
    while (temp != NULL)
    {
        temp_father = temp;
        temp = temp->getLeft();
    }
    return swap(*temp_father, wanted_vertex);
}

template <class T>
void AVL_Tree<T>::remove(const T &object)
{
    TreeNode<T> *wanted_vertex = this->find(object);
    if (wanted_vertex == NULL) {
        throw NodeDoesntExistsException();
    }
    // v has two sons
    if (wanted_vertex->getLeft() != NULL && wanted_vertex->getRight() != NULL)
    {
        wanted_vertex = step2Remove(*wanted_vertex);
    }
    // v doesn't have two sons
    TreeNode<T> *vertex = step1Remove(*wanted_vertex);
    // balancing the tree
    while (vertex != NULL)
    {
        vertex->setHeight(height(vertex));
        int bf = BF(vertex);
        if (bf == 2)
        {
            if (BF(vertex->getLeft()) >= 0)
            {
                vertex = LL_Roll(vertex);
            }
            else
            {
                vertex = LR_Roll(vertex);
            }
        }
        else if (bf == -2)
        {
            if (BF(vertex->getRight()) <= 0)
            {
                vertex = RR_Roll(vertex);
            }
            else
            {
                vertex = RL_Roll(vertex);
            }
        }
        vertex = vertex->getFather();
    }
    setRightMostVertex();
    setLeftMostVertex();
}

template <class T>
void AVL_Tree<T>::step1RemoveAux(TreeNode<T> *left_son, TreeNode<T>* right_son, TreeNode<T>* father
                    , bool is_left_son_of_wanted, bool is_left_son_of_father){
    if(is_left_son_of_wanted){
        if(is_left_son_of_father){
            father->setLeft(left_son);
        } else{
            father->setRight(left_son);
        }
        if (left_son != NULL){
            left_son->setFather(father);
        }
    } else{
        if(is_left_son_of_father){
            father->setLeft(right_son);
        } else{
            father->setRight(right_son);
        }
        if (right_son != NULL){
            right_son->setFather(father);
        }
    }
}

template <class T>
int AVL_Tree<T>::BF(const TreeNode<T> *vertex)
{
    TreeNode<T> *left = vertex->getLeft(), *right = vertex->getRight();
    return height(left) - height(right);
}

template <class T>
TreeNode<T> *AVL_Tree<T>::LL_Roll(TreeNode<T> *vertex)
{
    TreeNode<T> *A = vertex->getLeft();
    TreeNode<T> *AR = vertex->getLeft()->getRight();
    vertex->setLeft(AR);
    if (AR != NULL)
    {
        AR->setFather(vertex);
    }
    A->setRight(vertex);
    A->setFather(vertex->getFather());
    if (A->getFather() == NULL)
    {
        root = A;
    }
    vertex->setFather(A);
    if (A != root)
    {
        bool is_left = (A->getFather()->getLeft() == vertex);
        if (is_left)
        {
            A->getFather()->setLeft(A);
        }
        else
        {
            A->getFather()->setRight(A);
        }
    }
    vertex->setHeight(height(vertex));
    A->setHeight(height(A));
    return A;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::LR_Roll(TreeNode<T> *vertex)
{
    TreeNode<T> *A = vertex->getLeft();
    TreeNode<T> *B = A->getRight();
    TreeNode<T> *BL = B->getLeft();
    TreeNode<T> *BR = B->getRight();
    A->setRight(BL);
    if (BL != NULL)
    {
        BL->setFather(A);
    }
    vertex->setLeft(BR);
    if (BR != NULL)
    {
        BR->setFather(vertex);
    }
    B->setFather(vertex->getFather());
    if (B->getFather() == NULL)
    {
        this->root = B;
    }
    B->setLeft(A);
    A->setFather(B);
    B->setRight(vertex);
    vertex->setFather(B);
    if (B != root)
    {
        bool is_left = (B->getFather()->getLeft() == vertex);
        if (is_left)
        {
            B->getFather()->setLeft(B);
        }
        else
        {
            B->getFather()->setRight(B);
        }
    }
    vertex->setHeight(height(vertex));
    A->setHeight(height(A));
    B->setHeight(height(B));
    return B;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::RR_Roll(TreeNode<T> *vertex)
{
    TreeNode<T> *A = vertex->getRight();
    TreeNode<T> *AL = vertex->getRight()->getLeft();
    vertex->setRight(AL);
    if (AL != NULL)
    {
        AL->setFather(vertex);
    }
    A->setLeft(vertex);
    A->setFather(vertex->getFather());
    if (A->getFather() == NULL)
    {
        root = A;
    }
    vertex->setFather(A);
    if (A != root)
    {
        bool is_left = (A->getFather()->getLeft() == vertex);
        if (is_left)
        {
            A->getFather()->setLeft(A);
        }
        else
        {
            A->getFather()->setRight(A);
        }
    }
    vertex->setHeight(height(vertex));
    A->setHeight(height(A));
    return A;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::RL_Roll(TreeNode<T> *vertex)
{
    TreeNode<T> *A = vertex->getRight();
    TreeNode<T> *B = A->getLeft();
    TreeNode<T> *BL = B->getLeft();
    TreeNode<T> *BR = B->getRight();
    A->setLeft(BR);
    if (BR != NULL)
    {
        BR->setFather(A);
    }
    vertex->setRight(BL);
    if (BL != NULL)
    {
        BL->setFather(vertex);
    }
    B->setFather(vertex->getFather());
    if (B->getFather() == NULL)
    {
        root = B;
    }
    B->setLeft(vertex);
    vertex->setFather(B);
    B->setRight(A);
    A->setFather(B);
    if (B != root)
    {
        bool is_left = (B->getFather()->getLeft() == vertex);
        if (is_left)
        {
            B->getFather()->setLeft(B);
        }
        else
        {
            B->getFather()->setRight(B);
        }
    }
    vertex->setHeight(height(vertex));
    A->setHeight(height(A));
    B->setHeight(height(B));
    return B;
}

template <class T>
void AVL_Tree<T>::setRightMostVertex()
{
    TreeNode<T> *pos = root;
    if (pos == NULL)
    {
        rightMostLeaf = NULL;
    }
    else
    {
        while (pos->getRight() != NULL)
        {
            pos = pos->getRight();
        }
        rightMostLeaf = pos;
    }
}

template <class T>
void AVL_Tree<T>::setLeftMostVertex()
{
    TreeNode<T> *pos = root;
    if (pos == NULL)
    {
        leftMostLeaf = NULL;
    }
    else
    {
        while (pos->getLeft() != NULL)
        {
            pos = pos->getLeft();
        }
        leftMostLeaf = pos;
    }
}

template <class T>
void AVL_Tree<T>::insert(const T &object)
{
    TreeNode<T> *temp, *father;
    temp = this->find(object);
    if(temp != NULL){
        throw NodeAlreadyExistsException();
    }
    temp = root;
    TreeNode<T> *new_node = new TreeNode<T>(object);
    if (temp == NULL)
    {
        root = new_node;
        rightMostLeaf = new_node;
        leftMostLeaf = new_node;
    }
    else
    {
        father = temp->getFather();
        while (temp != NULL)
        {
            if (object < *(temp->getValue()))
            {
                father = temp;
                temp = temp->getLeft();
            }
            else if (object > *(temp->getValue()))
            {
                father = temp;
                temp = temp->getRight();
            }
        }
        if (object < *(father->getValue()))
        {
            father->setLeft(new_node);
        }
        else if (object > *(father->getValue()))
        {
            father->setRight(new_node);
        }
        new_node->setFather(father);
        /*
        while (father != NULL)
        {
            father->setHeight(height(father));
            int bf = BF(father);
            if (bf == 2)
            {
                if (BF(father->getLeft()) >= 0)
                {
                    father = LL_Roll(father);
                }
                else
                {
                    father = LR_Roll(father);
                }
            }
            else if (bf == -2)
            {
                if (BF(father->getRight()) <= 0)
                {
                    father = RR_Roll(father);
                }
                else
                {
                    father = RL_Roll(father);
                }
            }
            father = father->getFather();
        }*/
        balancingAfterInsert(father);
        setRightMostVertex();
        setLeftMostVertex();
    }
}

template <class T>
void AVL_Tree<T>::balancingAfterInsert(TreeNode<T> * vertex){
    while (vertex != NULL)
    {
        vertex->setHeight(height(vertex));
        int bf = BF(vertex);
        if (bf == 2)
        {
            if (BF(vertex->getLeft()) >= 0)
            {
                vertex = LL_Roll(vertex);
            }
            else
            {
                vertex = LR_Roll(vertex);
            }
        }
        else if (bf == -2)
        {
            if (BF(vertex->getRight()) <= 0)
            {
                vertex = RR_Roll(vertex);
            }
            else
            {
                vertex = RL_Roll(vertex);
            }
        }
        vertex = vertex->getFather();
    }
}

template <class T>
TreeNode<T> *AVL_Tree<T>::find(const T &object) const
{
    TreeNode<T> *temp = root;
    while (temp != NULL)
    {
        if (object < *(temp->getValue()))
        {
            temp = temp->getLeft();
        }
        else if (object > *(temp->getValue()))
        {
            temp = temp->getRight();
        }
        else
        {
            return temp;
        }
    }
    return NULL;
}

template <class T>
void AVL_Tree<T>::inOrder()
{
    inOrder(this->root);
}

template <class T>
void AVL_Tree<T>::inOrder(TreeNode<T> *_root)
{
    if (_root == NULL)
        return;
    inOrder(_root->getLeft());
    std::cout << *(_root->getValue()) << " ";
    inOrder(_root->getRight());
}

template <class T>
TreeNode<T> *AVL_Tree<T>::swap(TreeNode<T> &vertex1, TreeNode<T> &vertex2)
{
    if (vertex2.getRight() == &vertex1)
    {
        return swapAux1(vertex1, vertex2);
    }
    else
    {
        return swapAux2(vertex1, vertex2);
    }
}

template <class T>
TreeNode<T> *AVL_Tree<T>::swapAux1(TreeNode<T> &vertex1, TreeNode<T> &vertex2)
{
    TreeNode<T> *left1, *right1;
    left1 = vertex1.getLeft();
    right1 = vertex1.getRight();
    setSonAndFather(&vertex1, &vertex2, true);
    vertex1.setFather(vertex2.getFather());
    if (vertex1.getFather() == NULL)
    {
        root = &vertex1;
    }
    else
    {
        if (vertex1.getFather()->getRight()->getValue() == vertex2.getValue())
        {
            vertex1.getFather()->setRight(&vertex1);
        }
        else
        {
            vertex1.getFather()->setLeft(&vertex1);
        }
    }
    vertex2.setLeft(left1);
    if (left1 != NULL)
    {
        left1->setFather(&vertex2);
    }
    vertex2.setRight(right1);
    if (right1 != NULL)
    {
        right1->setFather(&vertex2);
    }
    vertex2.setFather(&vertex1);
    vertex1.setRight(&vertex2);
    return &vertex2;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::swapAux2(TreeNode<T> &vertex1, TreeNode<T> &vertex2)
{
    TreeNode<T> *left1, *right1, *father1;
    left1 = vertex1.getLeft();
    right1 = vertex1.getRight();
    father1 = vertex1.getFather();
    setSonAndFather(&vertex1, &vertex2, true);
    setSonAndFather(&vertex1, &vertex2, false);
    vertex1.setFather(vertex2.getFather());
    if (vertex1.getFather() == NULL)
    {
        root = &vertex1;
    }
    else
    {
        if (vertex1.getFather()->getRight()->getValue() == vertex2.getValue())
        {
            vertex1.getFather()->setRight(&vertex1);
        }
        else
        {
            vertex1.getFather()->setLeft(&vertex1);
        }
    }
    vertex2.setLeft(left1);
    if (left1 != NULL)
    {
        left1->setFather(&vertex2);
    }
    vertex2.setRight(right1);
    if (right1 != NULL)
    {
        right1->setFather(&vertex2);
    }
    vertex2.setFather(father1);
    if (father1 != NULL)
    {
        bool is_left = (father1->getLeft() == &vertex1);
        if (is_left)
        {
            vertex2.getFather()->setLeft(&vertex2);
        }
        else
        {
            vertex2.getFather()->setRight(&vertex2);
        }
    }
    return &vertex2;
}

template <class T>
void AVL_Tree<T>::setSonAndFather(TreeNode<T> *vertex1, TreeNode<T> *vertex2, bool left_son)
{
    if (left_son)
    {
        vertex1->setLeft(vertex2->getLeft());
        if (vertex1->getLeft() != NULL)
        {
            vertex1->getLeft()->setFather(vertex1);
        }
    }
    else
    {
        vertex1->setRight(vertex2->getRight());
        if (vertex1->getRight() != NULL)
        {
            vertex1->getRight()->setFather(vertex1);
        }
    }
}

#endif
