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

int l, timer = 0;
// Store the time of entry and exit of each node to calculate the LCA
vector<int> tin, tout;
// Adjacency list for the tree
vector<vector<int>> adj;
// Store the 2^i th parent of each node for binary lifting
vector<vector<int>> up;

// Function to calculate the 2^i th parent of each node
void calc_up(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    rep_u(i, 1, l + 1){
        // The 2^i th parent of a node is the 2^(i-1) th parent of the 2^(i-1) th parent of the node
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int u: adj[v]){
        if(u != p){
            calc_up(u, v);
        }
    }
    tout[v] = ++timer;
}

// Function to calculate the k th parent of a node
int solve(int v, int k){
    // If k is 0, then the k th parent of the node is the node itself
    if(k == 0) return v;
    // Find the maximum i such that 2^i <= k
    int i = 63 - clz(k);
    // The k th parent of the node is the k - 2^i th parent of the 2^i th parent of the node
    return solve(up[v][i], k - (1LL << i));
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
	int n, q;
    cin >> n >> q;
    // Store the maximum length we can jump while binary lifting
    l = ceil(log2(n));
    tin.resize(n + 1);
    tout.resize(n + 1);
    adj.resize(n + 1);
    up.resize(n + 1, vector<int>(l+1));

    rep_u(i, 2, n + 1){
        int x;
        cin >> x;
        adj[x].pb(i);
    }

    // We use 0 as an extra node to represent the supposed parent of the root node
    calc_up(1, 0);

    rep(q){
        int x, k;
        cin >> x >> k;
        int res = solve(x, k);
        // If the k th parent of the node is not the 0 node, then print -1
        cout << (res ? res : -1) << nline;
    }
    
	// TIME COMPLEXITY: O(n*log(n) + q*log(n))
	// SPACE COMPLEXITY: O(n*log(n))

    return 0;

}