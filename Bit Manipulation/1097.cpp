#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        bool flag = true;
        for( int num = 0 ; num < (1 << n) ; num++ ){
            int sum = 0;
            for( int bit = 0 ; bit < n ; bit++ ){
                if( num & ( 1 << bit ) )
                    sum += arr[bit];
                else
                    sum -= arr[bit];
            }
            if( sum % 360 ==  0 ){
                cout << "YES\n";
                flag = false;
                break;
            }
        }
        if( flag )
            cout << "NO\n";
   }
}