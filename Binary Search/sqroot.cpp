#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int floorSqrt(int n)
{
    int low = 0 , high = n;
    while( low <= high ){
        int mid = low + ( high - low )/2;
        if( mid*mid == n )
            return mid;
        if( mid*mid < n )
            low = mid+1;
        else
            high = mid-1;
    }
    return min( low , high );
}


int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
        int n ;cin >> n;
        cout << floorSqrt(n) << "\n";
   }
}