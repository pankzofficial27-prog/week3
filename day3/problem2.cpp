#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> minSt;

public:

    void push(int val)
    {
        st.push(val);

        if(minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }

    void pop()
    {
        if(st.top() == minSt.top())
            minSt.pop();

        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack s;

    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);

    cout << "Minimum = " << s.getMin() << endl;

    s.pop();

    cout << "Minimum = " << s.getMin() << endl;

    return 0;
}