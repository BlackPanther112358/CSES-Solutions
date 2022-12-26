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

    // Taking input from the console
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    rep_u(i, 0, n) cin >> w[i];

    // Creating the dp array
    // dp[i] = {min rides, min wieght on last ride} where i is the bitmask for the passengers
    vector<pair<int, int>> dp((1<<n), {inf, inf});
    // Base case as there is no passenger
    dp[0] = {0, x};

    // Iterating over all the possible bitmasks
    rep_u(i, 1, (1<<n)){
        rep_u(j, 0, n){
            // If the jth passenger is not present in the bitmask, do nothing
            if(!(i & (1<<j))) continue;
            // If the jth passenger is present , then process dp for the remaining passengers
            pair<int, int> val = dp[i ^ (1<<j)];
            val.second += w[j];
            // If the weight of the last ride exceeds the limit, then add a new ride
            if(val.second > x){
                val.first++;
                val.second = min(w[j], val.second - w[j]);
            }
            // Update the dp array
            dp[i] = min(dp[i], val);
        }
    }

    // Minimum number of rides required to transport all the passengers
    cout << dp[(1<<n) - 1].first << nline;

    /*
    Space Complexity: O(2^n)
    Time Complexity: O(2^n * n)
    */

    return 0;

}