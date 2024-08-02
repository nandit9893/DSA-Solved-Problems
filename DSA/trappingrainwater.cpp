#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector <int> &height)
    {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxWater = 0;
        while(i<j)
        {
            int w = j-i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxWater = max(area, maxWater);
            if(height[i]>height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return maxWater;
    }
};
int main()
{
    Solution sol;
    int i;
    vector <int> height = {1,8,6,2,5,4,8,3,7};
    cout<<"Input array with height of elevation having width 1 : ";
    cout<<"[";
    for(i=0;i<height.size();i++)
    {
        cout<<height[i];
        if(i<height.size()-1)
            cout<<", ";
    }
    cout<<"]";
    cout<<endl;
    cout<<endl;
    int result = sol.maxArea(height);
    cout<<"Amount of water it can trap : "<<result;
    cout<<endl;
    return 0;
}
