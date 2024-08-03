#include<iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};
class Solution
{
public:
    void printList(Node *l1)
    {
        Node *result = l1;
        cout<<"[";
        while(result!=nullptr)
        {
            cout<<result->data;
            if(result->next!=nullptr)
                cout<<", ";
            result = result->next;
        }
        cout<<"]";
        cout<<endl;
    }
    Node *swapNodes(Node *HEAD)
    {
        if(HEAD==nullptr || HEAD->next==nullptr)
            return HEAD;
        // A = HEAD
        // B = HEAD->next
        // C = HEAD->next->next

        //temp = head->next
        //A->next = swapNodes(HEAD->next->next);
        //B->next = A
        Node *temp = HEAD->next;
        HEAD->next= swapNodes(HEAD->next->next);
        temp->next = HEAD;
        return temp;
    }
};
int main()
{
    Solution sol;
    Node *l = new Node(1);
    l->next = new Node(2);
    l->next->next = new Node(3);
    l->next->next->next = new Node(4);
    cout<<"List : ";
    sol.printList(l);
    cout<<endl;

    Node *result = sol.swapNodes(l);
    cout<<"List after swaping the nodes in pair: ";
    sol.printList(result);
    cout<<endl;
    return 0;
}
