/*************************************************************************
    > File Name: bellmanford.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年01月11日 星期一 09时33分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define EDGENUM  50
#define NODE  50
#define MAX 1000
typedef struct Edge{
	int u,v;
	int cost;
}Edge;
Edge edge[EDGENUM];
int dis[NODE],pre[NODE];
int edgeNum,nodeNum;
bool Bellman_Ford(){
	dis[0]=0;
	pre[0]=0;
	for(int i =1;i<nodeNum;++i){
		dis[i]=MAX;
	}
	for(int i=1;i<nodeNum;++i){
        for(int j=0;j<edgeNum;++j){
			int start=edge[j].u;
			int end=edge[j].v;
			int cost=edge[j].cost;
			int tmpCost=dis[start]+cost;
			if(tmpCost<dis[end]){
				dis[end]=tmpCost;
				pre[end]=start;
			}
		}
	}
	for(int i=0;i<edgeNum;++i){
        int start=edge[i].u;
		int end=edge[i].v;
		int cost=edge[i].cost;
		int tmpCost=dis[start]+cost;
		if(tmpCost<dis[end])
			return false;
	}
	return true;
}
void printPre(int tmpNode,int tag){
    if(tmpNode == 0){
		cout<<"0->";
		return ;
	}
	int preNum=pre[tmpNode];
	printPre(preNum,0);
	if(tag == 0)
    	cout<<tmpNode<<"->";
	else
		cout<<tmpNode<<endl;
}
int main(){
	cin>>edgeNum>>nodeNum;
	for(int i=0;i<edgeNum;++i){
		cin>>edge[i].u>>edge[i].v>>edge[i].cost;
	}
    Bellman_Ford();
	cout<<dis[nodeNum-1]<<endl;
	cout<<"路径是："<<endl;
	printPre(nodeNum-1,1);
}

