#include<iostream>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    int longestSubstringWithoutRepeatingCharacters(string &input)
    {
        int size = input.length();
        int r = 0;
        int l = 0;
        int len = 0;
        unordered_set <char> st;
        while(r<size)
        {
            if(st.find(input[r])==st.end())
            {
                st.insert(input[r]);
            }
            else
            {
                while(st.find(input[r])!=st.end())
                {
                    st.erase(input[l]);
                    l++;
                }
                st.insert(input[r]);
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
int main()
{
    Solution sol;
    string input = "pwwkew";
    cout<<"Input String : "<<input;
    cout<<endl;
    cout<<endl;
    int result = sol.longestSubstringWithoutRepeatingCharacters(input);
    cout<<"Length of longest substring in "<<input<<" : "<<result;
    cout<<endl;
    return 0;
}
