// Planets Queries I
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

    // Taking input from console
    int n, q;
    cin >> n >> q;

    // We will use binary jumping to solve this problem
    // Initialize the jump array, where jump[i][j] = 2^jth parent of i
    // Since we have to find 10^9 the parent in the worst case, we will need log2(10^9) = 30 jumps
    int jump[n][30];

    // Take input of the parent of each node
    for(int i = 0; i < n; i++){
        cin >> jump[i][0];
        jump[i][0]--;
    }

    // Construct the jump array
    // We iterate over the size of jump so that for larger values of j, we can use the values of smaller j
    for(int j = 1; j < 30; j++){
        for(int i = 0; i < n; i++){
            // 2^jth parent of i is 2^(j-1)th parent of 2^(j-1)th parent of i
            jump[i][j] = jump[jump[i][j-1]][j-1];
        }
    }

    // Process the queries
    while(q--){
        int x, k;
        cin >> x >> k;
        x--;
        // We iterate over the bits of k from the most significant bit to the least significant bit
        for(int i = 29; i >= 0; i--){
            // If the ith bit is set, we jump to the 2^ith parent of x
            if(k & (1 << i)){
                x = jump[x][i];
            }
        }
        cout << x + 1 << '\n';
    }

	// TIME COMPLEXITY: O(n*log(k) + q*log(k))
	// SPACE COMPLEXITY: O(n*log(k))

    return 0;

}