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
public:
    int size;
    vector<int> arr;

    fenwicked_tree(int n){
        size = n;
        arr.resize(n, 0);
    }

    fenwicked_tree(vector<int> &nums){
        size = nums.size();
        arr.resize(size, 0);
        for(int i = 0; i < size; i++){
            arr[i] += nums[i];
            int r = i|(i + 1);
            if(r < size) arr[r] += arr[i];
        }
    }

    void update(int idx, int val){
        while(idx < size){
            arr[idx] += val;
            idx = idx|(idx + 1);
        }
    }

    int prefix_sum(int idx){
        int ans = 0;
        while(idx >= 0){
            ans += arr[idx];
            idx = (idx&(idx + 1)) - 1;
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

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    fenwicked_tree f_tree(arr);

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k, u;
            cin >> k >> u;
            f_tree.update(k - 1, u - arr[k - 1]);
            arr[k - 1] = u;
        }else{
            int a, b;
            cin >> a >> b;
            cout << f_tree.range_sum(a - 1, b - 1) << "\n";
        }
    }

	// TIME COMPLEXITY: O(n + q*log(n))
	// SPACE COMPLEXITY: O(n)

    return 0;

}