#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// Basically the idea is, BS on answer. First we guess a value for the answer and check if it really
// is. If yes, we take the min value of ans if not, eliminate one half.

// in this case, I guess the answer as mid. Checking if mid satisfies requirements is simple.
// I've pointed out all the vals in the vector that are > mid -> the gap between them 
// are required roses.

int boquets_count( vector<int> arr, int mid , int k , int m){
    vector<int> buffer;
    buffer.push_back(-1);    // for the purpose of gap.
    for( int i = 0 ; i < arr.size() ; i++ ){
        if( arr[i] > mid )
            buffer.push_back(i);
    }
    buffer.push_back( arr.size() );   // for the purpose of gap.
    // for( auto it : buffer )
    //     cout << it << " ";
    // cout << "\n";
    int boquets = 0;
    for( int i = 0 ; i < buffer.size()-1 ; i++ ){
        int gap = buffer[i+1] - buffer[i] - 1;
        if( gap >= k )
            boquets += gap/k;
    }
    if( boquets >= m )
        return mid;
    return -1;
}

int roseGarden(vector<int> arr, int k, int m)
{
    int n = arr.size();
    if( k*m > n )
        return -1;
    int low = *min_element( arr.begin() , arr.end() );
    int high = *max_element( arr.begin() , arr.end() );
    int ans = high;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        int val = boquets_count( arr , mid , k , m );
        // cout << "mid:" << mid << " val:" << val << "\n";
        if( val == -1 )
            low = mid + 1;
        else{
            ans = min( ans , mid );
            high = mid - 1;
        }
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        int k , m; cin >> k >> m;
        // int test; cin >> test;
        // while( test-- ){
        //     int mid ; cin >> mid;
        //     boquets_count( arr , mid , k , m ); 
        // }
        cout << roseGarden( arr , k , m ) << "\n";
   }
}