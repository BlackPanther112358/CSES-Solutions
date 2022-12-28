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

// Function to solve the question using digit DP
int solve(int n){

    if(n < 0) return 0;
    if(n == 0) return 1;

    // Converting the numbers to 18 length vectors
    vector<int> x;
    while(n){
        x.pb(n % 10);
        n /= 10;
    }
    n = sz(x);

    // dp[i][j] stores the number of ways to set ith digit of the number to j
    // 11th index stores the number of ways for upper limit, i.e. when the whole range is not to be considered
    vector<vector<int>> dp(n, vector<int>(11, 0));
    // Base case: number of ways to get units digit
    rep_u(i, 0, 10) dp[0][i] = 1;
    // Base case: number of ways to get 11th digit
    dp[0][10] = 1;

    // Calculating the number of ways for each digit
    rep_u(i, 1, n){
        // For each digit, we can set it to any number from 0 to 9
        rep_u(j, 0, 10){
            rep_u(k, 0, 10){
                // 2 adjacent digits cannot be same
                if(j == k) continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
        // Calculating the number of ways for the upper limit
        rep_u(j, 0, 10){
            if(j < x[i - 1]) {if(x[i] != j) dp[i][10] += dp[i - 1][j];}
            else if(j == x[i - 1]) {if(x[i] != j) dp[i][10] += dp[i - 1][10];}
            else break;
        }
    }

    // Finding and returning the answer
    int ans = 0;
    // Since we discarded consecutive 0's, we need to accomodate numbers, where they were leading 0's
    rep_u(i, 0, n - 2){
        if(i == 0){
            rep_u(j, 0, 10){
                ans += dp[i][j];
            }
        }
        else{
            rep_u(j, 1, 10){
                ans += dp[i][j];
            }
        }
    }
    // For last digit, we iterate from 0 to x[n - 1]
    rep_u(i, 0, 10){
        if(i < x[n - 1]) ans += dp[n - 1][i];
        else{
            ans += dp[n - 1][10];
            break;
        }
    }
    return ans;

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

    // Taking input from console
    int a, b;
    cin >> a >> b;
    // If input is 1e18, then we need not consider it in final answer and can work with 18 digit numbers
    if(a == 1e18) a--;
    if(b == 1e18) b--;

    // Calculating the answer
    cout << solve(b) - solve(a - 1) << nline;

    return 0;

}