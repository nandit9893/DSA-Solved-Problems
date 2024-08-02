#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(string s1,string s2,string s3)
    {
        int size = min(min(s1.length(), s2.length()), s3.length());
        string prefix = "";
        int i;
        for(i=0;i<size;i++)
        {
            if(s1[i]==s2[i] && s2[i]==s3[i])
            {
                prefix = prefix+s1[i];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};
int main()
{
    Solution sol;
    string s1,s2,s3;
    cout<<"Enter the strings : "<<endl;
    cout<<endl;
    cout<<"String 1 : ";
    cin>>s1;
    cout<<endl;
    cout<<"String 2 : ";
    cin>>s2;
    cout<<endl;
    cout<<"String 3 : ";
    cin>>s3;
    cout<<endl;
    string result = sol.longestCommonPrefix(s1,s2,s3);
    if(result.empty())
    {
        cout<<"No common prefix "<<endl;
    }
    else
    {
        cout<<"Longest common prefix among "<<s1<<", "<<s2<<", and "<<s3<<" : "<<result<<endl;
    }
    cout<<endl;
    return 0;
}

