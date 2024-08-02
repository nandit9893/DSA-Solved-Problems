#include<iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {}
};
class Solution
{
    public:
    void printList(ListNode *l1)
    {
        ListNode *start = l1;
        cout<<"[";
        while(start!=nullptr)
        {
            cout<<start->data;
            if(start->next!=nullptr)
                cout<<", ";
            start = start->next;
        }
        cout<<"]";
        cout<<endl;
    }
    ListNode *sortedList(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->data<=l2->data)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1!=nullptr)
        {
            curr->next = l1;
        }
        if(l2!=nullptr)
        {
            curr->next = l2;
        }
        return dummy->next;
    }
};
int main()
{
    Solution sol;
    ListNode *l1;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
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
    ListNode *result = sol.sortedList(l1, l2);
    cout<<"Merged sorted lists : ";
    sol.printList(result);
    cout<<endl;
    return 0;
}
