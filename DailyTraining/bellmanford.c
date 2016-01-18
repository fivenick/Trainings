/*************************************************************************
    > File Name: bellmanford.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月13日 星期三 08时09分58秒
 ************************************************************************/

#include<stdio.h>
#define MAX 1000
typedef struct edge{
	int start;
	int end;
	int cost;
}edge;
int dis[10];
edge myEdge[10];
int main(){
	int nodeNum,edgeNum;
	int index=0,jindex=0,kindex=0;
	scanf("%d %d",&edgeNum,&nodeNum);
	for(index=0;index<nodeNum;++index){
		dis[index]=MAX;
	}
	dis[0]=0;
	for(index =0;index<edgeNum;++index){
		int start,end,len;
		scanf("%d %d %d",&myEdge[index].start,&myEdge[index].end,&myEdge[index].cost);
	}
	int tmpIndex=nodeNum-1;
	for(index=0;index<tmpIndex;++index){
		for(jindex=0;jindex<edgeNum;++jindex){
			int start=myEdge[jindex].start;
			int end=myEdge[jindex].end;
			int cost=myEdge[jindex].cost;
			if(dis[end]>dis[start]+cost)
				dis[end]=dis[start]+cost;
		}
	}
	printf("%d\n",dis[nodeNum-1]);
	
}
