#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

int setBits(int N){
    int ncopy = N;
    int bits = 0;
    while(ncopy){
      if ((ncopy & 1) == 0) {
        N = N | (1 << bits);
        break;
      }
      bits++;
      ncopy = ncopy >> 1;
    }
    return N;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        cout << setBits(n) << "\n";
   }
}