#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack <char> bracket;
        for(char c : s)
        {
            if(c=='(' || c=='[' || c=='{')
            {
                bracket.push(c);
            }
            else
            {
                if(bracket.empty())
                    return false;

                char top = bracket.top();
                if( (c==']' && top!='[') || (c=='}' && top!='{') || (c==')' && top!='(') )
                {
                    return false;
                }
                bracket.pop();
            }
        }
        return bracket.empty();
    }
};
int main()
{
    Solution rs;
    string input = "()";
    cout<<"Input parenthesis : "<<input;
    cout<<endl;
    cout<<endl;
    cout<<"Output : "<<(rs.isValid(input) ? "true" : "false")<<endl;
    return 0;
}
