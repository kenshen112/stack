/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    Kenyon Bunker and Tim O'Barr
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

//Function to return precedence of operators 
int orderOfOperations(char c)
{
   if (c == '^')
      return 3;
   else if (c == '*' || c == '/')
      return 2;
   else if (c == '+' || c == '-')
      return 1;
   else
      return -1;
}
/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   custom::stack<char> stack;

   //flag marker for start of stack
   stack.push('S');
   string postfix;

   for (int iInfix = 0; iInfix < infix.length(); iInfix++)
   {
      //Operands; numeric and alpha
      if (infix[iInfix] >= '0' && infix[iInfix] <= '9')
      {
         postfix += infix[iInfix];
      }

      //Parentheses '('
      else if (infix[iInfix] == '(')
      {
         stack.push('(');
      }

      // Parentheses ')'
      else if (infix[iInfix] == ')')
      {
         while (stack.top() != 'S' && stack.top() != '(')
         {
            char c = stack.top();
            stack.pop();
            postfix += c;
         }
         if (stack.top() == '(')
         {
            char c = stack.top();
            stack.pop();
         }
      }

      //Operator
      else {
         while (stack.top() != 'S' && orderOfOperations(infix[iInfix]) <= orderOfOperations(stack.top()))
         {
            char c = stack.top();
            stack.pop();
            postfix += c;
         }
         stack.push(infix[iInfix]);
      }

   }
   //Pop remaining elements from the stack 
   while (stack.top() != 'S')
   {
      char c = stack.top();
      stack.pop();
      postfix += c;
   }
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
