#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector <string> combination(string num)
    {
        if(num.empty())
        {
            return {};
        }
        vector <string> result;
        string current;
        vector <string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(result, current, map, num, 0);
        return result;
    }
    void backtrack(vector <string> &result, string &current, const vector <string> &map, const string &num, int index)
    {
        if(index==num.size())
        {
            result.push_back(current);
            return;
        }
        int digit = num[index]-'0';
        for(char c : map[digit])
        {
            current.push_back(c);
            backtrack(result, current, map, num, index+1);
            current.pop_back();
        }
    }
};
int main()
{
    Solution sol;
    int i;
    string num = "53";
    cout<<"Input : "<<num;
    vector <string> result = sol.combination(num);
    cout<<endl;
    cout<<endl;
    cout<<"All possible letter combinations for digits : "<<endl;
    cout<<endl;
    cout<<"[";
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i];
        if(i<result.size()-1)
            cout<<", ";
    }
    cout<<"]";
    cout<<endl;
    return 0;
}
