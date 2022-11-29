/*
 wk7_palindrome_TBoston.cxx

 Filename:       wordPalindrome.cxx
 Summary:        This program will test to see if a series of words entered by the user is a word-by-word palindrome

 Specifications: Design, define, implement and compare a stack and queue. Using a stack and a queue to compare words.

 Test cases:     Input sentence entered by the user.

 Author:         Timothy Boston
 Created:        November 14, 2022
 Summary of Modifications:
 */
#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
#include <string>
#include "queue1.h"
#include "stack1.h"
using namespace std;


void pushIntoQueue(string userInput, queue<string>&);
void pushIntoStack(string s, stack<string>&);
bool compareStackQueue(stack<string>&, queue<string>&);

int main( )
{
    queue<string> q1;
    stack<string> s1;
    string userInput;
    int cont, temp;
    do
    {
    cout << "\t\t**********PALINDROME PROGRAM**********\n\n";
    cout << "Welcome! Type in a sentence without punctuation and I will see if it's a palindrome:" << endl;
    cin.clear();
    getline(cin, userInput);

    pushIntoQueue(userInput, q1);
    pushIntoStack(userInput, s1);

    cin.ignore(80, '\n');
    if (compareStackQueue(s1, q1))
        cout << "This is a palindrome." << endl;
    else
        cout << "This is not a palindrome." << endl;


    cout << "\nWould you like to check another line? type 1 for yes and 0 for no...\n";
    cin >> temp;
    cont = temp;
    //cin.clear();
    }while(cont != 0);
    return EXIT_SUCCESS;
}

//push the user input into a queue
void pushIntoQueue(string userInput, queue<string>& q1)
{
  //create an empty temp string
  string temp = "";

  //traverse the entire string
  for(int i = 0; i < userInput.length(); i++)
  {
    if(userInput[i] == ' ')
    {

      //push the temp variable into the stack
      q1.push(temp);

      temp = "";
    }
    else
    {
      temp = temp + userInput[i];
    }
  }
}

//function to push the user input into the stack
void pushIntoStack(string s, stack<string>& s1)
{

  //create an empty temp string
  string temp = "";

  //traversing the entire string
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ')
    {
      //push the temp variable into the stack
      s1.push(temp);

      //assigning temp variable as empty
      temp = "";
    }
    else
    {
      temp = temp + s[i];
    }

  }
  s1.push(temp);
}

//compares both stack and queue and returns true or false depending if the user input is a palindrome
bool compareStackQueue(stack<string>& s1, queue<string>& q1)
{
    bool isMatch = false;

    while(!s1.empty() && !q1.empty())
    {
        if(s1.top() == q1.front())
        {
            isMatch = true;
            s1.pop();
            q1.pop();
        }
        else
        {
            isMatch = false;
            break;
        }
    }
    return isMatch;
}
