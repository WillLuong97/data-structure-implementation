//Program to check if an expression contains valid parenthese with the right opening and closing
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;


//Function to check if a pair of parentheses are of the same kind
bool checkIfPair(char opening, char closing)
{
    if (opening== '(' && closing== ')')
    {
        return true;
    }

    else if(opening== '{' && closing== '}')
    {
        return true;
    }

    else if(opening== '[' && closing== ']')
    {
        return true;
    }

    
    return false;
}//end of function



//main function to check if the parentheses in the user expression is valid or not
bool checkValidParenthesesCharacter(string &expr)
{
    stack <char> s;
    int i; 
    //looping through the list to find the expression in the string:
    for(i = 0; i < expr.length(); i++)
    {
        if (expr[i]== '(' || expr[i]== '{' || expr[i]== '[')
        {
            s.push(expr[i]);
        }
        else if(expr[i]== ')' || expr[i]== '}' || expr[i]== ']')
        {
            if(s.empty() || !checkIfPair(s.top(), expr[i]))
            {
                printf("False");
                return false;
            }

            else
            {
                s.pop();
            }
            
        }
    }//end for loop
    
    //if the stack is empty, then all the parentheses are correct: 
    if (s.empty()){
        printf("True");
        return true;
    }

    printf("False");
    return false;
}//end of function

//main function: 
int main()
{
    std::string expression;
    //Getting user expression from input: 
    cout << "Please enter the expression for evalutation: ";
    //extracting user input: 
    cin >> expression;
    checkValidParenthesesCharacter(expression);
}
