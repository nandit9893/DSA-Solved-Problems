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
    ListNode *createList()
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int x;
        while(1)
        {
            cin>>x;
            if(x==0)
            {
                break;
            }
            ListNode *temp;
            temp = new ListNode(x);
            if(head==nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        return head;
    }
    ListNode *addTwoList(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0)
        {
            int sum = carry;
            if(l1!=nullptr)
            {
                sum = sum + l1->data;
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                sum = sum + l2->data;
                l2 = l2->next;
            }
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        return dummy->next;
    }
    void printList(ListNode *head)
    {
        ListNode *temp = head;
        cout<<"[";
        while(temp!=nullptr)
        {
            cout<<temp->data;
            if(temp->next!=nullptr)
                cout<<", ";
            temp = temp->next;
        }
        cout<<"]";
        cout<<endl;
    }
};
int main()
{
    Solution sol;
    ListNode *l1, *l2, *l;
    cout<<"Enter the values for the list or 0 for exits "<<endl;
    cout<<endl;
    cout<<"Create First List : ";
    l1 = sol.createList();
    cout<<"Create Second List : ";
    l2 = sol.createList();
    cout<<endl;
    cout<<"First List : ";
    sol.printList(l1);
    cout<<"Second List : ";
    sol.printList(l2);
    cout<<endl;
    l = sol.addTwoList(l1, l2);
    cout<<"Output : ";
    sol.printList(l);
}
