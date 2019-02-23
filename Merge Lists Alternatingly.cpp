/*
For example:
Input:
List1- 5->7->17->13->11
List2- 12->10->2->4->6
Output:
List1- 5->12->7->10->17->2->13->4->11->6
List2- (empty)

For example 2:
Input:
List1- 1->2->3
List2- 4->5->6->7->8
Output:
List1- 1->4->2->5->3->6
List2- 7->8
*/
void mergeList(struct Node **p, struct Node **q)
{
    Node *f=*p,*s=*q;
    Node *nxt=NULL,*pre=NULL;

    while(f!=NULL && s!=NULL)
    {
        nxt=f->next;
        f->next=s;
         pre=s->next;
        s->next=nxt;
        f=nxt;
        s=pre;
    }
    *q=s;

}
