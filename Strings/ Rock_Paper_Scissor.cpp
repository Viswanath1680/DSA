#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

vector < int > rockPaperScissor(int k, string arr1, string arr2) {
    int nez = 0 , zen = 0;
    int n1 = arr1.length();
    int n2 = arr2.length();
    int it1 = 0 , it2 = 0;
    while(k--){
        if( arr1[it1] == arr2[it2] ){

        }
        else if( arr1[it1] == 'R' ){
            if( arr2[it2] == 'P' )
                zen++;
            else
                nez++;
        }
        else if( arr1[it1] == 'P' ){
            if( arr2[it2] == 'R' )
                nez++;
            else
                zen++;
        }
        else if( arr1[it1] == 'S' ){
            if( arr2[it2] == 'R' )
                zen++;
            else
                nez++;
        }
        it1 = ( it1 + 1 ) % n1;
        it2 = ( it2 + 1 ) % n2;
    }
    vector<int> ans(2,0);
    ans[0] = nez;
    ans[1] = zen;
    return ans;
}

int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    string s1, s2; cin >> s1 >> s2;
    vector<int> ans = rockPaperScissor( t, s1, s2 );
}