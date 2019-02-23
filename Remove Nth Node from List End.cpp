/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B)
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
