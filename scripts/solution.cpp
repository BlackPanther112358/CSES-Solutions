// Ferris Wheel
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
    vector<int> a(n);
    rep_u(i, 0, n) cin >> a[i];

    // Sorting the array
    sort(all(a));

    // Using 2 pointers from both ends to find valid pairs of children such that 
    // their weights are less than or equal to x
    int i = 0, j = n - 1, ans = 0;
    while(i <= j){
        // If the sum of weights of the children is less than or equal to x,
        if(a[i] + a[j] <= x){
            i++;
            j--;
        }
        // Else, we can only take the heavier child
        else j--;
        ans++;
    }

    // Printing the answer
    cout << ans << nline;
	
	// TIME COMPLEXITY: O(n*log(n))
	// SPACE COMPLEXITY: O(n)

    return 0;

}