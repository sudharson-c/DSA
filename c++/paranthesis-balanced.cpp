#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int top;
    int maxSize;
    char *arr;

public:
    Stack(int size)
    {
        top = -1;
        maxSize = size;
        arr = new char[maxSize];
    }
    void push(char value)
    {
        if (top < maxSize - 1)
        {
            arr[++top] = value;
        }
        else
        {
            cout << "Stack overflow!" << endl;
        }
    }
    char pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack empty" << endl;
            return '\0';
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};
bool isBalanced(string &expression)
{
    Stack post(expression.length());
    for (char ch : expression)
    {
        if (ch == ' ')
            continue;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            post.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (post.isEmpty())
            {
                if(ch==')')
                    cout << "Require '(' "<<endl;
                else if(ch==']')
                    cout << "Require '[' "<<endl;
                else
                    cout << "Require '{' "<<endl;
                return false;
            }
            char topChar = post.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == ']' && topChar != '[') ||
                (ch == '}' && topChar != '{'))
            {
                if (ch == ')' && topChar != '(')
                    cout << "Require '('" <<endl;
                else if ((ch == ']' && topChar != '['))
                    cout << "Require ']'" <<endl;
                else
                    cout << "Require '}'" <<endl;
                return false;
            }
        }
    }
    if (!post.isEmpty()){
        char topChar = post.pop();
        if (topChar == '(')
            cout << "Require ')'" <<endl;
        else if ( topChar == '[')
            cout << "Require ']'" <<endl;
        else
            cout << "Require '}'" <<endl;
    }
    return post.isEmpty();
}
int main()
{
    int user_choice = 1;
    do
    {
        cout << "1.Check expression\n2.exit " << endl;
        cout
            << "Enter choice: " << endl;
        cin >> user_choice;
        switch (user_choice)
        {
        case 1:
        {
            string expression;
            cout << "Enter an expression: ";
            cin >> expression;
            if (isBalanced(expression))
                cout << "The expression is balanced " << endl;
            else
                cout
                    << "The expression is not balanced " << endl;
            break;
        }
        case 2:
            break;
        default:
            cout << "Enter proper choice " << endl;
            break;
        }
    } while (user_choice != 2);
    return 0;
}