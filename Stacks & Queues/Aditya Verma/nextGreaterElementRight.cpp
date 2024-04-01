#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector< long long> ans(n);
    int it = n-1;
    ans[it--] = -1;
    stack<long> st;
    st.push(arr[n-1]);
    for( int i = n-2 ; i >= 0 ; i--){
        while( !st.empty() && st.top() <= arr[i] )
            st.pop();
        if( st.empty() )
            ans[it--] = -1;
        else
            ans[it--] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans(n,-1);
    if( n == 1 )
        return ans;
	stack<int> st;
	st.push( arr[n-1] );
	for( int i = n-2; i >= 0 ; i--){
        if( arr[i] < st.top() )
            ans[i] = st.top();
        else if( arr[i] >= st.top() ){
            while( !st.empty() && st.top() < arr[i] )
                st.pop();
            if( !st.empty() && arr[i] != st.top() )
                ans[i] = st.top();
        }
        st.emplace(arr[i]);
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
        vector<int> ans = nextLargerElement( arr , arr.size() );
        for( auto it : ans )
            cout << it << " ";
        cout << "\n";
   }
}