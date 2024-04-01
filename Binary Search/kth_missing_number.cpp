#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// is mid == kth number ? return that. if >kth number high = mid - 1. Similarly low = mid + 1;
int missingK(vector <int>arr, int n, int k) {
    if( k < arr[0] )
        return k;
    int low = 1 , high = arr[n-1] + k;
    int ans;
    int k_copy = k;
    while( low <= high ){
        k_copy = k;
        int mid = low + ( high - low )/2;
        int low_ind = lower_bound( arr.begin() , arr.end() , mid ) - arr.begin() ;   //these many indexes are already covered in the array
        if( low_ind < n && arr[low_ind] == mid )
            low_ind++;
        k_copy += low_ind;
        int k_copy_low = lower_bound( arr.begin() , arr.end() , k_copy ) - arr.begin();
        if( k_copy == mid && arr[k_copy_low] != mid )
            return mid;
        if( k_copy < mid )
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 1;
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
        int k; cin >> k;
        cout << missingK( arr , n , k ) << "\n";
   }
}