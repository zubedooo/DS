#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *ll;
    int data;
    struct node *rl;
}*listp;
void insert(int data,listp ptr)
{
    listp newnode,node;
    newnode=(listp)malloc(sizeof(* newnode));
    newnode->data=data;
    node=ptr->ll;
    newnode->ll=node;
    newnode->rl=node->rl;
    node->rl->ll=newnode;
    node->rl=newnode;
}
void delete(listp ptr)
{
    int data;
    listp node;
    node=ptr;
    printf("enter data to be deleted\n");
    scanf("%d",&data);
    for(node=node->rl;((node-> data)!=data)&& (node->rl!=ptr);node=node->rl) ;
    if(node==ptr)
        printf("only header node left and header node cant be deleted");
    else{
        node->ll->rl=node->rl;
        node->rl->ll=node->ll;
        printf("deleted %d\n",node->data);
        free(node);
    }
}
void displayf(listp ptr)
{
  listp node=ptr;
  node=node->rl;
  while(node!=ptr)
  {
      printf("%d\n",node->data);
      node=node->rl;
  }
  printf("\n\n");
}
void displayb(listp ptr)
{
  listp node=ptr;
  node=node->ll;
  while(node!=ptr)
  {
      printf("%d\n",node->data);
      node=node->ll;
  }
  printf("\n\n");
}
void main()
{
    int ch,i,data;
    listp node,head,ptr;
    node=(listp)malloc(sizeof(* node));
    head=(listp)malloc(sizeof(* head));
    head->rl=head;head->ll=head; ptr=head;
    while(1)
    {
    printf("1.insert\n2.delete\n3. display forward\n4.display reverse\n");
    printf("enter choice");scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter data:");scanf("%d",&data);
                   insert(data,ptr);break;
            case 2:delete(ptr);break;
            case 3:printf("forward direction\n");displayf(ptr); break;
            case 4:printf("reverse direction\n");displayb(ptr); break;
        }
    }
}
