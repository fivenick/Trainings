/*************************************************************************
    > File Name: testdij.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月13日 星期三 07时12分14秒
 ************************************************************************/

#include<stdio.h>
#define MAX 1000
int edge[10][10];
int dis[10];
int sawTag[10];
int pre[10];
void printPath(int proNode){
	if(proNode == -1)
		return;
	printPath(pre[proNode]);
	printf("%d->",proNode);
}
int main(){
	int nodeNum,edgeNum;
	int index=0,jindex=0,kindex=0;
	scanf("%d %d",&edgeNum,&nodeNum);
	for(index=0;index<nodeNum;++index){
		for(jindex=0;jindex<nodeNum;++jindex){
			if(index == jindex)
				edge[index][jindex]=0;
			else
				edge[index][jindex]=MAX;
		}
	}
	for(index=0;index<edgeNum;++index){
		int start,end,len;
		scanf("%d %d %d",&start,&end,&len);
		edge[start][end]=len;
	}
	dis[0]=0;
	sawTag[0]=1;
	pre[0]=-1;
	for(index=1;index<nodeNum;++index){
		dis[index]=edge[0][index];
		sawTag[index]=0;
		pre[index]=0;
	}
	for(index=1;index<nodeNum;++index){
		int tmpLen=MAX,minTag=0;
		for(jindex=1;jindex<nodeNum;++jindex){
			if((sawTag[jindex]==0) && (dis[jindex]<tmpLen)){
				tmpLen=dis[jindex];
				minTag=jindex;
			}
		}
		sawTag[minTag]=1;
		for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex]==0){
			    int tmpMinLen=tmpLen+edge[minTag][jindex];
				if(tmpMinLen<dis[jindex]){
					dis[jindex]=tmpMinLen;
					pre[jindex]=minTag;
				}
			}
		}
	}
	printf("%d\n",dis[nodeNum-1]);
    printPath(pre[nodeNum-1]);
	printf("%d\n",nodeNum-1);
}
