#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> in, out;

public:
    void push(int x) {
        in.push(x);
    }

    int pop() {
        peek();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;

    return 0;
}