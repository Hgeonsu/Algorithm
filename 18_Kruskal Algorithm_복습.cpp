//Kruskal -> union-find �̿�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getParent(int parent[], int node){
	if(parent[node] == node)return node;
	return parent[node] = getParent(parent, parent[node]);
}
void unionParent(int parent[], int first, int second){
	//parent ���� ���� ������ ��ģ��
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
		int node[2]; //��� �� ��
		int distance; // �Ÿ�(���)
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
	const int number = 7; //node 7�� 
	int parent[number + 1]; // index 1~7���� Ȱ���Ϸ���
	for(int i = 1 ; i <= number; i++ ){
		parent[i] = i; //�ʱ� �׷����� �ڽ� ȥ���̱� ������ �θ� �ڱ� �ڽ� 
	}
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12)); //������ �Լ��� �����ϴ� �Ŵϱ� �̷������� �ִ� �� �´µ�
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
