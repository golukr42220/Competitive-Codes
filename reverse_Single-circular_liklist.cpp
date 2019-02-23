
void reverse(struct Node** head_ref)
{
    Node *t1,*t=*head_ref,*current=*head_ref;

    while(t->next != current)
      {
        t=t->next;
      }

    Node *prev=t, *next=NULL;
    current=*head_ref,t1=*head_ref;
    while(current->next!=t1)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    current->next=prev;
     *head_ref=current;
}
