#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

/*
You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations,
 and false otherwise.
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int sum = 0;
        for( auto it : words )
            sum += it.size();
        int n = words.size();
        if( sum % n != 0 )
            return false;
        vector<int> chars( 26, 0 );
        for( auto outer : words )
            for( auto it : outer )
                chars[ it-'a' ]++;
        for( auto it : chars )
            if( it % n != 0 )
                return false;
        return true;
    }
};

int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
       int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
 
   }
}