#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left,*right;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;

void init(TREE *pt)
{
	pt->root=NULL;
}

void create(TREE *pt)
{
	NODE* temp,*p,*q;
	int wish;
	printf("Enter the root info\t:");
	pt->root=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&pt->root->info);
	pt->root->left=NULL;
	pt->root->right=NULL;
	do
	{
		printf("Enter the element :\t");
		temp=(NODE*)malloc(sizeof(NODE));
		scanf("%d",&temp->info);
		temp->left=NULL;
		temp->right=NULL;
		q=NULL;
		p=pt->root;
		while(p!=NULL)
		{
			q=p;
			if(temp->info<p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(temp->info<q->info)
			q->left=temp;
		else
			q->right=temp;
		printf("DO you want to add another 1/0");
		scanf("%d",&wish);
	}while(wish);
}

void inord(NODE	*r)
{
	if(r!=NULL)
	{
		inord(r->left);
		printf("%d\t",r->info);
		inord(r->right);
	}
}	
	
void inorder(TREE *pt)
{
	inord(pt->root);
}

void preord(NODE *r)
{
	if(r!=NULL)
	{
		printf("%d\t",r->info);
		preord(r->left);
		preord(r->right);
	}
}

void preorder(TREE *pt)
{
	preord(pt->root);
}

void postord(NODE* r)
{
	if(r!=NULL)
	{
		postord(r->left);
		postord(r->right);
		printf("%d\t",r->info);
	}
}
void postorder(TREE *pt)
{
	postord(pt->root);
}

int findMinimum(NODE *r)
{
	while(r->left!=NULL)
		r=r->left;
	return r->info;
}

int findMin(TREE *pt)
{
	if(pt->root)
	{
		return findMinimum(pt->root);
	}
	return -1;
}

int findMaximum(NODE *r)
{
	while(r->right!=NULL)
		r=r->right;
	return r->info;
}

int findMax(TREE *pt)
{
	if(pt->root)
	{
		return findMaximum(pt->root);
	}
	return -1;
}

int main()
{
	TREE tobj;
	init(&tobj);
	create(&tobj);
	
	printf("\nInorder\n");
	inorder(&tobj);
	
	printf("\nPreorder\n");
	preorder(&tobj);
	
	printf("\nPostorder\n");
	postorder(&tobj);
	
	int min=findMin(&tobj);
	if(min!=-1)
		printf("\nMin ele is %d\n",min);
	else
		printf("Empty Tree\n");

	int max=findMax(&tobj);
	if(max!=-1)
		printf("Max ele is %d\n",max);
	else
		printf("Empty Tree\n");
	
	return 0;
}

