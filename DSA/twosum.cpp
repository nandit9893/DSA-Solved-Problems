#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int target)
    {
        vector<int> result;
        int size = nums.size();
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution rs;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    cout<<"Input : ";
    cout<<"[";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i];
        if(i<nums.size()-1)
            cout<<", ";
    }
    cout<<"]"<<endl;
    cout<<"Target : "<<target<<endl;
    vector<int> result = rs.findIndices(nums, target);
    if(!result.empty())
    {
        cout<<"Indices are : ["<<result[0]<<", "<<result[1]<<"]"<< endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
