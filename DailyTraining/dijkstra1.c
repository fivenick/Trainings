/*************************************************************************
    > File Name: dijkstra1.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月08日 星期五 11时07分50秒
 ************************************************************************/

#include<stdio.h>
#define LARGE 1000
int main(){
	int sawTag[10];
	int nodeNum,edgeNum;
	int edge[10][10];//不要用变量初始化数据，不然可能会发生未知的错误
	int resLen[10];
    scanf("%d %d",&edgeNum,&nodeNum);
	int index=0,jindex=0;
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
		edge[start][end]=len;
	}
	sawTag[0]=1;
	resLen[0]=0;
    for(index=1;index<nodeNum;++index){
		resLen[index]=edge[0][index];
	    sawTag[index]=0;
	}
	for(index=1;index<nodeNum;++index){
		int minLen=LARGE;
		int minTag=0;
		for(jindex=1;jindex<nodeNum;++jindex){
			if((sawTag[jindex]==0) && (minLen>resLen[jindex])){
			    minLen=resLen[jindex];	
				minTag=jindex;
			}
		}
		sawTag[minTag]=1;
		for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex]==0){
				int tmpLen=minLen+edge[minTag][jindex];
				if(tmpLen<resLen[jindex])
					resLen[jindex]=tmpLen;
			}
		}
	}
	printf("输出数据：");
	printf("\n");
	printf("原点到最后一个顶点的最短路径长度：%d\n",resLen[nodeNum-1]);
	int tmpSawTag=nodeNum-1;
	int stackBuf[10];
	int stackTag=0;
	while(tmpSawTag !=0){
		for(index=0;index<nodeNum;++index){
			if(((index == 0)||(tmpSawTag != index))&&(resLen[tmpSawTag] == (resLen[index]+edge[index][tmpSawTag]))){
				stackBuf[stackTag++]=index;
				tmpSawTag=index;
				break;
			}
		}
	}
	printf("原点到最后一个顶点的路径为：");
	for(index=stackTag-1;index>-1;--index){
		printf("%d->",stackBuf[index]);
	}
	printf("%d",nodeNum-1);
}
