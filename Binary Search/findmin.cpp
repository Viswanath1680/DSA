#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// int ans = INT16_MAX;
int findMin(vector<int>& arr)
{
	int low = 0 , high = arr.size() - 1;
    if( low == high )
        return arr[low];
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( arr[low] <= arr[mid] && arr[mid] <= arr[high] )
            return arr[low];
        if( arr[low] <= arr[mid-1] && arr[mid] <= arr[high] )
            return arr[mid];
        if( arr[low] <= arr[mid] )
            low = mid+1;
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int findKRotation(vector<int> &arr){
	int low = 0 , high = arr.size() - 1;
    if( low == high )
        return low;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( arr[low] <= arr[mid] && arr[mid] <= arr[high] )
            return low;
        if( arr[low] <= arr[mid-1] && arr[mid] <= arr[high] )
            return mid;
        if( arr[low] <= arr[mid] )
            low = mid+1;
        else{
            high = mid - 1;
        }
    }
    return -1;  
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
        cout << findKRotation( arr ) << "\n";
   }
}