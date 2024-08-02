#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if(n<3)
        {
            return {};
        }
        //result.clear();
        sort(begin(nums), end(nums));
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int n1 = nums[i];
            int target = -n1;
            twoSum(nums, target, i + 1, n - 1);
        }
        return result;
    }
    void twoSum(vector <int> &nums, int target, int i, int j)
    {
        while(i<j)
        {
            if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else if(nums[i]+nums[j]<target)
            {
                i++;
            }
            else
            {
                result.push_back({-target, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                i++;
                j--;
            }
        }
    }
    void printInput(vector <int> &nums)
    {
        cout<<"[";
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i];
            if(i<nums.size()-1)
                cout<<", ";
        }
        cout<<"]";
    }
    void printOutput(vector <vector<int>> result)
    {
        cout<<"Array whose sum is 0 : ";
        for(int i=0;i<result.size();i++)
        {
            cout<<"[";
            for(int j=0;j<result[i].size();j++)
            {
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<", ";
            }
            cout<<"]";
            if(i<result.size()-1)
                cout<<", ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> array = {-1,0,1,2,-1,-4};
    int i, j;
    cout<<"Input array : ";
    sol.printInput(array);
    cout<<endl;
    cout<<endl;
    cout<<"Target : 0";
    cout<<endl;
    cout<<endl;
    vector <vector<int>> result = sol.threeSum(array);
    if(!result.empty())
    {
        sol.printOutput(result);
    }
    else
    {
        cout<<"No arrays found whose sum is 0 : "<<endl;
    }
    cout<<endl;
    return 0;
}
