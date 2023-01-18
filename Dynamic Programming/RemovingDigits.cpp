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

	// Creating a dp array
	// dp[i] = minimum steps to convert i to 0
	vector<int> dp(n + 1, inf);
	// Base case: 0 steps to convert 0 to 0
	dp[0] = 0;

	// Iterating over all the numbers from 1 to n
	rep_u(i, 1, n + 1){
		// Iterate over the digits of the number
		int temp = i;
		while(temp > 0){
			// Get the last digit
			int last_digit = temp % 10;
			// If the last digit is not 0
			if(last_digit != 0){
				// Update the dp array
				dp[i] = min(dp[i], dp[i - last_digit] + 1);
			}
			// Remove the last digit
			temp /= 10;
		}
	}

	// Print the answer
	cout << dp[n] << nline;

	// TIME COMPLEXITY: O(n * log(n))
	// SPACE COMPLEXITY: O(n)

    return 0;

}