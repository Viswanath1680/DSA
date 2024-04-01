#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = 1000000000 + 1, high = 0;
    for( int i = 0 ; i < m ; i++ ){
        low = min( matrix[i][0], low );
        high = max( matrix[i][n-1], high );
    }
    while( low <= high ){
        int mid = low + ( high - mid ) >> 1;
        int lessThanMid = 0;
        for( int i = 0 ; i < m ; i++ ){
            int ind = lower_bound( matrix[i].begin(), matrix[i].end(), mid ) - matrix[i].begin();
            if( ind != (n-1) && matrix[i][ind] != mid )
                continue;
            lessThanMid += ind + 1;
        }
        if( lessThanMid <= ( ( m*n ) >> 2 ) )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
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