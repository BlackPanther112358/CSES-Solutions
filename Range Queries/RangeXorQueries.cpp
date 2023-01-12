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

vector<int> seg_tree;

void create_seg_tree(vector<int> &x, int node, int start, int end){
    // Base case
    if((end - start) == 1){
        seg_tree[node] = x[start];
        return;
    }
    int mid = (start + end) / 2;
    // Recursively create the segment tree
    create_seg_tree(x, 2*node + 1, start, mid);
    create_seg_tree(x, 2*node + 2, mid, end);
    // Update the current node based on child nodes
    seg_tree[node] = seg_tree[2*node + 1] ^ seg_tree[2*node + 2];
}

int query(int node, int start, int end, int l, int r){
    // Base case
    if((start == l) && (end == r)) return seg_tree[node];
    int mid = (start + end) / 2;
    // Recursively query the segment tree
    if(r <= mid) return query(2*node + 1, start, mid, l, r);
    else if(l >= mid) return query(2*node + 2, mid, end, l, r);
    else return query(2*node + 1, start, mid, l, mid) ^ query(2*node + 2, mid, end, mid, r); 
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
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    rep_u(i, 0, n) cin >> x[i];

    // Creating a segment tree to compute range xor sums
    seg_tree.resize(4*n, inf);
    create_seg_tree(x, 0, 0, n);

    // Processing queries
    rep(q){
        int a, b;
        cin >> a >> b;
        cout << query(0, 0, n, a - 1, b) << nline;
    }

    return 0;

}