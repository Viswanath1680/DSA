#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

long long getTrappedWater(long long* arr, int n) {
    vector<long long> left(n), right(n);
    left[0] = arr[0]; right[n-1] = arr[n-1];
    for( int i = 1; i < n ; i++)
        left[i] = max( left[i-1], arr[i] );
    for( int i = n-2; i >= 0 ; i-- )
        right[i] = max( right[i+1], arr[i] );
    long long ans = 0;
    for( int i = 0; i < n ; i++ )
        ans += min( left[i], right[i] ) - arr[i];
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        int arr[n];
        for( auto& it : arr)
            cin >> it;
        cout << getTrappedWater( arr, n ) << "\n";
   }
}