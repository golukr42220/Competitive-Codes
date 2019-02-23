
void removeTheLoop(Node *node)
{

     Node *fast=node,*slow=node;

     while(fast && slow && fast->next)
     {
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast)
              slow->next=NULL;
     }

}
