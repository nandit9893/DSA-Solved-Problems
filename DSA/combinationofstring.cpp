#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
public:
    vector <string> getCombinations(string input)
    {
        vector <string> result;
        string curr = "";
        findCombinations(input, result, curr, 0);
        return result;
    }
    void findCombinations(const string &input, vector <string> &result, string curr, int start)
    {
        if(!curr.empty())
        {
            result.push_back(curr);
        }
        int i;
        for(i=start;i<input.size();i++)
        {
            curr.push_back(input[i]);
            findCombinations(input, result, curr, i+1);
            curr.pop_back();
        }
    }
    void printCombinations(vector <string> &result)
    {
        int count = 1;
        for(const string comb : result)
        {
            cout<<count<<". "<<comb<<endl;
            count++;
        }
    }
};
int main()
{
    Solution sol;
    string input;
    vector <string> result;
    cout<<"Enter a string : ";
    cin>>input;
    cout<<endl;
    cout<<"All combinations of string : "<<endl;
    result = sol.getCombinations(input);
    if(result.empty())
    {
        cout<<"Empty input : "<<endl;
    }
    else
    {
        sol.printCombinations(result);
    }
    return 0;
}
