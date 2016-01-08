/*************************************************************************
    > File Name: dijkstra2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月08日 星期五 13时17分43秒
 ************************************************************************/

#include<stdio.h>
#define LARGE 100
void printBuf(int tmpBuf[],int tmpStart);
int main(){
	int nodeNum,edgeNum;
	int sawTag[10],resLen[10],provBuf[10],edge[10][10],stackTag[10];
	int index=0,jindex=0;
	scanf("%d %d",&edgeNum,&nodeNum);
	for(index=0;index<nodeNum;++index)
		for(jindex=0;jindex<nodeNum;++jindex){
			if(index == jindex)
				edge[index][jindex]=0;
			else
				edge[index][jindex]=LARGE;
		}
	for(index =0;index<edgeNum;++index){
		int start,end ,len;
		scanf("%d %d %d",&start,&end,&len);
		edge[start][end]=len;
	}
	sawTag[0]=1;
	resLen[0]=0;
	provBuf[0]=-1;
	for(index=1;index<nodeNum;++index){
		sawTag[index]=0;
		resLen[index]=edge[0][index];
		provBuf[index]=0;
	}
	for(index=1;index<nodeNum;++index){
		int minLen=LARGE;
		int minTag=0;
		for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex]==0){
				if(resLen[jindex]<minLen){
					minLen=resLen[jindex];
					minTag=jindex;
				}
			}
		}
		sawTag[minTag]=1;
        for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex]==0){
				int tmpLen=minLen + edge[minTag][jindex];
				if(tmpLen<resLen[jindex]){
					provBuf[jindex]=minTag;
					resLen[jindex]=tmpLen;
				}
			}
		}
	}
	printf("输出数据：\n");
	printf("原点到最后一个顶点的最短路径长度：%d\n",resLen[nodeNum-1]);
    printBuf(provBuf,nodeNum-1);	
}
void printBuf(int tmpBuf[],int tmpStart){
	if(tmpStart == 0){
		printf("%d",0);
		return;
	}
	printBuf(tmpBuf,tmpBuf[tmpStart]);
	printf("->%d",tmpStart);
}
