#include<stdio.h>
#include<math.h>
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
int contrainhat(int x, Tree T)
{
    if(T!=NULL)
    {
        if(T->Left!=NULL)
        {
            return contrainhat(x,LeftChild(T));
        }
        if(T->Key==x) return 1;
    }
    return 0;
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
Tree getPrevious(int x, Tree T)
{
    if(T!=NULL)
    {
        if(x<T->Key) return getPrevious(x,LeftChild(T));
        if(T->Key==x) return T->Left;
        if(contrainhat(x,RightChild(T))) return T;
        if(x>T->Key) return getPrevious(x,RightChild(T));
    }
    return NULL;
}
int main()
{
	Tree T=NULL;
	Tree p;
	int x;
	insertNode(27,&T);
	p=T;
	insertNode(12,&T);
	insertNode(40,&T);
	insertNode(4,&T);
	insertNode(20,&T);
	insertNode(34,&T);
	insertNode(30,&T); 
	insertNode(50,&T);
	scanf("%d",&x);
	p = getPrevious(x,T);
	if (p==NULL)
	   printf("%d khong co nut dung truoc",x);
	else printf("Nut dung truoc la %d",p->Key);
}