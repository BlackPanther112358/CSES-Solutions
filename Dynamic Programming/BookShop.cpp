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
	int n , x;
	cin >> n >> x;
	vector<int> h(n), s(n);
	rep_u(i, 0, n) cin >> h[i];
	rep_u(i, 0, n) cin >> s[i];

	// dp[i][j] stores the maximum pages that can be obtained using first (i + 1) books at j cost
	// We can opimize the space complexity by only using dp[j] as we only need the previous row
	vector<int> dp(x + 1, -1);
	// Base case: at 0 cost, we can get 0 pages
	dp[0] = 0;
	// Iterating over books
	rep_u(i, 0, n){
		// Creating a copy of the previous row
		vector<int> temp = dp;
		// Iterating over cost
		rep_u(j, h[i], x + 1) if(temp[j - h[i]] != -1) dp[j] = max(dp[j], temp[j - h[i]] + s[i]);
	}

	// Finding the maximum number of pages
	int max_num = 0;
	for(auto i : dp) max_num = max(max_num, i);
	cout << max_num;

	// TIME COMPLEXITY: O(n * x)
	// SPACE COMPLEXITY: O(x)


    return 0;

}