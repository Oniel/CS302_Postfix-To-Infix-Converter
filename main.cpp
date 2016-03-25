/*
    oniel toledo
    assignment 04
    cs 302 section 1001

    the following program prompts the user for a postfix
    expression, pushes the expression to a stack and creates
    a binary expression tree. The program then terminates
    after the equivalent infix expression has been created and
    outputted
    for more information look at documentation in class header
    files, functions, and code fragements of significance.

    Algorithm (for reference)
    -examine next element in input
    -if operand:
        create a node (left,right NULL)
        move operand to node
        push the node's ADDRESS to stack
    -if operator
        create a node
        move operator to node
        (1) pop address of node from stack-assign to RIGHT
        (2) pop address of node from stack-assign to LEFT
        push node's address to stack
    -loop if input is true
    -when done creating expression tree pop the address from stack
     and assign it to root of the tree

    since I have created a program like this before for another class, I attempted
    to do the program in a different (more efficient and smaller) form, for example
    the two if statements within the algorithm I am used take up 1 line of code each
    in main, this was done by created new efficient functions for the binaryTree.
*/
#include <iostream>
#include <string>
#include <sstream>

#include "linkedStack.h"
#include "binaryTree.h"
using namespace std;

int main()
{
    //variables
    string postfixExpression;
    char postfixChar;

    //object declarations
    linkedStack<char> stack;
    binaryTree <char> tree;

    //prompt user for postfix expression
    cout << "Enter postfix notation string to be converted" << endl;
    cout << "---------------------------------------------" << endl;
    getline(cin, postfixExpression);
    istringstream input(postfixExpression);
    //postfix Expression has been set to the non-STDIN buffer 'input'

    //create a binary expression tree
    input >> postfixChar;
    while(input){
        //if operand...
            //create a new binary node with element as postfixChar
            //and left and right as NULL.
            //createNode will return a pointer to the newNode which is what will be on the stack
        if( postfixChar >= '0' && postfixChar <= '9')
            stack.push(tree.makeLeaf(postfixChar));

        //if operator...
            //create a leaf with operand as element, first pop assigned to the right,
            //and second pop assigned to the left
        else if(postfixChar=='+' || postfixChar=='-' || postfixChar=='*' || postfixChar=='/')
            stack.push(tree.makeLeaf(postfixChar, stack.topNpop(), stack.topNpop()));
        //input next character, if valid will loop again
        input >> postfixChar;
    }
    //at this point there is only one address in the stack, which is the tree's root
    stack.pop();
    //print the tree in inorder form, printTree calls the private inorderPrint function
    //to perform operation and add paranthesis
    tree.printTree();
    cout << endl;

    //done, terminate
    return 0;
}
