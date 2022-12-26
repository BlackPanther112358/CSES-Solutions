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

void helper(int i, int j, int itr, int n, vector<int>& next_step){
    // After the iterating the last bit, we can store the result and return
    if(itr == n){
        next_step.pb(j);
        return;
    }
    // If the current bit is set, then we move to next bit
    if(i & (1<<itr)) helper(i, j, itr + 1, n, next_step);
    // If the current bit is not set, then we must set it
    else{
        // Using the 1x2 block
        helper(i, j | (1<<itr), itr + 1, n, next_step);
        // Using the 2x1 block
        if(((itr + 1) < n) && !(i & (1<<(itr + 1)))){
            helper(i, j, itr + 2, n, next_step);
        }
    }
    return;
}

vector<int> get_next_step(int i, int n){
    vector<int> next_step;
    helper(i, 0, 0, n, next_step);
    return next_step;
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

    // Take input for console
    int n, m;
    cin >> n >> m;

    vector<vector<int>> next_step((1<<n));
    rep_u(i, 0, (1<<n)) next_step[i] = get_next_step(i, n);

    // State: dp[i][j] = no. of ways to complete upto (i- 1)th column, with ith column having jth mask as filled blocks
    vector<vector<int>> dp(m + 1, vector<int>((1<<n), 0));
    // Base case: All columns are empty
    dp[0][0] = 1;

    // Iterate over all columns, after every iteration, ith column is filled
    rep_u(i, 0, m){
        // Iterate over all possible masks for ith column, and update possibilities for next column after filling ith column
        rep_u(j, 0, (1<<n)){
            for(auto k:next_step[j]){
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
            }
        }
    }

    // Answer is the no. of ways to complete all columns, such that last column didn't extend beyond the grid
    cout << dp[m][0] << nline;

    return 0;

}