#include <iostream>
using namespace std;

template<class T>
class BinaryTreeNode
{
    // friend class BinaryTree<T>;
    private:
        T element;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;
    public:
        BinaryTreeNode()
        {
            element = NULL;
            left = NULL;
            right = NULL;
        }
        BinaryTreeNode(const T& ele)
        {
            element = ele;
            left = NULL;
            right = NULL;
        }
        BinaryTreeNode(const T& ele, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right)
        {
            element = ele;
            this.left = left;
            this.right = right;
        }
        T value() const
        {
            return element;
        }
        BinaryTreeNode<T>* leftchild() const
        {
            return left;
        }
        BinaryTreeNode<T>* rightchild() const
        {
            return right;
        }
        void setLeftchild(BinaryTreeNode<T>*  left)
        {
            this->left = left;
        }
        void setRightchild(BinaryTreeNode<T>* right)
        {
            this->right = right;
        }
        void setValue(const T& val)
        {
            element = val;
        }
        bool isLeaf() const
        {
            if (left == NULL && right == NULL)
                return true;
            else
                return false;
        }
        BinaryTreeNode<T>& operator = (const BinaryTreeNode<T> & Node)
        {
            BinaryTreeNode* node=new BinaryTreeNode(); // to be confirm
            node.setLeftchild(Node.leftchild());
            node.setRightchild(Node.rightchild());
            node.setValue(Node.value());
            return node;
        }
};

int main()
{
    BinaryTreeNode<char>* node1;
    BinaryTreeNode<char>* node2;
    BinaryTreeNode<char>* node3;
    // node1->setValue('a');
    // node2->setValue('b');
    // node3->setValue('c');
    node1->setLeftchild(node2);
    node1->setRightchild(node3);
    cout << node1->value() << endl;
    cout << "shabi" << endl;
    cout << node1->leftchild()->value() << endl;
    cout << node1->rightchild()->value() << endl;
    return 0; 
}

template<class T>
class BinaryTree
{
    private:                                
        BinaryTreeNode<T>* root;
        BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root, BinaryTreeNode<T>* current);
    public:
        BinaryTree(BinaryTreeNode<T>* root=NULL);
        ~BinaryTree() {deleteBinaryTree(root);};
        bool isEmpty() const;
        BinaryTreeNode<T>* getRoot() {return root;};
        BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* current);
        BinaryTreeNode<T>* leftSibling(BinaryTreeNode<T>* current);
        BinaryTreeNode<T>* rightSibling(BinaryTreeNode<T>* current);
        void preOrder(BinaryTreeNode<T>* root);
        void inOrder(BinaryTreeNode<T>* root);
        void postOrder(BinaryTreeNode<T>* root);
        void levelOrder(BinaryTreeNode<T>* root);
        void deleteBinaryTree(BinaryTreeNode<T>* root);     
};



