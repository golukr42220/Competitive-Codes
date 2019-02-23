Node *compute(Node *head)
{
   Node *t,*curr=head,*temp=NULL,*head_ref=NULL;
     int max1=-1;
 while(curr!=NULL)
 {

    while(curr!=NULL)
    {
       if(curr->data>max1)
       {
           max1=curr->data;
           t=curr;
       }
       curr=curr->next;
   }
   if(head_ref==NULL)
    {
      temp=t->next;
      t->next=NULL;
       head_ref=t;
       curr=temp;
       max1=-1;
    }
    else
    {
        Node *t1=head_ref;
        while(t1->next!=NULL)
         t1=t1->next;

      temp=t->next;
      t->next=NULL;
        t1->next=t;
        curr=temp;
        max1=-1;
    }
 }
 return head_ref;

}
