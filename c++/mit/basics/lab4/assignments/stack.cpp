#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Stack;

template <typename T>
// don't write <> after operator in prototype
Stack<T> operator+(Stack<T> s1, Stack<T> s2);

template <typename T>
class Stack
{
private:
    friend Stack<T> operator+<>(Stack<T> s1, Stack<T> s2);
    list<T> stack;
    int size = 0;

public:
    bool empty() const
    {
        return stack.empty();
    }
    void push(const T &item)
    {
        size += 1;
        stack.push_back(item);
    }
    T &top()
    {
        return stack.back();
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "Empty Stack" << endl;
        }
        else
        {
            size -= 1;
            stack.remove(stack.back());
        }
    }
    void print()
    {
        for (T &item : stack)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    list<T> getStack()
    {
        return stack;
    }
};

template <typename T>
Stack<T> operator+(Stack<T> s1, Stack<T> s2)
{
    Stack<T> newStack;
    // need getStack() to loop through array, can't loop through object
    for (T &item : s1.getStack())
    {
        newStack.push(item);
    }
    for (T &item : s2.getStack())
    {
        newStack.push(item);
    }
    return newStack;
}

int main()
{
    Stack<int> stack1;
    stack1.pop();
    cout << "top: " << stack1.top() << endl;
    cout << "empty: " << stack1.empty() << endl;
    stack1.push(1);
    cout << "empty: " << stack1.empty() << endl;
    cout << "print: ";
    stack1.print();
    stack1.push(39);
    stack1.push(99);
    cout << "top: " << stack1.top() << endl;
    stack1.pop();
    cout << "print: ";
    stack1.print();

    Stack<int> stack2;
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    Stack<int> summedStack = stack1 + stack2;
    summedStack.print();
}