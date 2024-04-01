#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

/*
    If m*n matrix is given, make n histograms ( or m ) out of it. Now find max of all.
*/

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

int histogramArea( vector<int> arr ){
    int n = arr.size();
    vector<int> left = nearestSmallerElementLeft( arr, n );
    vector<int> right = nextSmallerRight( arr, n );
    int ans = 0;
    for( int i = 0 ; i < n ; i++ ){
        int temp_ans;
        temp_ans = ( right[i] - left[i] - 1 ) * arr[i];
        ans = max( temp_ans, ans );
    }
    return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    vector<int> histogram(m);
    int ans = 0;
    for( int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < m ; j++){
            if( mat[i][j] )
                histogram[j]++;
            else
                histogram[j] = 0;
        }
        ans = max( ans, histogramArea( histogram ) );
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
 
   }
}