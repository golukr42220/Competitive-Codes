/*
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln.
Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.

*/
Node *Place(Node *t)
{
 Node *cur=t;
 Node *n=t;
 while(n!=NULL && n->next!=NULL)
 {
     cur=cur->next;
     n=n->next->next;
 }
 cout<<cur->data<<endl;
 return cur;
}
Node *Reverse(Node *t)
{
    Node *prev=NULL;
    Node *cur=t;
    while(cur!=NULL)
    {
        Node *nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}
Node *Merge(Node *root,Node *sec)
{
    Node *res=root;
    //cout<<root->next->data;
    while(root!=NULL && sec!=NULL)
    {
        Node *nxt=root->next;
        root->next=sec;
        Node *sec2=sec->next;
        sec->next=nxt;
        sec=sec2;
        root=nxt;
    }
    return res;
}
Node *inPlace(Node *root)
{
 Node *half=Place(root);
 Node *sec=Reverse(half->next);
 half->next=NULL;
 return Merge(root,sec);

}

