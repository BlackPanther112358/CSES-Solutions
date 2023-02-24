// Course Schedule
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

int timer = 0;
vector<bool> visited;
vector<int> tin, tout;
vector<int> order;
vector<vector<int>> graph;

bool dfs(int u){
    // Mark the node as visited and assign it an entry time
    tin[u] = timer++;
    visited[u] = true;
    for(auto v: graph[u]){
        // If a node is visited but not exited yet, then there is a cycle in the graph
        if(visited[v] && tout[v] == -1) return false;
        if(!visited[v]){
            if(!dfs(v)) return false;
        }
    }
    tout[u] = timer++;
    // Add nodes to the topological sort in reverse order of their exit time
    order.pb(u);
    return true;
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
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    tin.resize(n, -1);
    tout.resize(n, -1);
    // Create a graph, if course A must be taken before course B, then make an edge from A to B
    rep(m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
    }

    // Thus, we can create a topological sort of the graph. 
    // If there is a cycle in the graph, then the topological sort will not be possible.
    rep_u(i, 0, n){
        if(visited[i]) continue;
        if(!dfs(i)){
            cout << "IMPOSSIBLE" << nline;
            return 0;
        }
    }

    // Reverse the topological sort to get the correct order of courses
    reverse(all(order));
    for(auto x: order) cout << x+1 << " ";
    cout << nline;

	// TIME COMPLEXITY: O(n + m)
	// SPACE COMPLEXITY: O(n + m)

    return 0;

}