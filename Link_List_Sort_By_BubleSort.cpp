void sortList(Node** head)
{
   Node *i,*j;
   for(i=*head ;i->next!=NULL; i=i->next)
   {
      for(j=i->next; j!=NULL; j=j->next)
      {
         if(i->data>j->data)
         {
             int d=i->data;
             i->data=j->data;
             j->data=d;
         }
      }
   }
}
