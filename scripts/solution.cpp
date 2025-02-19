// Exponentiation II
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int

const int mod = 1000000007;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

int bin_exp(int x, int y, int m){
    int res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef BlackPanther112358
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int n;
    cin >> n;
    while(n--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << bin_exp(a, bin_exp(b, c, mod - 1), mod) << endl;
    }

	// TIME COMPLEXITY: O(n*log(b)*log(c))
	// SPACE COMPLEXITY: O(1)

    return 0;

}