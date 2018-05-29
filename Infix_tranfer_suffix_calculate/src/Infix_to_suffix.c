#include <stdio.h>
#include <stdlib.h>
#include "bool.h"
#include "Stack_Queue.h"

bool Estimate_character(char c){
	if(c>=48 && c<=57)
		return true;
	else 
		return false;
}
void Infix_to_suffix(char *str){
	Stack S1;
	char ch;
	char *p=str;
	char *q=p;
	InitStack(&S1);
	while(*p!='\0'){
	if(Estimate_character(*p)){
		*q=*p;
		q++;
	}
	else if(*p=='(' || *p=='[' || *p=='{' || EmptyStack(S1)){
		Push(&S1,*p);
	}
	else if(*p==')' || *p==']' || *p=='}'){
		switch(*p){
			case ')': Pop(&S1,&ch);while(!EmptyStack(S1) && ch!='('){
				*q=ch;
				q++;
				Pop(&S1,&ch);
			}
			break;
			case ']': Pop(&S1,&ch);while(!EmptyStack(S1) && ch!='['){
				*q=ch;
				q++;
				Pop(&S1,&ch);
			}
			break;
			case '}': Pop(&S1,&ch);while(!EmptyStack(S1) && ch!='{'){
				*q=ch;
				q++;
				Pop(&S1,&ch);
			}
			break;
		}

	}
	else {
		GetStack(S1,&ch);
		switch(*p){
			case '*':
			case '/':
			    if(ch!='*' || ch!='/') 
				Push(&S1,*p);
			    else {
			    	Pop(&S1,&ch);
			    	*q=ch;
			    	q++;
			    	p--;
			    }
				break;
			case '-':
			case '+':
			    if(ch=='(' || ch=='{' || ch=='[')
			    Push(&S1,*p);
			    else {
			    Pop(&S1,&ch);
			    *q=ch;
			    q++;
                p--;
			    }
                break;
		}
	}
    p++;
    }
    while(!EmptyStack(S1)){
    	Pop(&S1,&ch);
    	*q=ch;
    	q++;
    }
    *q='\0';
}

int main(){
	char *p;
	p=(char *)malloc(50*sizeof(char));
	scanf("%s",p);
	Infix_to_suffix(p);
	printf("%s",p);
	return 0;
}