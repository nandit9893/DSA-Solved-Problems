#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    void getPermutations(string input)
    {
        int count = 0;
        findPermutations(input, 0, input.size()-1, count);
    }
    void findPermutations(string input, int left, int right, int &count)
    {
        if(left==right)
        {
            count++;
            cout<<count<<". "<<input<<endl;
        }
        int i;
        for(i=left;i<=right;i++)
        {
            swap(input[left], input[i]);
            findPermutations(input, left+1, right, count);
            swap(input[left], input[i]);
        }
    }
};
int main()
{
    Solution sol;
    string input;
    cout<<"Enter the string : ";
    cin>>input;
    cout<<endl;
    cout<<"Permutations of string : "<<endl;
    sol.getPermutations(input);
    return 0;
}
