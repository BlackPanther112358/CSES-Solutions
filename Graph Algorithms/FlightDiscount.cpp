#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<pair<int, int>>> adj(n);
    rep(m){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb({b, c});
    }

    // Using Dijkstra's Algorithm along with DP
    // dp[i][j] = minimum cost to reach node i, if j = 1 then we have used the coupon, else not
    vector<vector<int>> dp(n, vector<int>(2, inf));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Implementing Dijkstra's Algorithm
    dp[0][0] = dp[0][1] = 0;    // Base case
    pq.push({0, {0, 0}});
    pq.push({0, {0, 1}});
    while(!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second.first;
        bool c = pq.top().second.second;
        pq.pop();
        if(dp[u][c] < cost) continue;
        for(auto it: adj[u]){
            int v = it.first;
            int next_cost = it.second;
            // If we have not used the coupon yet, then we can use it
            if((c == 0) && (dp[v][1] > dp[u][0] + next_cost/2)){
                dp[v][1] = dp[u][0] + next_cost/2;
                pq.push({dp[v][1], {v, 1}});
            }
            // Continue with the same state as before w.r.t. coupon
            if(dp[v][c] > dp[u][c] + next_cost){
                dp[v][c] = dp[u][c] + next_cost;
                pq.push({dp[v][c], {v, c}});
            }
        }
    }

    // Outputting the answer
    cout << min(dp[n-1][0], dp[n-1][1]) << nline;

    return 0;

}