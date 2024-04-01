#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// DP should be used, catch you later.
class Solution {
public:
    string Compress_string( string str ){
        string ans = "";
        for( int i = 0 ; i < str.length() ; i++){
            int j = i;
            ans += str[i];
            while( j < str.length() && str[j] == str[i] )
                j++;
            if( j == str.length() || str[j] != str[i] )
                j--;
            if( j - i ){
                char temp[3];
                int x = sprintf( temp, "%d", j-i+1 );
                ans += temp;
            }
            i = j;
        }
        return ans;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if( k == 0 )
            return s.length();
        
    }
};

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        string s; cin >> s;
        Solution sol;
        cout << sol.Compress_string( s ) << "\n";
   }
}