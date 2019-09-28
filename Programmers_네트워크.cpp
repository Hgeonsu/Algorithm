#include <string>
#include <vector>

using namespace std;
bool vis[201];
void dfs(int here, vector<vector<int>> &grp) {
	
	vis[here] = true;
	
	for (int i = 0; i < grp[here].size(); i++) {
		if (grp[here][i] == 0 || vis[i]) continue;
		dfs(i, grp);
	}
}
int solution(int n, vector<vector<int>> coms) {
	
	int ans = 0;
	for (int i = 0; i < coms.size(); i++) {
		if (!vis[i]) {
			ans++;
			dfs(i, coms);
		}
	}
	return ans;

	return 1;
}
