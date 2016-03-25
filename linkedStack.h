/*
	oniel toledo
	assignemnt 04
	cs 302 section 1001
	
    linkedStack class header file, the stack will be a derivation
    assignment 03 with the exception that the 'element' is a pointer
    to a binaryNode, thus this is a stack of pointers.
    functions used:
        constructor
        destructor
        isEmpty
        makeEmpty
        push
        pop
        top
        topNpop
*/

//check for INFO SHOULD BE toTREE

#ifndef HSTACK
#define HSTACK

#include <iostream>
#include "binaryTree.h"
using namespace std;

//list node ***********************************************
//thee stackNode's toBinaryNode points to a binaryNode
//note: the stack is a list of arrays pointing to trees;
template <class type>
struct stackNode{
    binaryNode<type> *treeAdrs;
    stackNode<type> *next;
    };

//class declarations **************************************
//the stack will be a child class of the binary tree so as to allow usage of the
//binaryNode struct node
template <class type>
class linkedStack:public binaryTree<type> {
    public:
        linkedStack();
        ~linkedStack();
        bool isEmpty() const;
        void makeEmpty();
        void push(binaryNode<type> *tree);
        void pop();
        binaryNode<type>* top() const;
        binaryNode<type>* topNpop();        //returns the address to tree
    private:
        stackNode<type> *stacktop;
};

//implementation functions ********************************
//constructor, sets only variable to NULL
template <class type>
linkedStack<type>::linkedStack(){
    stacktop = NULL;
    }

//destructor
template <class type>
linkedStack<type>::~linkedStack(){
    makeEmpty();}

//return true if stack is empty
template <class type>
bool linkedStack<type>::isEmpty() const{
    return (stacktop == NULL);
    }

//clear the list
template <class type>
void linkedStack<type>::makeEmpty(){
    stackNode<type> *tmp;
    while(stacktop != NULL){
        tmp = stacktop;
        stacktop = stacktop->next;
        delete tmp;
    }
}

//push has been altered. Push will push the address of the
//tree
template <class type>
void linkedStack<type>::push(binaryNode<type> *tree){
    stackNode<type> *newNode = new stackNode<type>;
    newNode->treeAdrs = tree;       //create link to leaf node
    newNode->next = stacktop;
    stacktop = newNode;
    }


//remove  top, used for topNpop function
template <class type>
void linkedStack<type>::pop(){
    stackNode<type> *tmp;
    if(stacktop !=NULL){
        tmp = stacktop;
        stacktop = stacktop->next;
        delete tmp;
        }
        //else list is empty do nothing
    }

//return the binaryNode address on the top of the stack
template <class type>
binaryNode<type>* linkedStack<type>::top() const{
    if(stacktop != NULL)
    return (stacktop->treeAdrs);
    }

//calls the top and pop functions
//pop the function and return the tree address at stackTop->treeAdrs
template <class type>
binaryNode<type>* linkedStack<type>::topNpop(){
    binaryNode<type> *tmp = top();
    pop();
    return tmp;
    }

#endif
