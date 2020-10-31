// leetcode 557
// https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

# include <iostream>
# include <stack>
using namespace std;

string reverseWords(string s)
{
    int pos = 0;
    while (1)
    {
        int end = s.find(" ", pos);
        if (end >= string::npos)
            break;
        for (int i = pos; i < (end+pos)/2; i++)
        {
            swap(s[i], s[end+pos-i-1]);
        }
        pos = end+1;
    }
    for (int i = pos; i < (s.length()+pos)/2; i++)
    {
        swap(s[i], s[s.length()+pos-i-1]);
    }
    return s;
}

int main()
{
    string s = "God Ding";
    cout << reverseWords(s);
}