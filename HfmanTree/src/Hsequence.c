#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100   //the counts of terminal must be in  50----->2n-1=Maxsize
#define Max 99999999
typedef struct S1{
	int lchild;
	int rchild;
	double weight;
	char ch;
	int parent;
}Node;


typedef struct S2{
	char ch;
	char string[Maxsize];
}CodeTable;
void scan(Node T[],int *n){
	int i,j;
	char ch;
	printf("please input the teminal Node counts\n");
	scanf("%d",n);
    printf("Please input counts data,like char;weight\n");
    getchar();
    for(i=0;i<*n;i++){
    	T[i].ch=getchar();
        getchar();   //absorb the ':'
    	scanf("%lf",&T[i].weight);
        T[i].parent=-1;
        T[i].lchild=T[i].rchild=-1;
        getchar();  //absorb the '\n'
    }
    for(;i<2*(*n);i++)
    	T[i].parent=-2;
}

void CreatHaffmanTree(Node T[],int n){
    int i,j;
    int node1;//mark the first found node 
    int node2; //the second
    int mv=n;
    double maxn;
    while(1){
    	i=0;
    	//find the minest weight
    	maxn=Max;
    	node1=-1;
    	node2=-1;
    	for(i=0;i<2*n;i++)
    		if(T[i].weight<maxn &&T[i].parent==-1){
    			node1=i;
    		maxn=T[i].weight;
    	    }
    	maxn=Max;
    	for(i=0;i<2*n;i++)
    		if(T[i].weight<maxn && i!=node1 && T[i].parent==-1){
    			node2=i;
    			maxn=T[i].weight;
    		}
    	if(node2==-1)
    		return ;
        //create a new node
    	T[mv].ch=' ';
    	T[mv].weight=T[node1].weight+T[node2].weight;
    	T[mv].lchild=node1;
    	T[mv].rchild=node2;
    	T[mv].parent=-1;

    	//deal with the node1 and node2
    	T[node1].parent=mv;
    	T[node2].parent=mv++;
    }
}



//coding 
void BuildCodeTable(Node T[],int n,CodeTable Code[]){
	Node *p=NULL;
	int mv=0;  //Code[]'s pointer
	int s; 
	int i,j;
	while(T[2*n-2].lchild!=-1 || T[2*n-2].rchild!=-1){
		p=&T[2*n-2];
		 //printf("%lf\n",p->weight);
		s=0;
		while(1){   //Loop output encoding
			if(p->lchild!=-1){    //left
				Code[mv].string[s++]='0';
				p=&T[p->lchild];
			}
			else if(p->ch!=' ' && T[T[p->parent].lchild].weight==p->weight){    //left terminal  node
				Code[mv].ch=p->ch;
				Code[mv].string[s++]='\0';
				T[p->parent].lchild=-1;
				break;
			}
			else if(p->rchild!=-1){   //right
				Code[mv].string[s++]='1';
				p=&T[p->rchild];
			}
			else if(p->ch!=' ' && T[T[p->parent].rchild].weight==p->weight){    //right terminal node 
				Code[mv].ch=p->ch;
				Code[mv].string[s++]='\0';
				T[p->parent].rchild=-1;
				break;
			}
			else if(p->lchild ==-1 && p->rchild == -1 && p->ch ==' ' ){    //find the untrue terminal node
				mv--;
				if(T[T[p->parent].lchild].weight==p->weight)
				    T[p->parent].lchild=-1;
			    else 
			    	T[p->parent].rchild=-1;
			    break;
			}
		}
		mv++;    //
	}

}
int main(){
    Node T[Maxsize];  
    CodeTable Code[Maxsize];
    int n,i;
    printf("------------------------------------------------------------------------\n");
    scan(T,&n);
    CreatHaffmanTree(T,n);
    
   	printf("---------------------The HaffmanTree in sequence------------------------\n");
    for(i=0;i<2*n-1;i++)
    	printf("%c;%.2lf;%d %d %d \n",T[i].ch,T[i].weight,T[i].parent,T[i].lchild,T[i].rchild);
	
	
	printf("---------------------The Coding Table----------------------------------\n");
	
	BuildCodeTable(T,n,Code);
	for(i=0;i<n;i++)
        printf("%c : %s\n",Code[i].ch,Code[i].string);
     
	return 0;
}