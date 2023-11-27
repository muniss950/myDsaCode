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
NODE* createNode(int e)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->left=NULL;
	temp->right=NULL;
	temp->info=e;
	return temp;
}
void create(TREE *pt)
{
	NODE *p,*q;
	int e, wish;
	printf("Enter info\n");
	scanf("%d",&e);
	pt->root=createNode(e);
	do
	{
		printf("Enter info\n");
		scanf("%d",&e);
		q=NULL;
		p=pt->root;
		while(p!=NULL)
		{
			q=p;
			if(e < p->info)
				p = p->left;
			else
				p = p->right;
		}
		if(e < q->info)
			q->left = createNode(e);
		else
			q->right = createNode(e);
		printf("Do you wish to continue\n");
		scanf("%d",&wish);
	}while(wish);
}

void io(NODE* r)
{
	if(r!=NULL)
	{
		io(r->left);
		printf("%d ",r->info);
		io(r->right);
	}
}

void inorder(TREE *pt)
{
	io(pt->root);
}

NODE* delNode(NODE *r,int ele)
{
	NODE *temp,*p;
	if(r==NULL)
		return r;
	if(ele < r->info)
		r->left = delNode(r->left,ele);
	else if(ele > r->info)
		r->right = delNode(r->right,ele);
	else
	{
		if(r->left == NULL) //1 right child or No children
		{
			temp=r->right;
			free(r);
			return temp;
		}
		else if(r->right == NULL) //1 left child or No children
		{
			temp=r->left;
			free(r);
			return temp;
		}
		else
		{ 
	//Node to be deleted has both children
	//Finding p’s leftmost child which is the inorder successor
			p=r->right;
			while(p->left != NULL)
				p=p->left;
			r->info=p->info;
			r->right=delNode(r->right, p->info);
		}
	}
	return r;
}

void deleteNode(TREE *pt,int e)
{
	pt->root=delNode(pt->root,e);
}

int main()
{
	int e;
	TREE t;
	init(&t);
	create(&t);
	inorder(&t);
	printf("Enter the element to be deleted\n");
	scanf("%d",&e);
	deleteNode(&t,e);
	printf("After deletion\n");
	inorder(&t);
	return 0;
}