#include <stdio.h>
#include <stdlib.h>
#define weight int
#define Max 50

typedef struct S1
{  
	weight info;
	struct  S1 *lchild,*rchild;
	struct  S1 *next;
}WNode ,*WN;

void Sort(int wdata[],int n){  //weight data sort
	int i,j;
	int min,k;
	for(i=0;i<n;i++){
		min=wdata[i];
		for(j=i+1;j<n;j++)
			if(min>wdata[j]){
				min=wdata[j];
				k=j;
			}
		min=wdata[i];
		wdata[i]=wdata[k];
		wdata[k]=min;
	}
}

WN CreaHfmanTree(int wdata[],int n){    
	VN *T1,*T2,*T,*Tail,*p,*pre;
	int i,j;
	int Node1,Node2;
	Tail=(VN)malloc(sizeof(VNode));
	Tail->next=0;
	while(1){
		Sort(wdata,n);  //sort
		i=0;
		T1=0;
		T2=0;
		while(wdata[i]!=-1 && i<n) i++;  //weight data find the 2 minest data
		if(i==n-1) return Tail->next;
        Node1=i;
        Node2=i+1;
        pre=Tail;          // the Node in front of p
        p=Tail->next;   //if the Node1 or Node2 is in the Tail,give the T1 or T2;
        while(p){
        	if(wdata[Node1]==p->info){
        		pre->next=p->next;
        		T1=p;
        	}
        	else if(wdata[Node2]==p->info){
        		pre->next=p->next;
        		T2=p;
        	}
        	pre=p;
        	p=p->lchild;
        }
        if(T1==0)
        T1=(VN)malloc(sizeof(VNode));T1->info=wdata[Node1];T1->next=0;
        if(T2==0)
        T2=(VN)malloc(sizeof(VNode));T2->info=wdata[Node2];T2->next=0;
        T=(VN)malloc(sizeof(VNode));T->next=0;
        T->lchild=T1;
        T->rchild=T2;
        T->info=T1->info+T2->info;
        if(Tail->next==0)   //the new node insert into the Tail
        	Tail->next=T;
        else {
        	T->next=Tail->next;
        	Tail->next=T;
        }
        wdata[Node1]=-1;
        wdata[Node2]=T->info;
	}


}

int main(){

    WN *T;   //Tree first node
    int n;  //weight
    int wdata[Max];
    int i;
    scanf("%d",&n); 
    for(i=0;i<n;i++)
    	scanf("%d",&wdata[i]);
    T=CreaHfmanTree(wdata,n);

	return 0;
}