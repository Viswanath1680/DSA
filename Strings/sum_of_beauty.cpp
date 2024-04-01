#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int calculate_beauty( vector<int>& freq ){
    int mini = 1000 , maxi = 0;
    for( auto it : freq ){
        maxi = max( maxi , it );
        if( it >= 1 )
            mini = min( mini , it );
    }
    return ( maxi - mini );
}

int beautySum(string s) {
    int ans = 0;
    for( int i = 0 ; i < s.length() ; i++ ){
        vector<int> freq( 26 , 0 );
        for( int j = i  ; j < s.length() ; j++  ){
            freq[ s[j] - 'a' ]++;
            ans += calculate_beauty( freq );
        }
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    while( t-- ){
        string s; cin >> s;
        cout << beautySum( s ) << "\n";
   }
}