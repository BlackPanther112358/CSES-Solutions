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
	vector<string> v(n);
	rep_u(i, 0, n) cin >> v[i];

	// Creating a dp array
	// dp[i][j] = number of paths to reach i, j
	// Transition: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
	// Thus we only need to store the last row
	vector<int> dp(n, 0);
	// Base case: 1 path to reach (0, 0)
	if(v[0][0] == '.') dp[0] = 1;
	// For the first row, we can only reach (0, j) from (0, j - 1)
	rep_u(i, 1, n) if(v[0][i] == '.') dp[i] = dp[i - 1];
	
	// For the rest of the rows
	rep_u(i, 1, n){
		// Copy the previous array and save dp into it
		vector<int> temp = dp;
		dp.assign(n, 0);
		// For first column, we can only reach (i, 0) from (i - 1, 0)
		if(v[i][0] == '.') dp[0] = temp[0];
		rep_u(j, 1, n){
			// If the current cell has a trap, then dp[i][j] = 0
			if(v[i][j] == '*') continue;
			// Else, dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
			dp[j] = (dp[j - 1] + temp[j]) % mod;
		}
	}

	// Print the answer
	cout << dp[n - 1] << nline;

	// TIME COMPLEXITY: O(n ^ 2)
	// SPACE COMPLEXITY: O(n)


    return 0;

}