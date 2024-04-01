#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

/*
    First write brute force:
    for( int i = 0 ; i < n ; i++ )
        for( int j = i ; j >= 0 ; j-- ) Dependent loop
            ...
    => Based on Stack. 

    Idea:
    For each element, find the index of greatest element to it's left. Subtract the indices. Qn done.
*/

vector<int> findStockSpans(vector<int>& arr, int n) {
    vector<int> ans(n);
    stack<pair< int,int >> st;
    ans[0] = 1;
    st.emplace( arr[0], 0 );
    for( int i = 1 ; i < n ; i++ ){
        while( !st.empty() && st.top().first < arr[i] )
            st.pop();
        if( st.empty() )
            ans[i] = i+1;
        else
            ans[i] = i - st.top().second;
        st.emplace( arr[i], i );
    }
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
        vector<int> ans = findStockSpans( arr, arr.size() );
        for( auto it : ans )
            cout << it << " ";
        cout << "\n";
   }
}