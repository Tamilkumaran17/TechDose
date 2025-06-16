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


void remove_duplicate(Node*head)
{
    

    Node* curr=head;

    while(curr!=NULL)
    {
        Node* prev=curr, *run=curr->next;

        while(run!=NULL)
            {
                if(run->val==curr->val)
                {
                    prev->next=run->next;
                    delete run;
                    run=prev->next;
                }
                else{

                    prev=run;
                    run=run->next;
                }
            }

            curr=curr->next;
    }


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
    
   


   cout<<"Orginal List : ";
   print(head);

   cout<<endl;
   remove_duplicate(head);


   cout<<"Duplicate removed list: ";
   print(head);



    
   
  
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