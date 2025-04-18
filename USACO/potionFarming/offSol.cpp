#include <iostream>
#include <vector>
 
const int MAXN = 200005;

int N;
std::vector<int> adj[MAXN];
int at[MAXN];
int p[MAXN];
int par[MAXN];
 
void input () {
    std::freopen("input.in", "r", stdin);
    std::freopen("txt.out", "w", stdout);
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b; std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}
 
void dfs (int v) {
	for (auto &u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			dfs(u);
		}
	}
}
 
void proc () {
	int L = 0;
	for (int i = 2; i <= N; i++) {
		L += (int(adj[i].size()) == 1);
	}
	for (int i = 0; i < L; i++) {
		at[p[i]]++;
	}
}
 
bool grab (int v) {
	while (v > 0) {
		if (at[v] > 0) {
			at[v]--;
			return 1;
		}
		v = par[v];
	}	
	return 0;
}
 
int solve () {
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (int(adj[i].size()) == 1) {
			ans += grab(i);
		}
	}
	return ans;
}
 
int main () {
	input();
	proc();
	dfs(1);
	std::cout << solve() << std::endl;
}