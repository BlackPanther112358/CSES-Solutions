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

// Store the final answer as global variable
int ans = 0;
vector<vector<int>> adj;

// We assume that u is the highest node in the diameter of the tree
// The diameter will be sum of the depths of the two farthest nodes from u
int dfs(int u, int p){
    // mx1 and mx2 will store the depths of the two farthest nodes from u
    int mx1 = 0, mx2 = 0;
    for(auto v: adj[u]){
        if(v != p){
            int d = dfs(v, u);
            if(d > mx1){
                mx2 = mx1;
                mx1 = d;
            }
            else if(d > mx2){
                mx2 = d;
            }
        }
    }
    // Updating the diameter of the tree
    ans = max(ans, mx1 + mx2);
    // Returning the depth of the farthest node from u
    return mx1 + 1;
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
    adj.resize(n);
    rep_u(i, 2, n + 1){
        int a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }

    // We can arbitrarily choose any node as the root in a tree
    // Thus setting node 1 as root, and parent -1
    dfs(0, -1);

    // Printing the diameter of the tree
    cout << ans << nline;
    
	// TIME COMPLEXITY: O(n)
	// SPACE COMPLEXITY: O(n)

    return 0;

}