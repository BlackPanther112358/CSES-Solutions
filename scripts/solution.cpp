//  Dynamic Range Sum Queries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int

const int mod = 1000000007;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

class fenwicked_tree{
private:
    int size;
    vector<int> arr;

public:
    fenwicked_tree(int n){
        size = n;
        arr.resize(n, 0);
    }

    void update(int idx, int val){

    }

    int prefix_sum(int idx){
        int ans = 0;
        while(idx >= 0){
            ans += arr[idx];
            idx = idx&(idx + 1) - 1;
        }
        return ans;
    }

    int range_sum(int l, int r){
        if(l == 0) return prefix_sum(r);
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifdef BlackPanther112358
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    

	// TIME COMPLEXITY: O(n*log(k) + q*log(k))
	// SPACE COMPLEXITY: O(n*log(k))

    return 0;

}