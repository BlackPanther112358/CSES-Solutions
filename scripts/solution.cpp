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
	int n , m;
	cin >> n >> m;
	vector<int> v(n);
	rep_u(i, 0, n) cin >> v[i];

	// dp[i][x] = number of ways to get value of x at index i
	// We will optimize space complexity by storing only value of x at last row.
	vector<int> dp(m, 0);
	// Base case: if first value is 0, then we can get any value from 1 to m, else we can get only value v[0]
	if(v[0] == 0) rep_u(i, 0, m) dp[i] = 1;
	else dp[v[0] - 1] = 1;

	// Iterating over all indices of array
	rep_u(i, 1, n){
		// Store the previous row and initialize current row to 0
		vector<int> temp = dp;
		dp.assign(m, 0);
		// If value at current index is 0, then we can get any value from 1 to m
		if(v[i] == 0){
			rep_u(j, 0, m){
				dp[j] += temp[j];
				if(j > 0) dp[j] += temp[j - 1];
				if(j < m - 1) dp[j] += temp[j + 1];
				dp[j] %= mod;
			}
		// Else we can get only value v[i]
		}else{
			dp[v[i] - 1] += temp[v[i] - 1];
			if(v[i] > 1) dp[v[i] - 1] += temp[v[i] - 2];
			if(v[i] < m) dp[v[i] - 1] += temp[v[i]];
			dp[v[i] - 1] %= mod;
		}
	}

	// Answer is sum of all values in last row
	int ans = 0;
	rep_u(i, 0, m) ans = (ans + dp[i]) % mod;
	cout << ans << nline;

	// TIME COMPLEXITY: O(n * m)
	// SPACE COMPLEXITY: O(m)

    return 0;

}