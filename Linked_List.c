#include<stdio.h>
#include<stdlib.h>



struct node
{
  int data;
  struct node *link;
};

struct node *head = NULL;
struct node *temp,*newnode,*tail,*prev;
int info,num;

void create_linked_list()
{
  

  if(head==NULL){
    
    printf("\nThis is empty linked list ");
    printf("\nEnter the number of Node to create linked list :- ");
    scanf("%d",&num);

    newnode = malloc(sizeof(struct node));
    head = newnode;
    printf("\nEnter the head node Data :- ");
    scanf("%d",&info);

    head->data = info;
    head->link = NULL;
    temp = head;
	
	int i;
    for( i=2; i<=num; i++)
	{

      newnode = malloc(sizeof(struct node));

      temp->link = newnode;
      temp = newnode;
      printf("\n Enter the %d Node data :- ",i);
      scanf("%d",&info);

      newnode->data = info;
      newnode->link = NULL;
      tail = newnode;

    }

  }

  else{

    printf("\n --Linked list is already crated-- :- ");

  }

  
}


void insert_node_at_first()
{
  if(head != NULL){
    printf("\nEnter the data to insert at first :- ");
    scanf("%d",&info);
    newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->link = head;
    head = newnode;
  }
  else{
    printf("\n--The list is Empty-- ");
  }

}

void insert_node_at_last()
{

  if(head != NULL){
    printf("\nEnter the data to insert at Last :- ");
    scanf("%d",&info);
    newnode = malloc(sizeof(struct node));
    newnode->data = info;
    newnode->link = NULL;
    tail->link = newnode;
    tail = newnode;
  }
  else{
    printf("\n--The list is Empty-- ");
  }

}

void delet_node_at_first()
{

  if(head!=NULL){

    temp = head;
    head = head->link;
    free(temp);
    printf("\nThe first node is Deleted \n");

  }
  
  else{
  	
  	printf("\nLinked list is empty\n");
  	
  }

}



void delet_node_at_last()
{
  
  temp = head;
  if(head!=NULL){

   while(temp->link!=NULL){
       
       prev = temp;
       temp = temp->link;
       
   }
   tail = prev;
   tail->link=NULL;
   free(temp);
   
    printf("\nThe Last node is Deleted \n");

  }
  
  else{
  	
  	printf("\nLinked list is empty\n");
  	
  }

}

void print_linked_list()
{

  if(head != NULL){  
    temp = head;
    printf("\nlinked list data :- \n\n");

    while(temp != NULL){
    
      printf("%d ->",temp->data);
      temp = temp->link;

    }
    printf("\n\n");
  }

  else{

    printf("\n--Linked list is Empty--\n");

  }
}

void count_the_element(){
    
    int count=0;
    
    if(head!=NULL){
        
        temp = head;
        while(temp->link!=NULL){
            
            temp = temp->link;
            count = count + 1;
        }
        printf("\nThe - %d - element present in linked list",count+1);
        
    }
    else{
        
        printf("\nlinked list is empty ");
        
    }
}

void search_the_element(){
    
    int search,count=0,count1=0;
    
    if(head!=NULL){
        
        printf("\nEnter the element to search :- ");
        scanf("%d",&search);
        
        temp = head;
        while(temp->link!=NULL){
            
        	temp = temp->link;
           	count1 = count1 + 1;
           
           if(search == temp->data){
               printf("\nthis element - %d - present on - %d - location in linked list",search,count1+1);
               
               count = count+1;
           }   
            
        }
        
        if(count==0){
        	
                printf("\nthis element - %d - is not present in linked list",search);
           
		}
        
    }
    else{
        
        printf("\nlinked list is empty ");
        
    }
    
}


int main()
{


  int num;

  do
  {

    printf("\n------------------------------------------------------");
    printf("\n 1. for create new linked list :- ");
    printf("\n 2. for insert new node at first :- ");
    printf("\n 3. for insearte now node at last :- ");
    printf("\n 4. for Delet node at first :- ");
    printf("\n 5. for Delet node at list :- ");
    printf("\n 6. for print the linked list :- ");
    printf("\n 7. for count the element in linked list :- ");
    printf("\n 8. for search the element in linked list :- ");
    printf("\n 0. to exit :- ");
    printf("\n------------------------------------------------------");

    printf("\nEnter the Number :- ");
    scanf("%d", &num);
    

    switch (num)
    {
    case 1: create_linked_list(); break;

    case 2: insert_node_at_first(); break;

    case 3: insert_node_at_last(); break;

    case 4: delet_node_at_first(); break;

    case 6: print_linked_list(); break;
    
    case 5: delet_node_at_last(); break;
    
    case 7: count_the_element(); break;
    
    case 8: search_the_element(); break;

    case 0: printf("\nExiting the program Thank You\n"); break;

    default: printf("\nEnvalid input :- \n"); break;


    }
  }while (num != 0);
}