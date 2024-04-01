#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

bool rotateString(string s, string goal) {
   if( s.length() != goal.length() )
      return false;
   s = s + s;
   for( int j = 0 ; j < s.length() ; j++ ){
      for( int i = 0 ; i < goal.length() ; i++ ){
         if( s[j] == goal[i] ){
            if( goal == s.substr( j , goal.length() ) )
               return true;
         }
      }
   }
   return false;
}

int32_t main() {
    speedup;
    int te = 1;
    while( te-- ){
       string s , t;
       cin >> s >> t;
        cout << rotateString( s , t ) << "\n";
   }
}