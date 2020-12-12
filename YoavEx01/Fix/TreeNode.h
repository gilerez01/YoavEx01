#ifndef _TREE_NODE_
#define _TREE_NODE_
#include <memory.h>

/**
* TreeNode class
*
* The following methods are available:
*   constructor         - Creates new TreeNode with the given parameters.
*   another constructor - Creates a new T value TreeNode.
*   getValue            - Return pointer to the value of the TreeNode.
*   setValue            - Change the value of the TreeNode to the given value.
*   getFather           - Return pointer to the father TreeNode.
*   setFather           - Change this TreeNode's father to another TreeNode.
*   getLeft             - Return pointer to this TreeNode left son.
*   setLeft             - Change this TreeNode's left son to another TreeNode.
*   getRight            - Return pointer to this TreeNode right son.
*   setRight            - Change this TreeNode's right son to another TreeNode.
*   getHeight           - Return the Height ot this TreeNode.
*   setHeight           - Change this TreeNode's height to a given height.                  
*/



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
    
    /**
     * copy constructor: Create a new TreeNode with the initialization of the given T value
     *                   and null to all the TreeNode pointers and initialize the height to zero.
     * @param
     *  T value
     * 
     * @return
     *  A new TreeNode with T value, height zero and pointers to null.
     */
    explicit TreeNode(const T &value);

    /**
    * constructor: Create a new TreeNode with the given parameters. 
    * @param
    *   T value, TreeNode pointers: father,left,right and int height.
    * 
    * @return
    * 	A new initalized TreeNode.
    */
    TreeNode(T &value, TreeNode<T> *father, TreeNode<T> *left, TreeNode<T> *right, int height);
    
    /**
    * destructor: Deallocate all the memory.
    * 
    * @Assumptions
    *  T has a destructor.
    */
    ~TreeNode();

    /**
     * getValue: Return a pointer to this TreeNode's value. 
     */
    T *getValue();

    /**
     * setValue: Set the given T value to this TreeNode's value. 
     * 
     * @param 
     *  A pointer the the new T value.
     */
    void setValue(T *new_value);

    /**
     * getFather: Return a pointer to this TreeNode's father. 
     */
    TreeNode<T> *getFather() const;

    /**
     * setFather: Set this TreeNode's father to the given father. 
     * 
     * @param 
     *  A pointer the the new father.
     */
    void setFather(TreeNode *new_father);

    /**
     * getLeft: Return a pointer to this TreeNode's left son. 
     */
    TreeNode<T> *getLeft() const;

    /**
     * setLeft: Set this TreeNode's left son to the given left son. 
     * 
     * @param 
     *  A pointer the the new left son.
     */
    void setLeft(TreeNode *new_left);

    /**
     * getRight: Return a pointer to this TreeNode's right son. 
     */
    TreeNode<T> *getRight() const;

    /**
     * setRight: Set this TreeNode's right son to the given right son. 
     * 
     * @param 
     *  A pointer the the new right son.
     */
    void setRight(TreeNode *new_right);

    /**
     * getHeight: Return the Height of this TreeNode.
     */
    const int getHeight() const;

    /**
     * setHeight: Set the Height of this TreeNode to a given height.
     * 
     * @param
     *  The new height.
     */
    void setHeight(int new_height);
};
//////////////////////////////////////////////////////////
// The Implementation
/////////////////////////////////////////////////////////


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
