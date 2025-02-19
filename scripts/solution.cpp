// Counting Divisors
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int

const int mod = 1000000007;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef BlackPanther112358
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    int N = 1e6;
    vector<int> div_cnt(N + 1, 0);
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            div_cnt[j]++;
        }
    }

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << div_cnt[x] << endl;
    }

	// TIME COMPLEXITY: O(xlog(x) + n)
	// SPACE COMPLEXITY: O(x)

    return 0;

}