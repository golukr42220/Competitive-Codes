ListNode* newNode(int data)
{
    ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val=data;
    temp->next=NULL;
    return temp;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B)
{
   int dig,r=0;
     ListNode *head=NULL,*first=A,*second=B,*temp;
     while(first!=NULL && second!=NULL)
     {
         dig = (first->val + second->val + r)%10;
         r=    (first->val + second->val + r)/10;

         if(head==NULL)
          {
              temp=newNode(dig);
            head=temp;

          }
         else
        {
            temp->next=newNode(dig);
            temp=temp->next;
        }
        first=first->next;
        second=second->next;
     }
     if(first==NULL && second==NULL)
       return head;

     while(first!=NULL)
     {
         dig = (first->val + r)%10;
         r= (first->val + r)/10;

        temp->next=newNode(dig);
        temp=temp->next;

        first=first->next;
     }

      while(second!=NULL)
      {
         dig = (second->val + r)%10;
         r= (second->val + r)/10;

        temp->next=newNode(dig);
        temp=temp->next;

        second=second->next;
     }
     if(r)
     {
        temp->next=newNode(r);
        temp=temp->next;

     }
     return head;
}
