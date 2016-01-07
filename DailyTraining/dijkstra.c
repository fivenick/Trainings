/*************************************************************************
    > File Name: dijkstra.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月07日 星期四 07时42分57秒
 ************************************************************************/

#include<stdio.h>
#define LARGE  1000
//void printBuf(int tmpBuf[],int len);
int main(){
	int nodeNum,edgeNum;
	int edge[10][10];
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

	printf("dddd");
    int resLen[nodeNum];
	int sawTag[nodeNum];
	resLen[0]=0;
	sawTag[0]=1;
	for(index=1;index<nodeNum;++index){
		resLen[index]=edge[0][index];
		sawTag[index]=0;
	}
	for(index=1;index<nodeNum;++index){
		printf("输出数据0");
	    int tmpMin=LARGE,minTag=0;
		for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex] == 0){
				if(resLen[jindex]<=tmpMin){
					tmpMin=resLen[jindex];
					minTag=jindex;
				}
			}
		}
		printf("输出数据-1");
		sawTag[minTag]=1;
		for(jindex=1;jindex<nodeNum;++jindex){
			if(sawTag[jindex] == 0){
				int tmpLen=resLen[minTag]+edge[minTag][jindex];
				if(tmpLen<resLen[jindex])
					resLen[jindex]=tmpLen;
			}
		}
		printf("输出数据1");
	}
		printf("输出数据2");
	
	printf("原点到最后一个顶点的路径长度：%d ",resLen[nodeNum-1]);
    int stack[10],stackTag=0;
	int calTag=nodeNum-1;
	while(calTag != 0){
		for(index=0;index<nodeNum;++index){
			if(resLen[index] == (resLen[calTag]-edge[index][calTag])){
				stack[stackTag]=index;
				++stackTag;
				calTag=index;
				break;
			}
		}
	}
	for(index=0;index<nodeNum;++index)
		printf("%d ",resLen[index]);
	printf("原点到最后一个顶点的路径为：");
	for(index=calTag-1;index>-1;--index){
		printf("%d->",stack[index]);
	}
	printf("%d",nodeNum-1);
}
void printBuf(int tmpBuf[],int tmpLen){
	int index=0;
	for(index=0;index<tmpLen;++index){
		printf("%d ",tmpBuf[index]);
	}
	printf("\n");
}
