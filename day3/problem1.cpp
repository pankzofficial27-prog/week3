#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
                return false;

            if((ch == ')' && st.top() == '(') ||
               (ch == '}' && st.top() == '{') ||
               (ch == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    if(isValid(s))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}