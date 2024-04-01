#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void Print( int Pointer , vector<int> arr , vector<int> ans ){
    if( Pointer == arr.size() ){
        for( auto it : ans )
            cout << it << " ";
        cout << "\n";
        return;
    }
    ans.emplace_back( arr[Pointer] );
    Print( Pointer+1 , arr , ans );	// either include this element.
    ans.pop_back();
    Print( Pointer+1 , arr , ans );	// or exclude it.
    return;
}

void Print_str(int pointer, int size, char input[], string ans) {
    if ( pointer == size ) {
        cout << ans << "\n";
        return;
    }
    ans += input[pointer];
    Print_str(pointer + 1, size, input, ans);
    ans.pop_back();
    Print_str(pointer + 1, size, input, ans);
}

void printSubsequences(char input[]) {
    string ans = "";
    int ind = 0;
    while( input[ind] != '\0')
        ind++;
    Print_str(0, ind, input, ans);
}

int32_t main() {
    speedup;
    int t = 1;
    while( t-- ){
    //    int n ;cin >> n;
    //     vector<int> arr(n);
    //     for( auto& it : arr)
    //         cin >> it;
    //     vector<int> ans;
    //     Print( 0 , arr , ans);
        char input[] = {'v','i','s'};
        printSubsequences( input );
   }
}
