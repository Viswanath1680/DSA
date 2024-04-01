#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// code is not correct. check why

int count_highest_continuous_substring( string str ){
    int n = str.length();   // string length
    int max = 0;
    for( int i = 0 ; i < n ;  ){
        int count = 0;
        char c = str[i];
        while( i < n && str[i] == c ){
            i++;
            count++;
        }
        if( count > max )
            max = count;
    }
    return max;
}

int countSubStrings(string s, int k) 
{
    int ans = 0;
    int n = s.length();
    int count = count_highest_continuous_substring( s );
    for( int window = k ; window <= count + k - 1 ; window++ ){
        map<char , int> hashmap;
        hashmap.clear();
        for( int i = 0 ; i <= n - window ; i++ ){
            int j = i + window - 1;
            bool flag = true;
            for( int p = i ; p <= j ; p++ ){
                hashmap[ s[p] ]++;
            }
            if( hashmap.size() == k ){
                ans++;
                cout << s.substr( i , window ) << " ";
            }
            hashmap.clear();
        }
        cout << "\n";
    }
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       string s; cin >> s;
       int k; cin >> k;
    //    cout << "frequency: "<< count_highest_continuous_substring( s ) << "\n";
       cout << countSubStrings( s , k ) << "\n";
   }
}