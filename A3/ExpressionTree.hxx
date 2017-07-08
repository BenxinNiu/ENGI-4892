#ifndef __ExpressionTree_HXX__
#define __ExpressionTree_HXX__

#include <iostream>
using namespace std;

/*
  This class represents a simplified expression tree that will contain
  only the 4 basic arithmetic operators: +, -, *, /, and also parenthesis.
 */
class ExpressionTree
{
  public:
    ExpressionTree(const string& infix);
    ~ExpressionTree();

    // Traverse the expression tree and generate the result
    double evaluate() const { return evaluate(tree); }

  private:
    // Node contains operators and operands (in string format)
    struct ExprNode {
      string data;
      ExprNode* left;
      ExprNode* right;

      ExprNode(const string& d, ExprNode* l = nullptr, ExprNode* r = nullptr)
        : data(d), left(l), right(r) { }
    };

    // Root of our expression tree
    ExprNode* tree;

    // Utility function to test for operator
    //  return true if s is '+', '-', '*', '/', else false
    bool isOperator(const string& s) const;

    // Utility function to compare precedence of op1 and op2
    //  return -1 if lower precedence, 0 if equal, 1 if higher
    int opPrecedence(const string& op1, const string& op2) const;

    // Convert an infix expression into postfix notation
    // pre-condition:   a valid infix expression (each part separated by space)
    // post-condition:  returns a string in postfix form
    string convertInfixToPostfix(const string& infix) const;

    // Utility function to clear memory
    void clear(ExprNode* root);

    // Create an expression tree from a postfix expression
    // pre-condition:   a valid postfix expression (each part separated by space)
    // post-condition:  'tree' points to a valid expression tree
    void buildTreeFromPostfix(const string& postfix);

    // Traverse the expression tree and generate a result
    // pre-condition:   an expression tree already exists
    //                  (ie, buildTreeFromPostfix() has already been called)
    // post-condition:  the expression tree is traversed, and the final
    //                  output calculated (the tree is not modified)
    double evaluate(const ExprNode* root) const;
};

#endif
