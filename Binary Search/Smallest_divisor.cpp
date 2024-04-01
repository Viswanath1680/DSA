#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// A simple BS on answer and checking the given condition.
bool checkSum( vector<int>& arr , int mid , int limit ){
    int sum = 0;
    for( auto it : arr )
        sum += it/mid + ( it%mid == 0 ? 0 : 1 );
    return ( sum <= limit );
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int low = *min_element( arr.begin() , arr.end() );
    int high = *max_element( arr.begin() , arr.end() );
    int ans = high;
    while( low <= high ){
        int mid = low + ( high - low ) / 2;
        if( checkSum( arr , mid , limit ) ){
            ans = min( ans , mid );
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
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
        int limit; cin >> limit;
        cout << smallestDivisor( arr , limit ) << "\n";
   }
}