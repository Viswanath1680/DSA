#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)


int maxDepth(string s) {
	int counter1 = 0 , counter2 = 0;
	for( int i = 0 ; i < s.size() ; i++ ){
		if( s[i] == '(' )
			counter1++;
		else if( s[i] == ')' )
			counter1--;
		counter2 = max( counter1 , counter2 );
	}
	return counter2;
}
