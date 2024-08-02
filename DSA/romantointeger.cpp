#include<iostream>
using namespace std;
class Solution
{
public:
    int romantointeger(string name)
    {
        string s[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int result = 0;
        int i;
        for(i=0;i<13;i++)
        {
            while(name.find(s[i])==0)
            {
                result = result+values[i];
                name = name.substr(s[i].length());
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    string name;
    cout<<"Enter the Roman Numerals : ";
    cin>>name;
    cout<<endl;
    int num = sol.romantointeger(name);
    cout<<"Integer : "<<num;
    cout<<endl;
    return 0;
}

