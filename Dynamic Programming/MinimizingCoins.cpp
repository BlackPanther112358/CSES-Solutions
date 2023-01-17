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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    rep_u(i, 0, n) cin >> coins[i];

    // Making a dp array
    // dp[i] = minimum number of coins required to make sum i
    vector<int> dp(x + 1, inf);
    // Base case: 0 coins required to make sum 0
    dp[0] = 0;

    // Iterating over all possible sums
    rep_u(i, 1, x + 1){
        // Iterating over all coins
        rep_u(j, 0, n){
            // If the current coin is less than the current sum and dp[i - coins[j]] is not inf
            if((coins[j] <= i) && (dp[i - coins[j]] != inf)){
                // Obtain dp[i] using dp[i - coins[j]] + coins[j]
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Ouput the answer
    // If dp[x] is inf, then no solution exists
    if(dp[x] == inf) cout << -1 << nline;
    else cout << dp[x] << nline;

    return 0;

}