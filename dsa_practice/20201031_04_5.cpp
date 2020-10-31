// leetcode 5
// https://leetcode-cn.com/problems/longest-palindromic-substring/

# include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    int length = s.length();
    if (length == 1 || length == 2)
        return true;
    else
        return isPalindrome(s.substr(1, length-1));
}
string longestPalindrome(string s)
{

}

int main()
{

}