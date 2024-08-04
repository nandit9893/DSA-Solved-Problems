#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int gola_index = -1;
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                gola_index = i-1;
                break;
            }
        }
        if(gola_index!=-1)
        {
            int j;
            int swap_index = gola_index;
            for(j=n-1;j>gola_index;j--)
            {
                swap_index = j;
                break;
            }
            swap(nums[gola_index], nums[swap_index]);
            reverse(nums.begin()+gola_index+1, nums.end());
        }
    }
};

int main()
{
    Solution sol;
    vector <int> nums = {1,2,3};
    cout<<"Original string: ";
    for(int num : nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<endl;
    sol.nextPermutation(nums);
    cout<<"Next permutation: ";
    for(int num : nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}
