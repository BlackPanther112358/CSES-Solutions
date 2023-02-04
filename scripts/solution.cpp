// Money Sums
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
    vector<int> coins(n);
    rep_u(i, 0, n) cin >> coins[i];

    // dp[i] = 1 if we can make sum i using the coins else 0
    vector<bool> dp(sum_all(coins) + 1, false);
    // We can make sum 0 using no coins
    dp[0] = true;

    // We must use each coin atmost once, thus we iterate over the coins
    rep_u(i, 0, n){
        // We store the previous dp array before updating it
        vector<bool> temp = dp;
        // We update the dp array for all the sums that can be made using the current coin
        rep_u(j, 1, sz(dp)){
            // We can make sum j using the current coin if we can make sum j - coins[i] using the coins before the current coin
            if(j >= coins[i]) dp[j] = temp[j] || temp[j - coins[i]];
        }
    }

    // Outputting the answer
    vector<int> ans;
    rep_u(i, 1, sz(dp)) if(dp[i]) ans.pb(i);
    cout << sz(ans) << nline;
    for(auto x: ans) cout << x << " ";
    
	// TIME COMPLEXITY: O(n*sum(coins)))
	// SPACE COMPLEXITY: O(n)

    return 0;

}