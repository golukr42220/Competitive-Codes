#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};
//struct ListNode *head1=NULL;
struct ListNode *head=NULL;
struct ListNode *head2=NULL;
struct ListNode* create(int data)
{
struct ListNode* temp=new ListNode ;
temp->val=data;
temp->next=NULL;
return temp;
}
/*
struct ListNode* rev(struct ListNode* head1)
{
    struct ListNode *pre,*nxt,*temp=head1;
    nxt=pre=NULL;
    while(temp!=NULL)
    {
        nxt=temp->next;
        temp->next=pre;
        pre=temp;
        temp=nxt;
    }
    head1=pre;
   return head1;

}

struct ListNode* removeDuplicate(struct ListNode* temp)
{
    map<int,int>m;
    struct ListNode *p,*t=temp;

    while(temp!=NULL)
    {
        m[temp->data]++;
        temp=temp->next;
    }

    while(t!=NULL)
    {
        if(m[t->data]==1)
        {
            if(head1==NULL)
              head1=create(t->data);
            else
            {
              struct ListNode*trav=head1;
              while(trav->next!=NULL)
                 trav=trav->next;

            trav->next=create(t->data);
            }
        }
        t=t->next;
      }
    return head1;
}


struct ListNode* removeNthFromEnd(ListNode* A, int B)
{
      struct ListNode *p,*t=A;
      int c=0;
      while(t!=NULL)
      {
          t=t->next;
          c++;
      }
      t=A;
      if(c-B+1==1)
      {
          A=t->next;
          return A;
      }
     else if(B>c)
     {
         A=t->next;
     }
     else if(B==1)
     {
         t=A;

      int i=1,d=c-B+1;
       while(t->next!=NULL)
       {
          p=t;
          t=t->next;

       }
       p->next=NULL;
     }
     else
     {
          t=A;
        int i=1,d=c-B+1;

       while(t!=NULL)
       {
           if(i==d)
            p->next=t->next;
          p=t;
          t=t->next;
          i++;
       }

     }
    return A;
}
*/
struct ListNode* Rotate(struct ListNode *head_ref,int k)
{
       struct ListNode *head1=head_ref;
   int n=0;
   while(head1!=NULL)
   {
       n++;
       head1=head1->next;
   }
   int rot=k%n;
   head1=head_ref;
   while(rot--)
   {
         struct ListNode *trav=head1,*p=NULL;
         while(trav->next!=NULL)
         {
             p=trav;
             trav=trav->next;
         }
         p->next=NULL;
         trav->next=head1;
         head1=trav;
   }
   head_ref=head1;
   return  head_ref;
}
void display(struct ListNode *n)
{
while(n!=NULL)
{
   cout<<n->val<<endl;
    n=n->next;
}
}
int main()
{
    int n,i,j;
   cout<<"enter no of nodes";
   cin>>n;
    for(j=1;j<=n;j++)
    {

        cin>>i;
        if(head==NULL)
        {
            head=create(i);
        }
        else
        {
           struct ListNode* traverse=head;
            while(traverse->next!=NULL)
            {
                traverse=traverse->next;
            }
            traverse->next=create(i);
        }
    }
    /*
    cout<<endl<<"enter no of nodes for second list"<<endl;
   cin>>n;
    for(j=1;j<=n;j++)
    {

        cin>>i;
        if(head1==NULL)
        {
            head1=create(i);
        }
        else
        {
           struct ListNode* traverse=head1;
            while(traverse->next!=NULL)
            {
                traverse=traverse->next;
            }
            traverse->next=create(i);
        }
    }
    */

    //display(head);
    //head=removeDuplicate(head);
    //cout<<"removie"<<endl;
    head= Rotate(head,4);
    display(head);
}
