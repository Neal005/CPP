#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<windows.h>
struct Node
{
	int Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;
Tree LeftChild(Tree T)
{
    if(T!=NULL) return T->Left;
    else return NULL;
}
Tree RightChild(Tree T)
{
    if(T!=NULL) return T->Right;
    else return NULL;
}
typedef int ElementType;
struct Node1
{
	ElementType Element;
	struct Node1	*Next;
};
typedef struct Node1* Position;
typedef struct
{
	Position Front, Rear;
} Queue;
void makenullQueue(Queue *pQ)
{
	Position Header;
	Header=(struct Node1*)malloc(sizeof(struct Node1)); 
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
}
int emptyQueue(Queue Q)
{
	return (Q.Front==Q.Rear);
}
void enQueue(ElementType X, Queue *pQ)
{ 
	pQ->Rear->Next=(struct Node1*)malloc(sizeof(struct Node1));
	pQ->Rear=pQ->Rear->Next;
	pQ->Rear->Element=X;
	pQ->Rear->Next=NULL;
}
void deQueue(Queue *pQ)
{
	if (!emptyQueue(*pQ))
    {
		Position Tempt;
		Tempt=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}
 } 
ElementType front(Queue Q)
{
	if (!emptyQueue(Q))
		return Q.Front->Next->Element;
	return -1;
}
Tree Search(int x,Tree T)
{
	if(T!=NULL)
	{
    	if(T->Key==x) return T;
    	if(T->Key<x) return Search(x,RightChild(T));
    	if(T->Key>x) return Search(x,LeftChild(T));
    }
    return NULL;
}
void width_browse(Tree T)
{
    Queue D;
    Tree T1=T;
    makenullQueue(&D);
    enQueue(T1->Key,&D);
    while(!emptyQueue(D))
    {
        if(T1->Left!=NULL) enQueue(T1->Left->Key,&D);
        if(T1->Right!=NULL) enQueue(T1->Right->Key,&D);
        printf("%d ",T1->Key);
        if(!emptyQueue(D))
        {
			deQueue(&D);
        	T1=Search(front(D),T);
        }
    }
}
void insertNode(int x, Tree *pT)
{
	if((*pT) == NULL)
	{
		(*pT) = (struct Node*)malloc(sizeof(struct Node));
		(*pT)->Key = x;(*pT)->Left = NULL;(*pT)->Right = NULL;
	}
	else if((*pT)->Key == x)printf("Da ton tai khoa x");
	else if((*pT)->Key > x)insertNode(x,&(*pT)->Left);
	else insertNode(x,&(*pT)->Right);
}
void NLR(Tree T)
{
	if(T!=NULL) printf("%d ",T->Key);
	if(T->Left!=NULL) NLR(LeftChild(T));
	if(T->Right!=NULL) NLR(RightChild(T));
}
void LNR(Tree T)
{
	if(T->Left!=NULL) LNR(LeftChild(T));
	if(T!=NULL) printf("%d ",T->Key);
	if(T->Right!=NULL) LNR(RightChild(T));
}
int main()
{
	int x,a1=0;
	do
	{
    	Tree T=NULL;
    	do
    	{
    		printf("insert node: ");
    		scanf("%d",&x);
    		insertNode(x,&T);
			printf("Width browse:\n   ");
    		width_browse(T);
    		printf("\n\nNLR: ");
    		NLR(T);
    		printf("\nLNR: ");
    		LNR(T);
    		printf("\n\n1. insert         2. reset tree         3. exit\nchoose: ");
    		do
    		{
    			scanf("%d",&a1);
    			fflush(stdin);
    			if(a1>3||a1<1) printf("Error, please try again!\nchoose: ");
    		}while(a1>3||a1<1);
    		if(a1==1||a1==2) system("cls");
    	} while(a1==1);
    }while(a1==2);
}