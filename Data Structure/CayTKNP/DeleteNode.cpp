#include<stdio.h>
#include<math.h>
struct Node
{
	int Key;
	struct Node *Left,*Right;
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
int deleteMin(Tree *T)
{
    int k;
    if((*T)->Left==NULL)
    {
        k=(*T)->Key;
        (*T)=(*T)->Right;
        return k;
    }
    else return deleteMin(&(*T)->Left);
}
void deleteNode(int x, Tree*pT)
{
	if((*pT)!=NULL) //Kiem tra cay khac rong
	if(x <(*pT)->Key) //Hy vong x nam ben trai cua nut
	deleteNode(x,&(*pT)->Left);
	else
	if(x >(*pT)->Key) //Hy vong x nam ben phai cua nut
	deleteNode(x,&(*pT)->Right);
	else// Tim thay khoa x tren cay
	if(((*pT)->Left==NULL)&&((*pT)->Right==NULL))//x la nut la
	(*pT)=NULL; // Xoa nut x
	else// x co it nhat mot con
	if((*pT)->Left==NULL) //Chac chan co con phai
	(*pT) = (*pT)->Right;
	else
	if((*pT)->Right==NULL) //Chac chan co con trai
	(*pT) = (*pT)->Left;
	else// x co hai con
	(*pT)->Key = deleteMin(&(*pT)->Right);}
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
void inOrder(Tree T)
{
	if(T->Left!=NULL) inOrder(LeftChild(T));
	printf("%d ",T->Key);
	if(T->Right!=NULL) inOrder(RightChild(T));
}
int main()
{
	Tree T=NULL;
	int x;
	insertNode(27,&T);
	insertNode(12,&T);
	insertNode(40,&T);
	insertNode(4,&T);
	insertNode(20,&T);
	insertNode(34,&T);
	insertNode(30,&T);
	insertNode(50,&T);
	scanf("%d",&x);
	deleteNode(x, &T);
	inOrder(T);
}