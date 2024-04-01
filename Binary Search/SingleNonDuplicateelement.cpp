#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// Monotonicty changes when the required element encounters. How?
// Here's why: 
// until we encounter no dupicate element, the indices of the repeated element will be :
// ( even - odd ) - ( even - odd ) .. After the single element, it changes to OE OE. This is the monotonic nature.

int singleNonDuplicate(vector<int>& arr){
	int low = 0 , high = arr.size() - 1;
    if( low == high )
        return arr[0];
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( mid%2 == 0 ){
            if( arr[mid] == arr[mid+1] && mid < arr.size()-1)
                low = mid + 1;
            else if( arr[mid] == arr[mid-1] && mid > 0)
                high = mid - 1;
            else
                return arr[mid];
        }
        else if( mid%2 == 1 ){
            if( arr[mid] == arr[mid+1] && mid < arr.size()-1 )
                high = mid - 1;
            else if( arr[mid] == arr[mid-1] && mid > 0 )
                low = mid + 1;
            else
                return arr[mid];
        }
    }
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
        cout << singleNonDuplicate( arr ) << "\n";
   }
}