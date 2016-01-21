/*************************************************************************
    > File Name: testprim.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月19日 星期二 11时01分27秒
 ************************************************************************/

#include<stdio.h>
#define MIN 1000
int edge[20][20];
int main(){
	int least[10],tag[10],father[10];
	int index=0,jindex=0;
	int start=0,end=0,len=0;
	int nodeNum=0,edgeNum=10;

	for(index=0;index<20;++index){
		for(jindex=0;jindex<20;++jindex){
			if(index == jindex){
				edge[index][jindex]=0;
				edge[jindex][index]=0;
			}else{
				edge[index][jindex]=MIN;
				edge[jindex][index]=MIN;
			}
		}
	}
	for(index=0;index<10;++index){
		scanf("%d %d %d",&start,&end,&len);
		edge[start-1][end-1]=len;
		edge[end-1][start-1]=len;
		if(start > nodeNum)
			nodeNum=start;
		if(end > nodeNum)
			nodeNum=end;
	}
	least[0]=0;
	tag[0]=1;
	father[0]=0;
    for(index=1;index<nodeNum;++index){
		least[index]=edge[0][index];
		tag[index]=0;
		father[index]=0;
	}
	for(index=1;index<nodeNum;++index){
		int tmpMin=MIN;
		int minIndex=0;
		for(jindex=0;jindex<nodeNum;++jindex){
			if((tag[jindex] == 0)&&(least[jindex]<tmpMin)){
				tmpMin=least[jindex];
				minIndex=jindex;
			}
		}
		tag[minIndex]=1;
		for(jindex=0;jindex<nodeNum;++jindex){
			if((tag[jindex] == 0)&&(least[jindex] > edge[minIndex][jindex])){
				least[jindex]=edge[minIndex][jindex];
				father[jindex]=minIndex;
			}
		}
	}
	for(index=1;index<nodeNum;++index){
		printf("%d %d",index,father[index]);
		printf("\n");
	}
}
