#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {}; 

};


void insert(Node*& head, int data)
{
    Node* nn = new Node(data);

    if(!head)
    {
        head=nn;
        return;
    }
    
    Node* temp=head;

    while(temp->next)
    {
        temp=temp->next;
    }

    temp->next=nn;
}


void print(Node* head)
{
    if(head==NULL)
    cout<<"EMPTY";

    while(head)
    {
        if(head->next!=NULL)
        cout<<head->val<<" -> ";
        else
        cout<<head->val;
        head=head->next;
    }
    
    cout<<endl;
}


Node* reverseList(Node*head,int left, int right)
{
    if(!head|| left==right)
    return head;

    Node* dummy= new Node(0);
    dummy->next=head;
    Node* temp=dummy;

    for(int i=1;i<left;i++)
    temp=temp->next;

    Node* start=temp->next;
    Node* end=start;

    for(int i=left;i<right;i++)
    end=end->next;

    Node* next=end->next;
    end->next=NULL;

    Node *curr=start,*prev=NULL,*nextNode=NULL;
    while(curr)
    {
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;

    }

    temp->next=prev;
    start->next=next;

    return dummy->next;


}




void solve()
{
    Node* head=NULL;

   

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        insert(head,k);
    }
    
    int left,right;
    cin>>left>>right;


   cout<<"Orginal List : ";
   print(head);

   cout<<endl;
   Node* reversed = reverseList(head,left,right);


   cout<<"Reversed List from left to right index : ";
   print(reversed);



    
   
  
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}