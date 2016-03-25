/*
    oniel toledo
    assignment 04
    cs 302 section 1001

    the following file is the header file for the template based
    class binaryTree (used as an expression tree).
    Since this is an expression tree, find, findMax, findMin, remove, insert
    and makeEmpty functions are not needed and thus their corresponding class
    declarations and functions have been commented out.
    functions that are used:
        constructor             -initialize root
        destructor              -free object memory space
        isEmpty                 -bool operation
        printTree               -call inorderPrint()
        inorderPrint            -add parenthesis and print the tree
        makeLeaf(1 parameter)   -create node for an operand
        makeLeaf(3 parameters)  -create node for an operator
*/

//header gaurds
#ifndef HTREE
#define HTREE

#include <iostream>
#include "linkedStack.h"
using namespace std;

//list node ***********************************************
//thee stackNode's toBinaryNode points to a binaryNode
template <class type>
struct binaryNode{
    type element;
    binaryNode<type> *left;
    binaryNode<type> *right;
    };

template < class type>
class binaryTree {
    public:
        //constructor/destructor(s)
        binaryTree();
        ~binaryTree();
        //user accessibly functions
//        const type find(const type &x) const;
//        const type findMax(const type &x) const;
//        const type findMin(const type &x) const;
        bool isEmpty() const;
        void printTree() const;
//        void makeEmpty();
//        void insert(const type &x);
//        void remove(const type &x);
        binaryNode<type>* makeLeaf(const type x);
        binaryNode<type>* makeLeaf(const type x, binaryNode<type> *right, binaryNode<type> *left);
    private:
        binaryNode<type> *root;
        //private functions
        const type &elementAt(binaryNode<type> *t) const;
        void inorderPrint(binaryNode<type> *nodeRoot) const;
//        void insert(const type &x, binaryNode<type> *&t);
//        void remove(const type &x, binaryNode<type> *&t);
//        binaryNode<type>* find(const type &x, binaryNode<type> *t) const;
//        binaryNode<type>* findMax(const type &x, binaryNode<type> *&t);
//        binaryNode<type>* findMax(const type &x, binaryNode<type> *&t);
    };

//Constructors***************************************
template <class type>
binaryTree<type>::binaryTree(){
    root = NULL;
    }

template <class type>
binaryTree<type>::~binaryTree(){
    //makeEmpty();
    }



//misc functions****************************************
template <class type>
bool binaryTree<type>::isEmpty() const{
    return (root == NULL);
    }

//create a single leaf node (for operands)
template <class type>
binaryNode<type>* binaryTree<type>::makeLeaf(const type x){
    binaryNode<type> *newNode = new binaryNode<type>;
    newNode->element = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
    }

//create a single leaf node with 2 children which are operands (for operators)
template <class type>
binaryNode<type>* binaryTree<type>::makeLeaf(const type x,binaryNode<type> *right, binaryNode<type> *left){
    binaryNode<type> *newNode = new binaryNode<type>;
    newNode->element = x;       //push the operator to  element
    newNode->right = right;     //move the first popped in stack to the right
    newNode->left = left;       //move the second popped in stack to the left
    root = newNode;             //point the address of newNode to the root
    return newNode;
    }


//print the tree in inorder format
template <class type>
void binaryTree<type>::printTree() const{
    inorderPrint(root);
    }

//print the tree in inorder traversal (with parenthesis)
//will recursively print from: right subtree, root, left subtree
template <class type>
void binaryTree<type>::inorderPrint(binaryNode<type> *nodeRoot) const {
    if(nodeRoot != NULL){
        //if operator then output ( before outputting the operand
        if(nodeRoot->element == '+' || nodeRoot->element == '-' || nodeRoot->element == '*' || nodeRoot->element == '/')
            cout << "(";
        inorderPrint(nodeRoot->right);      //will recurse until
        cout << nodeRoot->element;
        inorderPrint(nodeRoot->left);
        //if operand then output ) after outputting the operand
        if(nodeRoot->element == '+' || nodeRoot->element == '-' || nodeRoot->element == '*' || nodeRoot->element == '/')
            cout << ")";
        }
    }

//find item x in the tree
//template <class type>
//const type binaryTree<type>::find(const type &x) const{
//    return elementAt(find(x, root));
//    }
//
////find item x in the tree
//template <class type>
//const type binaryTree<type>::findMin(const type &x) const{
//    return elementAt(findMin(x, root));
//    }
//
////find item x in the treParenthesese
//template <class type>
//const type binaryTree<type>::findMax(const type &x) const{
//    return elementAt(findMax(x, root));
//    }
//
//template <class type>
// void binaryTree<type>::insert(const type &x){
//    elementAt(insert(x,root));
//    }
//template <class type>
// void binaryTree<type>::remove(const type &x){
//    elementAt(remove(x, root));
//    }
//internal functions*************************************************
//elementAt function
//template <class type>
//const type &binaryTree<tree>::elementAt(binaryNode<type> *t) const{
//    if(t==NULL)
//        cout << "ITEM-NOT-FOUND" << endl;
//        return;
//    else return (t->element);
//    }
//
//template <class type>
//binaryNode<type>* binaryTree<type>::find(const type &x, binaryNode<type> *t) const{
//    if(t==NULL) return NULL;
//    else if(x < t->element) return find(x, t->left);
//    else if(x > t->element) return find(x, t->right);
//    else return t;
//    }
//
//template <class type>
//binaryNode<type>* binaryTree<type>::findMin(const type &x, binaryNode<type> *&t) const{
//    if(t==NULL) return NULL;
//    if(t->left==NULL) return t;
//    return findMin(t->left);
//    }
//
//template <class type>
//binaryNode<type>* binaryTree<type>::findMax(const type &x, binaryNode<type> *&t) const{
//    if(t==NULL) return NULL;
//    if(t->right==NULL) return t;
//    return findMax(t->right);
//    }
//
//template <class type>
//void binaryTree<type>::insert(const type &x, binaryNode<type> *&t){
//    if(t==NULL) t = new binaryNode<type>(x, NULL, NULL);
//    else if(x < t->element) insert(x, t->left);
//    else if(x > t->element) insert(x, t->right);
//    else;
//    }
//
//template <class type>
//void binaryTree<type>::remove(const type &x, binaryNode<type> *&t){
//    if(t==NULL) return; //item not found in list
//    if(x < t->element) remove(x, t->left);
//    else if(x > t->element) remove(x,t->right);
//    else if(t->left != NULL && t->right==NULL){
//        t->element = findMin(t->right)->element;
//        remove(t->element, t->right);
//        }
//    else{
//        binaryNode<type> *oldNode = t;
//        t = (t->left != NULL) ? t->left : t->right;
//        delete oldNode;
//        }
//    }



#endif



