#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int timetaken( vector<int> v , int p ){
    int time = 0;
    for( auto it : v ){
        if( it%p == 0 )
            time += it/p;
        else
            time += it/p + 1;
    }
    return time;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    if( v.size() == 1 ){
        return ( v[0]%h == 0 ? v[0]/h : v[0]/h+1 );
    }
    // sort( v.begin() , v.end() );
    // int low = *min_element( v.begin() , v.end() );
    int low = 1;
    int high = *max_element( v.begin() , v.end() );
    int ind = high;
    if( h == v.size() )
        return high;
    int mid;
    while( low <= high ){
        mid = ( high + low ) /2;
        int mid_ans = timetaken( v , mid );
        // cout << mid << " " << mid_ans << "\n";
        if( mid_ans <= h ){
            ind = min( ind , mid );
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ind;
}


int32_t main() {
    // speedup;
    int t = 1;
    // cin >> t;
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
    while( t-- ){
        int h; cin >> h;
        // cout << timetaken( arr , h ) << "\n";
        cout << minimumRateToEatBananas( arr , h ) << "\n";
   }
}