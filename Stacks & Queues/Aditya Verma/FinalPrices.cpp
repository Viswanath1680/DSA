#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector<int> Discountarray( vector<int> arr ){
    int n = arr.size();
    vector<int> ans(n);
    if( n == 1 )
        return ans;
    stack<int> st;
    st.push(arr[n-1]);
    for( int i = n-2; i >= 0 ; i--){
        while( !st.empty() && st.top() >= arr[i] )
            st.pop();
        if( !st.empty() )
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

vector<int> finalPrices(vector<int>& prices) {
    vector<int> discount = Discountarray(prices);
    int n = prices.size();
    for( int i = 0 ; i < n ; i++ )
        prices[i] -= discount[i];
    return prices;
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
        vector<int> ans = finalPrices( arr );
        for( auto it : ans )
            cout << it << " ";
        cout << "\n";
   }
}