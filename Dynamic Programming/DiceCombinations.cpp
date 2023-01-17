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

    // Make a dp array to store the number of ways to reach a particular sum
    vector<int> dp(n + 1, 0);
    // Base case: There is only one way to reach a sum of 0
    dp[0] = 1;

    // Iterate over all possible sums less than n
    rep_u(i, 1, n + 1){
        // Iterate over all possible coins
        rep_u(j, 1, 6 + 1){
            // If the current sum is greater than the current coin value
            if(i >= j){
                // Add the number of ways to reach the current sum - current coin value to the number of ways to reach the current sum
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }

    // Print the number of ways to reach a sum of n
    cout << dp[n];

    return 0;

}