#include <iostream>
#include <string>
#define maxSize 100
using namespace std;
class Stack{
private:
    int top;
public:
    Stack()
    {
        top = -1;
    }
    int stackArray[maxSize];
    void push(int x)
    {
        if (top <= maxSize - 1)
        {
            stackArray[++top] = x;
            cout << "\n"
                 << x << " is pushed into stack "<<endl;
        }
        else
        {
            cout << "Stack is full" << endl;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    int pop()
    {
        if (this->isEmpty())
        {
            return -9999;
        }
        return stackArray[top--];
    }
    int peek()
    {
        if (isEmpty())
        {
            return -9999;
        }
        return stackArray[top];
    }
};
int main()
{
    Stack stk;
    int choice, n, temp;
    do
    {
        cout << endl;
        cout << "0 - Exit." << endl;
        cout << "1 - Push Item." << endl;
        cout << "2 - Pop Item." << endl;
        cout << "3 - Peek Item" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter item to insert: ";
            cin >> n;
            stk.push(n);
            break;
        case 2:
            temp = stk.pop();
            if (temp != -9999)
                cout << "\n"<< temp << " is removed(popped)."<<endl;
            else
                cout << "\nStack is empty" << endl;
            break;
        case 3:
            temp = stk.peek();
            if (temp != -9999)
                cout << "\n"<< temp << " is top element."<<endl;
            else
                cout << "\nStack is empty" << endl;
            break;
        default:
            cout << "An Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}