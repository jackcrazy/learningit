#include <stdio.h>
#include <stdlib.h>
#include "bool.h"
#include "Stack_Queue.h"


bool InitStack(Stack *S){
	S->top=-1;
	return true;
}
bool EmptyStack(Stack S){
	if(S.top==-1)
		return true;
	else 
		return false;
}
int StackOverflow(Stack S){
	if(S.top==Maxsize-1)
		return true;
	else 
		return false;
}
int GetStack(Stack S,ElemType *x){
	if(EmptyStack(S))
		return false;
	*x=S.data[S.top--];
	  return true;
}
int ClearStack(Stack *S){
    return true;
}
int Push(Stack *S,ElemType x){
	if(StackOverflow(*S)){
		printf("The Stack is fulled.");
		return false;
	}
	S->data[++S->top]=x;
	return true;
}
int Pop(Stack *S,ElemType *x){
	if(EmptyStack(*S)){
		printf("The Stack is Empty.");
		return false;
	}
	*x=S->data[S->top--];
	return true;
}


