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
	vector<int> a(n);
	rep_u(i, 0, n) cin >> a[i];

	// dp[i] stores the smallest value of the last element of an increasing subsequence of length i+1
	// Also, as a smaller length subsequence will always be a subsequence of a larger length subsequence, the value of dp[i] will always be smaller than dp[i+1]
	// Thus dp[i] is always increasing. This allows us to use binary search the maximum length of an increasing subsequence ending at a[i]
	vector<int> dp(n + 1, inf);
	rep_u(i, 0, n){
		// We need to find the smallest j, such that dp[j] >= a[i]
		// Thus, dp[j] (last element of an increasing subsequence of length j+1) is a[i]
		// This can be done using binary search
		int idx = lower_bound(all(dp), a[i]) - dp.begin();
		dp[idx] = a[i];
	}

	// Find the maximum length of an increasing subsequence
	// We also added an extra element to dp in case the entire array is an increasing subsequence
	rep_u(i, 0, n + 1){
		// If dp[i] is inf, then no increasing subsequence of length i+1 exists
		if(dp[i] == inf){
			cout << i << nline;
			break;
		}
	}

	// TIME COMPLEXITY: O(n*log(n))
	// SPACE COMPLEXITY: O(n)

    return 0;

}