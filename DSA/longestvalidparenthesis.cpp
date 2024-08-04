#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution
{
public:
    int longestValidParenthesis(string s)
    {
        stack <int> st;
        st.push(-1);
        int maxLen = 0;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i-st.top());
                }
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution sol;
    string input;
    cout<<"Enter the string of brackets : ";
    cin>>input;
    cout<<endl;
    int result = sol.longestValidParenthesis(input);
    cout<<"Longest valid parenthesis : "<<result;
    cout<<endl;
    return 0;
}
