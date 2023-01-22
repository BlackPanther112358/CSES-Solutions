// Removal Game
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

	// dp[i][j] = Best score of both players when array is a[i...j]
	// Iterate using Top up DP approach on lenght of array
	// Can optimize space complexity to O(n) as we only store dp[i][j] and dp[i][j+1] at any time
	vector<pair<int, int>> dp;
	// Base case: dp[i][i] = a[i] for first player and 0 for second player
	rep_u(i, 0, n) dp.pb(mp(a[i], 0));

	// Iterate over length of array
	rep_u(i, 2, n + 1){
		// Store the previous dp array in temp
		vector<pair<int, int>> temp = dp;
		dp.clear();
		// Iterate using sliding window of length i
		rep_u(j, 0, n - i + 1){
			// Player 1 can choose a[j] or a[j + i - 1] and then best scores of both players are stored in dp[j + 1] and dp[j] respectively 
			dp.pb(max(mp(a[j] + temp[j + 1].second, temp[j + 1].first), mp(a[j + i - 1] + temp[j].second, temp[j].first)));
		}
	}

	// Answer is net score of game when array is a[0...n-1]
	cout << dp[0].first;

	// TIME COMPLEXITY: O(n^2)
	// SPACE COMPLEXITY: O(n)

    return 0;

}