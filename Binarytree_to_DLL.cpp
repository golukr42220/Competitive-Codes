Node *convertToDLL(Node *root,Node **head_ref)
{

    static Node *prev=NULL;
    if(!root)
    return NULL;
    convertToDLL(root->left,head_ref);

       if(!(*head_ref))
       *head_ref=root;
     else
     {
         root->left=prev; prev->right=root;
     }
     prev=root;


     convertToDLL(root->right,head_ref);


}
