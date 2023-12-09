//program implement tries
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct trienode
{
	struct trienode *child[256];
	int endofword;
};
int length;
int level;
char word[100];
 int isempty(struct trienode *root);
void display(struct trienode *curr);
struct trienode *getnode();
void insert(struct trienode *root, char *key);
struct trienode* delete(struct trienode *root, char *str, int level, int length);


 int main()
 {
  struct trienode *root;
  char key[100],prefix[100];
  int ch,k,count;
//length=0;
  root=getnode();
  while(1)
  {
    printf("\n1. Insert..");
    printf("\n2. Delete..");
    printf("\n3. Search..");
    printf("\n4. Display..");
    printf("\n5. Display-length");
    printf("\n6. Display-Prefix");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter word..\n");
              scanf("%s",key);
              insert(root,key);
              break;
     case 2: printf("Enter the word for deletion..\n");
               scanf("%s",key);
              level=0;
               delete(root,key,0,4);
               break;
       case 3: printf("Enter the word to search..\n");
               scanf("%s",key);
               k=search(root,key);
               if(k)
                 printf("\nWord found..\n");
               else
                 printf("\nNot found..\n");
               break; 
	
       case 4:length=0;
               display(root);
               break;
     /* case 5:length=0;
               printf("Enter the length");
               scanf("%d",&count);
               display_length(root,count);
               break;
       case 6:length=0;
              printf("Enter the prefix..\n");
              scanf("%s",prefix);
              display_prefix(root,prefix);
              break;*/
	
 
    }
  }
}

int search(struct trienode * root, char *key)
{
int i,index;
struct trienode *curr;
curr=root;
 for(i=0;key[i]!='\0';i++)
 { index=key[i];
 if(curr->child[index]==NULL)
 return 0;
 curr=curr->child[index];
 }
 if(curr->endofword==1)
 return 1;
 return 0;
}

struct trienode* delete(struct trienode *root, char *key, int level, int length)
{
	if(root==NULL)
		return NULL;

	if(length==level)
	{
		if(root->endofword)
			root->endofword=0;

		if(isempty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
	}

	int index=key[level];
	root->child[index]=delete(root->child[index],key,level+1,length);
	if(root->endofword==0 && isempty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
}
int isempty(struct trienode *root)
{
	int i;
	for(i=0;i<256;i++)
		if(root->child[i]!=NULL)
			return 0;
	return 1;
}
void insert(struct trienode *root, char *key)
{
	struct trienode *cur;
	int i,index;
	cur=root;
	for(i=0;key[i]!='\0';i++)
	{
		index=key[i];
		if(cur->child[index]==NULL)
			cur->child[index]=getnode();
		cur=cur->child[index];	
	}
	cur->endofword=1;
	
}

struct trienode *getnode()
{
	int i;
	struct trienode *temp;
	temp=(struct trienode*)malloc(sizeof(struct trienode));
	for(i=0;i<256;i++)
		temp->child[i]=NULL;
	temp->endofword=0;
	return temp;
}
 void display(struct trienode *curr)
 {
   int i,j;	 
	 for(i=0;i<256;i++)
	 {
	 if(curr->child[i]!=NULL)
		 {
	         word[length++]=i; //copy the character
	         if(curr->child[i]->endofword==1)
			 {
				 printf("\n");
				 for(j=0;j<length;j++)
					 printf("%c",word[j]);				 
			 }
			 display(curr->child[i]);
		 }
	 }
     length--;
	 return;
 }

 
