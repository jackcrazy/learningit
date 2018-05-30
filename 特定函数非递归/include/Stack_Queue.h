/*Stack and Queue define and basic operate*/
#ifndef _Stack_Queue_H_
#define _Stack_Queue_H_
#define ElemType int
//Stack 
typedef struct s1{
	ElemType data[Maxsize];
    int top;
}Stack;
bool InitStack(Stack *S);
bool EmptyStack(Stack S);
int StackOverflow(Stack S);
int GetStack(Stack S,ElemType *x);
int ClearStack(Stack *S);
int Push(Stack *S,ElemType x);
int Pop(Stack *S,ElemType *x);

#endif
