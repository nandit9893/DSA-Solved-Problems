#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxlen = 0;
        int sp = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalinrome(s, i, j))
                {
                    if(j-i+1>maxlen)
                    {
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
    bool isPalinrome(string &s, int i, int j)
    {
        if(i>=j)
        {
            return true;
        }
        if(s[i]==s[j])
        {
            return isPalinrome(s, i+1, j-1);
        }
        return false;
    }
};
int main()
{
    Solution sol;
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    string result = sol.longestPalindrome(s);
    cout<<endl;
    cout<<"Longest palindromic substring in "<<s<<" : "<<result<<endl;
    return 0;
}



