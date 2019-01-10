#include<stdio.h>
#include<stdlib.h>

typedef struct node
  {
 int data;
 struct node * prev,*next;
 }node;

node * head =NULL,*tail = NULL,*temp = NULL,*ptr=NULL,*after = NULL;

void create(int data)
   {
temp = (node *)malloc(sizeof(node));
temp->prev = NULL;
temp->next = NULL;
temp->data = data;
    }
void insert(int data)
    {
if(head==NULL)//when there is new node
    {
create(data);
head = temp;
tail = head;
    }
else if(tail->data<data)

    {
create(data);
tail->next = temp;
 temp->prev = tail;
 tail = temp;
     }
  else if(head->data>data)//smallest element among all must me head
    {
  create(data);
  temp->next = head;
  head->prev = temp;
  head = temp;
    }

  else
    {
  ptr = head;
  while(ptr->data<data)//In between the nodes
  ptr = ptr->next;
  create(data);
  after = ptr->prev;
  after->next = temp;
  temp->prev = after;
  temp->next = ptr;
  ptr->prev = temp;
    }
    }
void display(int x)
   {
 printf("The elements of the list:");
 for(ptr=head;ptr!=NULL;ptr=ptr->next)
   {
      printf("%d, ",ptr->data);
   }
  printf("\nTriplets of the key:\n");
  node *ptr1=NULL,*ptr2=NULL,*ptr3=NULL;
  int count=0;
  for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
{
  for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
{
  for(ptr3=ptr2->next;ptr3!=NULL;ptr3=ptr3->next)
{
  if((ptr1->data + ptr2->data + ptr3->data)==x)
{
  printf("(%d,%d,%d) \n",ptr1->data,ptr2->data,ptr3->data);
  count++;
 }
   }
   }
   }
printf("\n");

if(count==0)
  {
   printf("NO TRIPLETS FOR THE KEY\n");
  }
  else
  {
    printf("%d TRIPLETS EXIST\n", count);
  }
  }

void main()
  {
  int ch, data;
  printf("1.Insert no into the list:\n");
  printf("2. To display the triplets:\n");
  printf("3.Exit\n");
  for(;;){
  printf("Enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
      case 1:
       printf("Enter data\n");
       scanf("%d",&data);
       insert(data);
       break;
      case 2:
      printf("Enter the key:");
       scanf("%d",&data);
       display(data);
       break;
      case 3:
 exit(0);
      default:
        printf("Wrong choice\n");
}}
}
