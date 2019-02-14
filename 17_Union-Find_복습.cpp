#include<stdio.h>
int getParent(int parent[], int node){
	if(parent[node] == node){
		return node;
	}
	//return parent[node] = getParent(getParent(node));
	return parent[node] = getParent(parent, parent[node]);
}
void unionParent(int parent[], int a, int b){
	//parent를 작은쪽으로 합친다
	int first = getParent(parent, a);
	int second = getParent(parent, b);
	if(first < second){
		parent[b] = parent[a];
	}else{
		parent[a] = parent[b];
	}
}
int findParent(int parent[], int a, int b){
	if(getParent(parent, a) == getParent(parent, b)){
		return 1;
	}else{
		return 0;
	}
}
int main(void){
	int parent[11]; // index 1~11로 쓰려고
	//parent 를 자기 자신으로 초기화 
	for(int i = 1 ; i <= 10 ; i++){
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);//1, 2, 3, 4 연결 
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);//5, 6, 7, 8 연결 
	
	printf("1과 5는 연결되어있나? %d", findParent(parent, 1, 5));
	unionParent(parent, 4, 5);
	printf("\n1과 5는 연결되어있나? %d", findParent(parent, 1, 5));
	return 0;
}
