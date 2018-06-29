#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Max_Vertex_Num 100
#define VRType int
#define Infotype int
typedef struct S2{
	char name[30]; 
	int number; 
}VerType;  //city
typedef struct ArcCell{
     VRType adj; //address
     Infotype *info;  //infomation
}ArcCell ,AdjMatrix[Max_Vertex_Num][Max_Vertex_Num];   //address
typedef struct S1{
	VerType vexs[Max_Vertex_Num];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

void Create(MGraph *G){
	int n;  //city count
	int i,j;
	char ch;
	printf("Please input some infomation to connect the city\n");
	printf("Please scan the city name,if you don't want to scan,you can input the 'Z' \n");
	ch='0';
	G->vexnum=0;  //Init
	i=0;
	while(ch!='Z'){
		scanf("%s",string);
		if(strlen(string)>2){
			strcpy(G->vexs[i].name,string);
			G->vexs[i].number=i++;
		}
		else 
			printf("Input errror,Please scan again \n");
		ch=getchar();
	}
	printf("The scan of city name is over,next you need to scan the address from a city to another, like stringa <65> stringb\n" );
    printf("The Over is the same to 'Z'\n");
    ch='0';
    while(ch!='Z'){
    	//scanf("%s %c%d%c %s",)
    }    

}
int main(){
    MGraph G;
    Create(&G);

	return 0;
}