// leetcode 20
// 

# include <iostream>
# include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> stk;
    int length = s.length();
    if (length % 2 == 1)
        return false;
    for (char temp: s)
    {
        //char temp = s[i];
        if (temp == '(' || temp == '[' || temp == '{')
            stk.push(temp);
        else if (temp == ')' || temp == ']' || temp == '}')
        {
            switch(temp)
            {
                case(')'):
                    if (stk.empty() || stk.top() != '(')
                        return false;
                    break;
                case(']'):
                    if (stk.empty() || stk.top() != '[')
                        return false;
                    break;
                case('}'):
                    if (stk.empty() || stk.top() != '{')
                        return false;
                    break; 
            }
            stk.pop();
        }       
    }
    if (stk.empty())
        return true;
    else
        return false;
}

int main()
{
    string a = "((()))";
    cout << isValid(a);
    return 0;
}
