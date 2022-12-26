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
    int n, k = 0;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    vector<int> ans(n);
    rep_u(i, 0, n) cin >> arr[i][0] >> arr[i][1];
    rep_u(i, 0, n) arr[i][2] = i;
    // Sorting the array according to the arrival time
    sort(all(arr));

    // Using priority queue to store the departure time and room number
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> data;
    rep_u(i, 0, n){
        if(data.empty()){
            data.push(mp(arr[i][1], ++k));
            ans[arr[i][2]] = k;
        }
        else{
            // If there is an empty room available
            if(data.top().first < arr[i][0]){
                pair<int, int> temp = data.top();
                data.pop();
                data.push(mp(arr[i][1], temp.second));
                ans[arr[i][2]] = temp.second;
            }
            // If there is no empty room available
            else{
                data.push(mp(arr[i][1], ++k));
                ans[arr[i][2]] = k;
            }
        }
    }

    cout << k << nline;
    rep_u(i, 0, n) cout << ans[i] << " ";
    cout << nline;

    return 0;

}