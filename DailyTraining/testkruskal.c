/*************************************************************************
    > File Name: testkruskal.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月18日 星期一 07时49分15秒
 ************************************************************************/

#include<stdio.h>

int getRoot(int tmpNode,int tmpSet[]);
typedef struct edge{
	int start;
	int end;
	int len;
	struct edge* next;
	int tag;
}edge;
int nodeSet[10];
int main(){
	int nodeNum=0;
	int start=0,end=0,len=0;
	int index=0;
	edge* head=(edge*)malloc(sizeof(edge));
	head->next=NULL;
	for(index=0;index<10;++index){
		edge* tmp=malloc(sizeof(edge));
		scanf("%d %d %d",&start,&end,&len);
		tmp->start=start;
		tmp->end=end;
		tmp->len=len;
		tmp->tag=0;
		if(start > nodeNum)
			nodeNum=start;
		if(end > nodeNum)
			nodeNum=end;
		tmp->next=NULL;
		edge* former=head;
		edge* tempory=former->next;
		while((tempory != NULL)&&((tempory->len)<len)){
			former=tempory;
			tempory=tempory->next;
		}
		if(tempory != NULL){
			former->next=tmp;
			tmp->next=tempory;
		}else{
			former->next=tmp;
		}
	}
	for(index=0;index<=nodeNum;++index){
		nodeSet[index]=index;
	}
	int haveEdgeNum=0;
	edge* tmpEdge=head->next;
	while(haveEdgeNum < nodeNum){
		start=tmpEdge->start;
		end=tmpEdge->end;
		if(getRoot(start,nodeSet) == getRoot(end,nodeSet)){
			tmpEdge=tmpEdge->next;
		}else{
			int tmpRoot=getRoot(end,nodeSet);
			nodeSet[tmpRoot]=start;
			tmpEdge->tag=1;
			tmpEdge=tmpEdge->next;
			++haveEdgeNum;
		}

	}
	tmpEdge=head->next;
	while(tmpEdge != NULL){
		if(tmpEdge -> tag != 0){
			printf("%d %d %d\n",tmpEdge->start+1,tmpEdge->end+1,tmpEdge->len);
		}
		tmpEdge=tmpEdge->next;
	}
}
int getRoot(int tmpNode,int tmpSet[]){
	int root=tmpSet[tmpNode];
	while(root != tmpNode){
		tmpNode=root;
		root=tmpSet[tmpNode];
	}
	return root;
}
