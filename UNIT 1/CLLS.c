#include <stdio.h> 
#include <stdlib.h>

struct node 
{
    int data; 
    struct node* next;
}; 

struct node* addToEmpty(int);
struct node* addAtBeg(struct node*,int);
void print(struct node*);
struct node* addAtEnd(struct node*,int);
struct node* addAfterPos(struct node*,int, int);
struct node* createList(struct node*);
struct node* delFirst(struct node*);
struct node* delLast(struct node*);
struct node* delInter(struct node*,int);
int main() 
{ 
    int data = 45; 
    struct node* tail; 
    
	tail = addToEmpty(data);
	printf("\n-----------------------------------\n");
	printf("Displaying the INITIAL LIST\n");
	print(tail);
	
	printf("\n-----------------------------------\n");
	printf("Inserting 34 at Beginning\n");
	tail = addAtBeg(tail, 34); 
    print(tail); 
	
	printf("\n-----------------------------------\n");
	printf("Inserting 6 and 56 at End\n");
	tail = addAtEnd(tail, 6);
    tail = addAtEnd(tail, 56);
	print(tail); 
	
	printf("\n-----------------------------------\n");
	printf("Inserting 66 at after Intermediate position 2\n");
	tail = addAfterPos(tail, 66, 2); 
    print(tail);
	
	printf("\n-----------------------------------\n");
	printf("CREATING A CIRCULAR LINKED LIST\n");
	tail = createList(tail); 
    print(tail);
	
	printf("\n-----------------------------------\n");
	printf("Deleting the first node from the list\n");
	tail = delFirst(tail); 
    print(tail);
	
	printf("\n-----------------------------------\n");
	printf("Deleting the last node from the list\n");
	tail = delLast(tail);  
    print(tail); 
	
	
	printf("\n-----------------------------------\n");
	printf("Deleting the intermediate node from the list\n");
	tail = delInter(tail, 3); 
    print(tail);
     
    return 0; 
}

// function to create the circular singly node

struct node* addToEmpty(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->next = temp; 
    return temp;
}

struct node* addAtBeg(struct node* tail, int data)
{ 
    struct node* newP = (struct node*)malloc(sizeof(struct node)); 
    newP->data = data; 
    newP->next = tail->next; 
    tail->next = newP; 
    return tail; 
}

void print(struct node* tail)
{ 
    struct node* p = tail->next; 
    do
    { 
        printf("%d ", p->data); 
        p = p->next;
    } while(p!=tail->next); 
}

struct node* addAtEnd(struct node* tail, int data)
{ 
    struct node* newP = (struct node*)malloc(sizeof(struct node)); 
    newP->data = data; 
    //newP->next = NULL; 

    newP->next = tail->next; 
    tail->next = newP; 
    tail = tail->next; 
    return tail; 
}

struct node* addAfterPos(struct node* tail, int data, int pos) 
{
    struct node* p = tail->next; 
    struct node* newP = (struct node*)malloc(sizeof(struct node)); 
    newP->data = data; 
    newP->next = NULL; 
    while(pos > 1)
    {  
        p = p->next; 
        pos--; 
    }
    newP->next = p->next;
    p->next = newP; 
    if(p == tail)
    {
        tail = tail->next; 
    }
    return tail; 
}

struct node* createList(struct node* tail) 
{ 
    int i, n, data; 
    printf("Enter the number of nodes of the linked list: "); 
    scanf("%d", &n); 
    
    if(n == 0) 
        return tail; 
    /*
	printf("Enter the element 1: "); 
    scanf("%d", &data); 
    tail = addToEmpty(data); 
	*/

    for(i=1; i<=n; i++) 
    { 
        printf("Enter the element %d: ", i); 
        scanf("%d", &data); 
        tail = addAtEnd(tail, data); 
    }
    return tail; 
}

struct node* delFirst(struct node* tail)
{ 
    if(tail == NULL) 
        return tail; 
    if(tail->next == tail)
    {
        free(tail); 
        tail = NULL; 
        return tail; 
    }
    struct node* temp = tail->next; 
    tail->next = temp->next; 
    free(temp); 
    temp = NULL; 
    return tail;  
}

struct node* delLast(struct node* tail)
{
    if (tail == NULL) 
        return tail; 
    struct node* temp = tail->next; 
    if(tail->next == tail)
    { 
        free(tail); 
        tail = NULL; 
        return tail; 
    } 
    while(temp->next != tail) 
    {   
        temp = temp->next; 
    }
    temp->next = tail->next; 
    free(tail); 
    tail = temp; 
    return tail; 
}

struct node* delInter(struct node* tail, int pos) 
{ 
    if(tail == NULL) 
        return tail; 
    struct node* temp = tail->next; 
    if(tail->next == tail) 
    { 
        free(tail); 
        tail = NULL; 
        return tail; 
    } 
    while(pos > 2) 
    { 
        temp = temp->next; 
        pos--; 
    } 
    struct node* temp2 = temp->next; 
    temp->next = temp2->next; 

    //HANDLING THE CASE OF DELETING THE LAST NODE
    if(temp2 == tail) 
        tail = temp; 
    free(temp2); 
    temp2 = NULL; 
    return tail; 
}