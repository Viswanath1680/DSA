#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// To implement a set DS.

/*
    Functions in Set : 
    Add, remove, print. // but numbers are unique. If I add 5 twice, it only prints once,
    Set prints the numbers in ascending order. But, Time complexity O(1) ans Space too!
*/

// Numbers inserted are in between 1 and 60 ( included )

// Using Bit masking. long long int will have 64 bits. Hence, 60 bits.

int x = 0;

void Add( int bit ){
    x = x | ( 1 << bit );
}

void remove( int bit ){
    if( x & ( 1 << bit ) )
        x = x - ( 1 << bit );
    else
        cout << "Number doesn't exist\n";
    return;
}

void print(){
    int x_copy = x;
    for( int bit = 0 ; bit <= 60 ; bit++ ){
        if( x & ( 1 << bit ) )
            cout << bit << " ";
    }
    cout << "\n";
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       Add(5);
       Add(3);
       Add(2);
       print();
       remove(5);
       remove(3);
       print();
   }
   
}