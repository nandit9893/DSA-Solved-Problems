#include<iostream>
#include<vector>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {};
};
class Solution
{
public:
    void printList(ListNode *l)
    {
        ListNode *L = l;
        cout<<"[";
        while(L!=nullptr)
        {
            cout<<L->data;
            if(L->next!=nullptr)
                cout<<", ";
            L = L->next;
        }
        cout<<"]";
        cout<<endl;
    }
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2)
    {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1->data<=l2->data)
        {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *partitionAndMerge(int start, int end, vector <ListNode*> lists)
    {
        if(start>end)
        {
            return nullptr;
        }
        if(start==end)
        {
            return lists[start];
        }
        int mid = start + (end-start)/2;
        ListNode *l1 = partitionAndMerge(start, mid, lists);
        ListNode *l2 = partitionAndMerge(mid+1, end, lists);
        return mergeTwoSortedLists(l1, l2);
    }
    ListNode *sortedList(vector <ListNode*> &lists)
    {
        int k = lists.size();
        if(k==0)
            return nullptr;
        return partitionAndMerge(0, k-1, lists);
    }
};
int main()
{
    Solution sol;
    ListNode *l1;
    l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    cout<<"First sorted list : ";
    sol.printList(l1);
    cout<<endl;

    ListNode *l2;
    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    cout<<"Second sorted list : ";
    sol.printList(l2);
    cout<<endl;

    ListNode *l3;
    l3 = new ListNode(2);
    l3->next = new ListNode(6);
    cout<<"Third sorted list : ";
    sol.printList(l3);
    cout<<endl;

    vector <ListNode*> lists = {l1, l2, l3};
    ListNode *result = sol.sortedList(lists);
    cout<<"Merged sorted lists : ";
    sol.printList(result);
    return 0;
}
