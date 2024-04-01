#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// #include <bits/stdc++.h> 
string doorStatus(int n) {
    string ans = "";
    for( int i = 0 ; i < n ; i++)
        ans += "1";
    if( n == 1 )
        return ans;
    for( int i = 2 ; i <= n ; i++){
        for( int j = 0; j < n ; j++){
            int k = j+1;
            if( k % i == 0 ){
                if( ans[j] == '1')
                    ans[j] = '0';
                else
                    ans[j] = '1';
            }
        }
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       int n; cin >> n;
       cout << doorStatus(n) << '\n';
   }
}