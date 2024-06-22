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
    char peek()
    {
        if (top >= 0)
        {
            return arr[top];
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
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
string infixToPostfix(string infix)
{
    string postfix = "";
    Stack st(infix.length());
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            st.pop();
        }
        else if (isOperator(ch))
        {
            while (!st.isEmpty() &&
                   precedence(ch) <= precedence(st.peek()))
                postfix += st.pop();
            st.push(ch);
        }
    }
    while (!st.isEmpty())
        postfix += st.pop();
    return postfix;
}
int main()
{
    int uchoice = 1;
    do
    {
        cout << "1.Check expression\n2.exit "<<endl;
        cout << "Enter choice: " << endl;
        cin >> uchoice;
        switch (uchoice)
        {
        case 1:
        {
            string expression;
            cout << "Enter an expression: ";
            cin >> expression;
            string postfix =
                infixToPostfix(expression);
            cout << "postfix:" << postfix << endl;
            break;
        }
        case 2:
            break;
        default:
            cout << "Enter proper choice "<<endl;
                break;
        }
    } while (uchoice != 2);
    return 0;
}