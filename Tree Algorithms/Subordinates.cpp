#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int

const int mod = 1000000007;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

#define nline               "\n"
#define rep(xx)             for(int aa = 0; aa < xx; aa++)
#define rep_u(ii, aa, bb)   for(int ii = aa; ii < bb; ii++)
#define rep_d(ii, aa, bb)   for(int ii = aa; ii >= bb; ii--)
#define sz(x)               (int)x.size()
#define pb                  push_back
#define mp                  make_pair
#define all(x)              (x).begin(), (x).end()
#define sum_all(x)          accumulate(all(x), 0)
#define max_idx(x)          max_element(all(x)) - x.begin()
#define min_idx(x)          min_element(all(x)) - x.begin()
#define pcnt(x)             __builtin_popcountll(x)
#define clz(x)              __builtin_clzll(x)
#define ctz(x)              __builtin_ctzll(x)  
#define prec(x)             setprecision(x) << fixed

vector<int> ans;
vector<vector<int>> adj;

int dfs(int u){
	if(adj[u].size() == 0) return 0;
	int cnt = 0;
	for(auto v: adj[u]){
		// Find the number of subordinates of v and add it to cnt
		cnt += dfs(v) + 1;
	}
	ans[u] = cnt;
	return cnt;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef BlackPanther112358
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    // Taking input from console
	int n;
	cin >> n;
	vector<int> parent(n, 0);
	rep_u(i, 1, n) {cin >> parent[i]; parent[i]--;}

	// Creating adjacency list
	adj.resize(n);
	rep_u(i, 1, n) adj[parent[i]].pb(i);

	// We will use dfs to find the number of subordinates of each employee
	ans.resize(n, 0);
	// We will start dfs from the general manager of the company
	dfs(0);

	// Printing the answer
	rep_u(i, 0, n) cout << ans[i] << " ";

	// TIME COMPLEXITY: O(n)
	// SPACE COMPLEXITY: O(n)

    return 0;

}