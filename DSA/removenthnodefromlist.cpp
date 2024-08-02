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
    void printList(ListNode *HEAD)
    {
        cout<<"[";
        ListNode *TAIL = HEAD;
        while(TAIL!=nullptr)
        {
            cout<<TAIL->data;
            if(TAIL->next!=nullptr)
                cout<<", ";
            TAIL = TAIL->next;
        }
        cout<<"]";
        cout<<endl;
    }
    ListNode *removeNthNode(ListNode *HEAD, int n)
    {
        int count = 0;
        ListNode *head = HEAD;
        while(head!=nullptr)
        {
            count++;
            head = head->next;
        }
        int targetIndex = count-n;
        if(targetIndex==0)
        {
            ListNode *newHead = HEAD->next;
            delete HEAD;
            return newHead;
        }
        ListNode *prev = HEAD;
        int i;
        for(i=1;i<targetIndex;i++)
        {
            prev = prev->next;
        }
        ListNode *target = prev->next;
        prev->next = target->next;
        delete target;
        return HEAD;
    }
};
int main()
{
    Solution sol;
    ListNode *HEAD;
    HEAD = new ListNode(1);
    HEAD->next = new ListNode(2);
    HEAD->next->next = new ListNode(3);
    HEAD->next->next->next = new ListNode(4);
    HEAD->next->next->next->next = new ListNode(5);
    cout<<"Input List : ";
    sol.printList(HEAD);

    int n = 2;
    ListNode *result = sol.removeNthNode(HEAD, n);
    cout<<endl;
    cout<<"List after removing "<<n<<"nd node from the end of list : ";
    sol.printList(result);

    return 0;
}
