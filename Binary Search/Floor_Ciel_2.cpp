#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int Floor( int arr[] , int n , int target ){
    int ans = n , low = 0 , high = n-1;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if (arr[mid] >= target) {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int target ) {
    sort( arr , arr + n );
    pair< int , int > ans;
    if( arr[0] > target ){
        ans.first = -1;
        ans.second = arr[0];
        return ans;
    }
    else if( arr[n-1] < target ){
        ans.second = -1;
        ans.first = arr[n-1];
        return ans;
    }
    
    int lower_index = Floor( arr , n , target );
    ans.first = arr[lower_index];
    if( ans.first > target ){
        ans.second = arr[ lower_index];
        ans.first = arr[ --lower_index ];
    }
    else
        ans.second = ans.first;
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n; cin >> n;
        int arr[n];
        for( int i = 0 ; i < n ; i ++)
            cin >> arr[i];
        int target; cin >> target;
        pair < int , int > ans = getFloorAndCeil( arr , n , target );
        cout << ans.first << " " << ans.second << "\n";
   }
}