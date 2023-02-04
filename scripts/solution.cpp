// Edit Distance
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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    // Making sure that s is the longer string
    if(n < m){
        swap(s, t);
        swap(n, m);
    }

    // dp[i][j] stores the edit distance between s[0...i] and t[0...j]
    vector<int> dp(m + 1, inf);
    // Base case
    // As s is currently empty, we need to delete all characters of t
    rep_u(i, 0, m + 1) dp[i] = i;

    rep_u(i, 1, n + 1){
        // Assign the previous row to temp
        vector<int> temp = dp;
        dp.assign(m + 1, inf);
        // For empty string t, we need to insert all characters of s
        dp[0] = i;
        rep_u(j, 1, m + 1){
            // We delete the current character of s
            dp[j] = min(dp[j], temp[j] + 1);
            // We insert the current character of t
            dp[j] = min(dp[j], dp[j - 1] + 1);
            // If current characters of s and t are same, we don't need to do anything
            if(s[i - 1] == t[j - 1]) dp[j] = min(dp[j], temp[j - 1]);
            // Else we replace the current character of s with the current character of t
            else dp[j] = min(dp[j], temp[j - 1] + 1);
        }
    }

    // Printing the answer
    cout << dp[m] << nline;
    
	// TIME COMPLEXITY: O(n*m)
	// SPACE COMPLEXITY: O(min(n, m))

    return 0;

}