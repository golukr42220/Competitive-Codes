/*
   count length of both linked list.
    then check which one is greater, greater linked list traverse abs(len1-len2) times.
    After that traverse both  simultaneously, and check where both linked list are same, Print that number.
*/
int intersectPoint(Node* head1, Node* head2)
{
  int n1=0,n2=0;
  Node *t2,*t1=head1;
  while(t1!=NULL)
  {
      t1=t1->next;
      n1++;
  }
    t2=head2;
  while(t2!=NULL)
  {
      t2=t2->next;
      n2++;
  }

   int d=abs(n1-n2);
      if(n1==n2)
      {
          t1=head1,t2=head2;
         while(t2!=NULL && t1!=NULL)
         {
             if(t1->data==t2->data)
               return t1->data;

           t2=t2->next;
            t1=t1->next;
          }
      }
      else if(n1>n2)
      {
          t1=head1,t2=head2;
           int i=1;
           while(i<=d)
            {
                t1=t1->next;
                i++;
            }
         while(t2!=NULL && t1!=NULL)
         {
             if(t1->data==t2->data)
               return t1->data;

           t2=t2->next;
            t1=t1->next;
          }
      }
      else if(n1<n2)
       {
           t1=head1,t2=head2;
           int i=1;
           while(i<=d)
            {
                t2=t2->next;
                i++;
            }
         while(t2!=NULL && t1!=NULL)
         {
             if(t1->data==t2->data)
               return t1->data;

           t2=t2->next;
            t1=t1->next;
          }
      }
      return -1;

}
