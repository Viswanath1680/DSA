#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

#include <string>
#include <vector>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) {
    vector<bool> chars(128, false);
    map<char, char> smp;
    
    for (int i = 0; i < s.length(); i++) {
        if (smp.find(s[i]) == smp.end()) {
            if (!chars[t[i]]) {
                chars[t[i]] = true;
                smp[s[i]] = t[i];
            } else {
                return false;
            }
        } else if (smp[s[i]] != t[i]) {
            return false;
        }
    }
    return true;
}


int32_t main() {
    speedup;
    int te = 1;
    // cin >> t;
    while( te-- ){
       string s , t;
       cin >> s >> t;
        cout << isIsomorphic( s , t ) << "\n";
   }
}