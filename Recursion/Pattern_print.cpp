#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

/*
    Should print this:
    1
    1 2
    1 2 3
    ..
    1 2 3 .. n
*/

void Print( int n ){
    if( n == 1 ){
        cout << 1 << "\n";
        return;
    }
    Print( n-1 );
    for( int i = 1 ; i <= n ; i++)
        cout << i << " ";
    cout << "\n";
}

/*
    1 2 3 .. n
    ..
    1 2 3
    1 2
    1
*/

void Print2( int n ){
    if( n == 1 ){
        cout << 1 << "\n";
        return;
    }
    for( int i = 1 ; i <= n ; i++)
        cout << i << " ";
    cout << "\n";
    Print2( n-1 );
}


void Print3( int n ){
    if( n == 1 ){
        cout << 1 << "\n";
        return;
    }
    for( int i = 1 ; i <= n ; i++)
        cout << i << " ";
    cout << "\n";
    Print3( n-1 );
    for( int i = 1 ; i <= n ; i++)
        cout << i << " ";
    cout << "\n";
    return;
}

int32_t main() {
    // speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
        int n ;cin >> n;
        // Print(n);
        // Print2(n);
        Print3(n);
   }
}