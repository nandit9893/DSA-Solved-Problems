#include<iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
    double medianResult(int a[], int n1, int b[], int n2)
    {
        int c[n1+n2];
        merge(a, a + n1, b, b + n2, c);
        int totalsize = n1+n2;
        if(totalsize%2==0)
        {
            return (c[totalsize / 2 - 1] + c[totalsize / 2]) / 2.0;
        }
        else
        {
            return (c[totalsize/2]);
        }
    }
};
int main()
{
    Solution sol;
    int n1, n2, i;
    cout<<"Enter the size of first sorted array : ";
    cin>>n1;
    cout<<endl;
    int a[n1];
    cout<<"Enter the elements of first array : ";
    for(i=0;i<n1;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    cout<<"Enter the size of second sorted array : ";
    cin>>n2;
    cout<<endl;
    int b[n2];
    cout<<"Enter the elements of second array : ";
    for(i=0;i<n2;i++)
    {
        cin>>b[i];
    }
    cout<<endl;
    cout<<"First sorted array : ";
    for(i=0;i<n1;i++)
    {
        cout<<" "<<a[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<"Second sorted array : ";
    for(i=0;i<n1;i++)
    {
        cout<<" "<<b[i];
    }
    cout<<endl;
    cout<<endl;
    double median = sol.medianResult(a, n1, b, n2);
    cout<<"Median : "<<median;
    cout<<endl;
    return 0;
}

