#include <iostream>
#include <algorithm> 
using namespace std;

int Floor( int arr[] , int n , int target ){
	// sort( arr , arr+n );
	int ans = n ,low = 0 , high = n-1;
	while( low <= high ){
		int mid = low + ( high - low )/2;
		if( arr[mid] >= target ){
			ans = min( ans , mid );
			high = mid-1;
		}
		else
			low = mid + 1;
	}
	if( arr[ans] > target )
		ans--;
	return ans;
}

// pair<int, int> getFloorAndCeil(int arr[], int n, int target ) {
// 	pair<int , int> ans;
//     sort( arr , arr+n );
//     if( arr[0] > target ){
//         ans.first = -1;
// 		ans.second = 0;
// 		return ans;
// 	}
//     if( arr[n-1] < target ){
//         ans.second = -1;
// 		ans.first = n-1;
// 		return ans;
// 	}
// 	ans.first = lower_bound( arr , n , target );
// 	int idx = ans.first+1 , flag = 0;
// 	while( arr[idx] == target && idx < n ){
//         flag = 1;
// 		idx++;
//     } 
// 	// ans.second = ( flag == 1 ? arr[idx] : arr[idx-1] );
// 	ans.second = arr[idx];
//     ans.first = arr[ ans.first ];
// 	return ans;
// }

pair<int, int> getFloorAndCeil(int arr[], int n, int target ) {
	pair< int , int> ans;
	sort( arr , arr+n );
	int index = Floor( arr , n , target );
	if( index == -1 ){
		ans.first = -1;
		ans.second = arr[0];
	}
	if( index == n ){
		ans.first = arr[n-1];
		ans.second = -1;
	}
	// ans.first = arr[ index ];
	// ans.second = arr[ index+1 ];
	if( arr[ index ] == target ){
		ans.first = target , ans.second = target;
	}
	else{
		
	}
}

int main() {
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        int arr[n];
        for( int i = 0 ; i < n ; i++ )
            cin >> arr[i];
        int target; cin >> target;
        // pair< int , int > ans = getFloorAndCeil( arr , n , target );
        // cout << ans.first << " " << ans.second << "\n";
		int index = Floor( arr , n , target );
		// cout <<( index == -1 ? -1 : arr[index] ) << " " << index <<"\n";
		if( index == -1 )
			cout << -1 << " " << index  << "\n";
		else if( index == n )
			cout << arr[index-1] << " " << index-1 << "\n";
		else
			cout << arr[index] << " " << index << "\n";
   }
}