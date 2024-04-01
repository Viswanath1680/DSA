#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

class Solution {
public:
    // IV = 4       IX = 9
    // XL = 40      XC = 90
    // CD = 400     CM = 900
    int romanToInt(string s) {
        int ans = 0;
        for( int i = 0 ; i < s.length() ; i++ ){
            char c = s[i];
            if( c == 'V' )
                ans += 5;
            else if( c == 'L' )
                ans += 50;
            else if( c == 'D' )
                ans += 500;
            else if( c == 'M' )
                ans += 1000;
            else if( c == 'I' ){
                if( i != ( s.length()-1 ) && s[i+1] == 'V' ){
                    ans += 4;
                    i++;
                }
                else if( i != ( s.length()-1 ) && s[i+1] == 'X' ){
                    ans += 9;
                    i++;
                }
                else
                    ans++;
            }
        }
    }
};

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){

   }
}