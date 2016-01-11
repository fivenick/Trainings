/*************************************************************************
    > File Name: floyd.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月07日 星期四 07时12分49秒
 ************************************************************************/

#include<stdio.h>
#define LARGE 100
int main(){
	int nodeNum,edgeNum;
	int edge[10][10];
	scanf("%d %d",&nodeNum,&edgeNum);
	int index=0,jindex=0,xindex=0,yindex=0;
	for(index=0;index<nodeNum;++index){
		for(jindex=0;jindex<nodeNum;++jindex){
			if(index == jindex)
				edge[index][jindex]=0;
			else
				edge[index][jindex]=LARGE;
		}
	}
    for(index=0;index<edgeNum;++index){
		int start,end,len;
		scanf("%d %d %d",&start,&end,&len);
		edge[start-1][end-1]=len;
	}
	for(index=0;index<nodeNum;++index){
		for(xindex=0;xindex<nodeNum;++xindex){
			for(yindex=0;yindex<nodeNum;++yindex){
				int tmpLen=edge[xindex][index]+edge[index][yindex];
				if(edge[xindex][yindex]>tmpLen)
					edge[xindex][yindex]=tmpLen;
			}
		}
	}
	for(index=0;index<nodeNum;++index){
		for(jindex=0;jindex<nodeNum;++jindex){
			printf("%d ",edge[index][jindex]);
		}
		printf("\n");
	}
}
