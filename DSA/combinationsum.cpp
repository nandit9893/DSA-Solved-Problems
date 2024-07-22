#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void printInput(vector <int> &input)
    {
        cout<<"Input : ";
        cout<<"[";
        for(int i=0;i<input.size();i++)
        {
            cout<<input[i];
            if(i<input.size()-1)
                cout<<", ";
        }
        cout<<"]";
        cout<<endl;
        cout<<endl;
    }
    void printOutput(vector <vector<int>> &output)
    {
        cout<<"Ouput : ";
        for(const auto &comb : output)
        {
            cout<<"[";
            for(int i=0;i<comb.size();i++)
            {
                cout<<comb[i];
                if(i<comb.size()-1)
                    cout<<", ";
            }
            cout<<"] ";
        }
        cout<<endl;
        cout<<endl;
    }
    vector <vector<int>> combinationSum(vector <int> &output, int target)
    {
        vector <vector<int>> result;
        vector <int> combination;
        findResult(result, combination, output, target, 0);
        return result;
    }
    void findResult(vector <vector<int>> &result, vector <int> &combination, vector <int> &output, int target, int start)
    {
        if(target==0)
        {
            result.push_back(combination);
            return;
        }
        int i;
        for(i=start;i<output.size();i++)
        {
            if(output[i]<=target)
            {
                combination.push_back(output[i]);
                findResult(result, combination, output, target-output[i], i);
                combination.pop_back();
            }
        }
    }
};
int main()
{
    Solution sol;
    vector <int> input = {2, 3, 5};
    int target = 8;
    sol.printInput(input);
    vector <vector<int>> output = sol.combinationSum(input, target);
    sol.printOutput(output);
    return 0;
}
