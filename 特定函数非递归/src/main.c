#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50
//redefine a struct
typedef struct S{
	int no;
	double val;
}Elemtype;

typedef struct P
{
	int top;
	Elemtype data[Maxsize];
}Staspe;

double Pn(int n,double x){
	Staspe st;
	st.top=-1;
	int i;
	double fv1=1,fv2=2*x;
    for(i=n;i>=2;i--){
    	st.data[++st.top].no=i;
    }
    while(st.top>=0){
    	st.data[st.top].val=2*x*fv2-2*(st.data[st.top].no-1)*fv1;
    	fv1=fv2;
    	fv2=st.data[st.top].val;
    	st.top--;
    }
    if(n==0)
    	return fv1;
    else 
    	return fv2;
}


int main(){
    int n;
    double m;
    while(scanf("%d%lf",&n,&m)!=-1){
    	m=Pn(n,m);
    	printf("%lf",m);
    }
	return 0;
}