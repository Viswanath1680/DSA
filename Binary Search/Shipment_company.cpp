#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// A simple BS on answer again.
bool Is_enough(vector<int> &weights, int cap , int d) {
    int days = 1;
    int load = 0;
    int n = weights.size(); 
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; 
            load = weights[i]; 
        }
        else {
            load += weights[i];
        }
    }
    return ( days <= d);
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxi = *max_element( weights.begin() , weights.end() );
    int low = *min_element( weights.begin() , weights.end() );
    int high , sum = 0;
    for( auto it : weights )
        sum += it;
    if( d == 1 )
        return sum;
    high = sum;
    int ans = high;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( Is_enough( weights , mid , d ) && mid >= maxi ){
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
        int d; cin >> d;
        vector<int> arr(n,0);
        for( int i = 0 ; i < n ; i++ )
            cin >> arr[i];
        cout << leastWeightCapacity( arr , d ) << "\n";
   }
}