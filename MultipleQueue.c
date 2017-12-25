#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int key;
}element;
typedef struct node
{
element data;
struct node *link;
}*queuepointer;
queuepointer front[5]={NULL},rear[5]={NULL};

element deleteq(int i)
{
queuepointer temp=front[i];
element item;
if(front[i]==NULL)
printf("queue empty\n");
else
        item=temp->data;
        front[i]=front[i]->link;
        return(item);
}

void addq(element item,int i)
{
    queuepointer temp;
    temp=(queuepointer)malloc(sizeof(*temp));
    temp->data=item;
    temp->link=NULL;
if(front[i])
rear[i]->link=temp;
else
front[i]=temp;

rear[i]=temp;
}

void display(int i)
{
queuepointer temp=front[i];
if(!temp)
    {
printf("queue empty");
return;
    }
for(;temp;temp=temp->link)
printf("%d\n",temp->data.key);

}
int main()
{
int index, choice;
element item;
while(1)
{
printf("Enter 1. Insert 2. Delete 3. Display 4.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter queue index: ");
scanf("%d",&index);
printf("Enter element to be inserted : ");
scanf("%d",&item.key);
addq(item, index);
break;
case 2:
printf("Enter queue index: ");
scanf("%d",&index);
item=deleteq(index);
if(item.key!=-1)
printf("Element deleted %d", item.key);
break;
case 3:
printf("Enter queue index: ");
scanf("%d",&index);
display(index);
break;
case 4:
exit(0);
}
}
}
