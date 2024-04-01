#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int sum( int n ){
    if( !n )
        return 0;
    return n%10 + sum(n/10);
}

int32_t main() {
    // speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
        int n ;cin >> n;
        cout << sum(n) << "\n";
   }
}