#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int binSearch( vector<int> arr, int k ){
    int n = arr.size();
    int low = 0, high = n-1;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        int diff = n - mid ;
        // cout << low << " " << high << " " << mid << " " << diff << "\n";
        if( diff == k )
            return arr[mid];
        else if( diff < k )
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

void kthLargest( int n, int m, int k ){
    vector<int> arr;
    for( int i = 1 ; i <= n ; i++ )
        for( int j = 1; j <= m ; j++ )
            arr.emplace_back( i*j );
    sort( arr.begin(), arr.end() );
    cout << binSearch( arr, k ) << "\n";
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n,m,k; cin >> n >> m >> k;
        k--;
        if( k == 0 ){
            cout << n*m << "\n";
            continue;
        }
        if( k == n*m - 1){
            cout << 1 << "\n";
            continue;
        }
        kthLargest( n,m,k );
   }
}