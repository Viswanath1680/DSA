#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector<int> nextGreaterElement( vector<int> arr ){
    int n = arr.size();
    vector<int> ans(n);
    ans[n-1] = -1;
    int maxi = arr[n-1];
    for( int i = n-2; i >= 0 ; i-- ){
        maxi = max( maxi, arr[i] );
        ans[i] = maxi;
    }
    for( auto it : ans )
        cout << it << " ";
    cout << "\n";
    return ans;
}

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int n = prices.size();
    vector<int> rightGreater = nextGreaterElement(prices);
    int ans = 0;
    for( int i = 0 ; i < n ; i++ )
        ans = max( ans, rightGreater[i] - prices[i] );
    return ans;
}


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        cout << bestTimeToBuyAndSellStock(arr) << "\n";
   }
}