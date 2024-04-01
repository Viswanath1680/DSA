#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector<int> nearestSmallerElementLeft( vector<int> arr, int n ){
    vector<int> ans(n);
    ans[0] = -1;
    stack<pair<int,int>> st;
    st.emplace( arr[0], 0 );
    for( int i = 1; i < n; i++){
        while( !st.empty() && st.top().first >= arr[i] )
            st.pop();
        if( st.empty() )
            ans[i] = -1;
        else
            ans[i] = st.top().second;
        st.emplace( arr[i], i );
    }
    return ans;
}

vector<int> nextSmallerRight( vector<int>arr, int n ){
    vector<int> ans(n);
    ans[n-1] = n;
    stack<pair<int,int>> st;
    st.emplace( arr[n-1], n-1 );
    for( int i = n-2; i >= 0 ; i-- ){
        while( !st.empty() && st.top().first >= arr[i] )
            st.pop();
        if( st.empty() )
            ans[i] = n;
        else
            ans[i] = st.top().second;
        st.emplace( arr[i], i );
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        vector<int> left = nearestSmallerElementLeft( arr, n );
        vector<int> right = nextSmallerRight( arr, n );
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            int temp_ans;
            temp_ans = ( right[i] - left[i] - 1 ) * arr[i];
            ans = max( temp_ans, ans );
        }
        cout << ans << "\n";
   }
}