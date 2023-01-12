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
    int n, q;
    cin >> n >> q;
    vector<string> x(n);
    rep_u(i, 0, n) cin >> x[i];

    // Creating a prefix sum array to count number of trees
    // count[i][j] stores trees from (0, 0) to (i, j)
    vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));
    rep_u(i, 1, n + 1){
        rep_u(j, 1, n + 1){
            count[i][j] = count[i - 1][j] + count[i][j - 1] - count[i - 1][j - 1];
            if(x[i - 1][j - 1] == '*') count[i][j]++;
        }
    }

    // Processing queries
    rep(q){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << count[y2][x2] - count[y1 - 1][x2] - count[y2][x1 - 1] + count[y1 - 1][x1 - 1] << nline;
    }

    return 0;

}