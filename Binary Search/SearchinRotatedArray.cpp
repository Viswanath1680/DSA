#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    int low = 0 , high = arr.size()-1;
    while( low <= high ){
        int mid = low + (high - low)/2;
        if( arr[mid] == key )
            return true;
        if( arr[low] == key )
            return true;
        if( arr[high] == key )
            return true;
        if( arr[low] <= arr[mid] ){
            if( arr[low] <= key && key <= arr[mid] )
                high = mid-1;
            else
                low = mid+1;
        }
        else{       
            if( arr[mid] <= key && key <= arr[high] )
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return false;
}

int search(int* arr, int n, int key) {
    int low = 0 , high = n-1;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( arr[mid] == key )
            return mid;
        else if( arr[low] <= arr[mid] )  {  // left-sorted
            if( arr[low] <= key && key <= arr[mid] )
                high = mid-1;
            else
                low = mid+1;
        }   
        else{       // right - sorted
            if( arr[mid] <= key && key <= arr[high] )
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int32_t main() {
    speedup;
    int t = 1;
    int n; cin >> n;
    int arr[n];
    for( auto& it : arr )
        cin >> it;
    cin >> t;
    while( t-- ){
        int key;
        cin >> key;
        cout << search( arr , n , key ) << "\n";
   }
}