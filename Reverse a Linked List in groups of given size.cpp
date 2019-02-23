struct node *reverse (struct node *head, int k)
{
   struct node *t=head,*head_ref=NULL;
   struct node *temp=NULL,*curr=head,*pre,*nxt;
   int n=0,tm;
   while(t!=NULL)
   {
       n++;
       t=t->next;
   }
   if(n%k==0)
       tm=n/k;
   else
    tm=n/k+1;
    t=head;

    while(tm--)
    {
         temp=curr;
         int j=0;
         nxt=pre=NULL;
         while(j!=k && curr!=NULL)
         {
             nxt=curr->next;
             curr->next=pre;
             pre=curr;
             curr=nxt;
             j++;
         }

         if(head_ref==NULL)
             head_ref=pre;
        else
        {
            t->next=pre;
            t=temp;
        }
    }
    return head_ref;
}
