#include <stdio.h>
#include <stdlib.h>
#include "bool.h"
#define  ElemType int
#define  Maxsize 50
typedef struct s1{
	ElemType data[Maxsize];
    int top;
}Stack;

// use 2 Stack to imitate Queue;
//Stack basic operate
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


//implement function as like
int Enqueue(Stack *S1,Stack *S2,int x){
	int y;
	if(!StackOverflow(*S1)){
		Push(S1,x);
	    return true;
	}
	else if(StackOverflow(*S1)&&!EmptyStack(*S2)){
		printf("The Queue is fulled");
		return false;
	}
	else if(EmptyStack(*S2)){
		while(!EmptyStack(*S1)){
			Pop(S1,&y);
			Push(S2,y);
		}
		Push(S1,x);
	}
	return true;
}
int DeQueue(Stack *S1,Stack *S2,int *x){
	int y;
	if(!EmptyStack(*S2)){
		Pop(S2,x);
		return true;
	}
	else if(EmptyStack(*S2)&&!EmptyStack(*S1)){
		while(!EmptyStack(*S1)){
			Pop(S1,&y);
			Push(S2,y);
		}
		Pop(S2,x);
		return true;
	}
	else if(EmptyStack(*S1)&&EmptyStack(*S2)){
		printf("The Queue is clean.");
		return false;
	}
}
int EmptyQueue(Stack S1,Stack S2){
	if(EmptyStack(S1)&&EmptyStack(S2))
		return true;
	else 
		return false;
}
int main(){
    
    Stack S1,S2;
    int data[10]={0,1,4,5,32,4,7,8,0,10};
    int i;
    int x;
    InitStack(&S1);InitStack(&S2);
    for(i=0;i<10;i++){
    	Enqueue(&S1,&S2,data[i]);
    }

    for(i=0;i<10;i++){
    	DeQueue(&S1,&S2,&x);
        printf("%d ",x);
    }
    printf("\n");
	return 0;
}