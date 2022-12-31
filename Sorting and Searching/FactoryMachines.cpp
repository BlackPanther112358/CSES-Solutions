#include <bits/stdc++.h>
using namespace std;

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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep_u(i, 0, n) cin >> a[i];

    // We will Binary search on the answer to find the minimum time
    // If we assume the maximum time to make a product with 1 machine available and maximum possible products to be made, the answer will be 10^18
    // Thus we will search in the range [1, 10^18]

    int l = 1, r = 1e18;
    int ans = 0;

    while(l <= r){
        int mid = l + (r - l) / 2;
        // Counting the number of products that can be made in mid time
        int cnt = 0;
        rep_u(i, 0, n){
            cnt += mid / a[i];
            if(cnt >= t) break;
        }
        if(cnt >= t){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    // Output the answer
    cout << ans << nline;

    return 0;

}