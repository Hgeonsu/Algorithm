//Kruskal -> union-find 이용
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getParent(int parent[], int node){
	if(parent[node] == node)return node;
	return parent[node] = getParent(parent, parent[node]);
}
void unionParent(int parent[], int first, int second){
	//parent 값이 작은 쪽으로 합친다
	if(getParent(parent, first) > getParent(parent, second)){
		parent[first] = parent[second];
	}else{
		parent[second] = parent[first];
	}
}
int find(int parent[], int first, int second){
	if(parent[first] == parent[second]){
		return 1;
	}else{
		return 0;
	}
}
class Edge{
	public:
		int node[2]; //노드 두 개
		int distance; // 거리(비용)
		Edge(int first, int second, int distance){
			this->node[0] = first;
			this->node[1] = second;
			this->distance = distance;
		}
		bool operator <(Edge &edge){
			return this->distance < edge.distance;
		}
};
int main(void){
	const int number = 7; //node 7개 
	int parent[number + 1]; // index 1~7까지 활용하려고
	for(int i = 1 ; i <= number; i++ ){
		parent[i] = i; //초기 그래프는 자신 혼자이기 때문에 부모도 자기 자신 
	}
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12)); //생성자 함수에 접근하는 거니까 이런식으로 넣는 게 맞는듯
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(5, 7, 73));
	v.push_back(Edge(4, 2, 24));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 3, 20));
	v.push_back(Edge(6, 3, 37));
	sort(v.begin(), v.end());
	int sum = 0; 
	for(int i = 0; i < v.size() ; i++){
		if(!find(parent, v[i].node[0], v[i].node[1])){
			unionParent(parent, v[i].node[0], v[i].node[1]);
			sum += v[i].distance;
		}
	}
	printf("cost : %d ", sum);
	return 0;
} 
