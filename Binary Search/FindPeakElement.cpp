#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// simple case, if there's one peak. Then 3 cases arise. Index wise:
// 1. peak < middle
// 2. peak = middle -> easy csae to detect
// 3. peak > middle. 
// if we compare and we get the case 3, then it is guaranteed that peak is in the right side of middle.
// similarly if case 1, then peak is in left side.
// this applies in case of multiple peaks too.
 
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if( n == 1 )
        return 0;
    if( arr[0] > arr[1] )
        return 0;
    if( arr[n-1] > arr[n-2] )
        return n-1;
    int low = 0 , high = n-1;
    while( low <= high ){
        int mid = low + (high-low)/2;
        if( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] )
            return mid;
        else if( arr[mid] < arr[mid+1] )
            low = mid+1;
        else if( arr[mid] < arr[mid-1] )
            high = mid-1;
    }
}


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n; cin >> n;
        vector<int> arr(n);
        for( auto& it : arr )
            cin >> it;
        cout << findPeakElement( arr ) << "\n";
   }
}