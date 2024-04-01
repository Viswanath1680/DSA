#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector<int> nextLargerElementleft_Indices( vector<int> arr, int n ){
    vector<int> ans(n);
    ans[0] = -1;
    stack<pair<int,int>> st;
    st.emplace( arr[0], 0 );
    for( int i = 1; i < n ; i++ ){
        while( !st.empty() && st.top().first <= arr[i] )
            st.pop();
        if( st.empty() )
            ans[i] = -1;
        else
            ans[i] = st.top().second;
        st.emplace( arr[i], i );
    }
    return ans;
}

vector<int> nextLargerElementleft( vector<int> arr, int n ){
    vector<int> ans(n);
    stack<int> st;
    for( int i = 0 ; i < n ; i++ ){
    	while( !st.empty() && st.top() <= arr[i] )
    		st.pop();
    	if( st.empty() )
    		ans[i] = -1;
    	else
    		ans[i] = st.top();
    	st.push(arr[i]);
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
        vector<int> ans = nextLargerElementleft_Indices( arr , arr.size() );
        for( auto it : ans )
            cout << it << " ";
        cout << "\n";
   }
}