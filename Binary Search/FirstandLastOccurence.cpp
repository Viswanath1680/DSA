#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int lowerBound(vector<int> arr, int n, int target) {
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

int upperBound(vector<int> &arr, int target, int n){
	int ans = n , low = 0 , high = n -1;
	while( low <= high ){
		int mid = low + (high - low)/2;
		if (arr[mid] > target) {
		ans = min(ans, mid);
		high = mid - 1;
		}
		else if( arr[mid] <= target )
		low = mid + 1;
	}	
	return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int idx = lowerBound( arr , n , k );
    pair<int , int> ans;
    if( idx == n || arr[idx] != k ){
        ans.first = -1 ;
        ans.second = -1;
    }
    else{
        ans.first = idx;
        ans.second = upperBound( arr , k , n ) - 1;
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       int n , k;cin >> n >> k;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        pair<int , int> ans = firstAndLastPosition( arr , n , k );
        cout << ans.first << " " << ans.second << "\n";
   }
}