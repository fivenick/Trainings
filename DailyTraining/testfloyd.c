/*************************************************************************
    > File Name: testfloyd.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月13日 星期三 06时55分52秒
 ************************************************************************/

#include<stdio.h>
#define MAX  1000
int edge[10][10];
int main(){
	int nodeNum,edgeNum;
	int index=0,jindex=0,kindex=0;
	scanf("%d %d",&nodeNum,&edgeNum);
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
		edge[start-1][end-1]=len;
	}
	for(index=0;index<nodeNum;++index){
		for(jindex=0;jindex<nodeNum;++jindex){
			for(kindex=0;kindex<nodeNum;++kindex){
				int tmpLen=edge[jindex][index]+edge[index][kindex];
				if(tmpLen<edge[jindex][kindex])
					edge[jindex][kindex]=tmpLen;
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
