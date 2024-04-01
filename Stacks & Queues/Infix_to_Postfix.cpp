#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

string infixToPostfix(string exp){
    int n = exp.length();
    stack<char> st;
    string ans = "";
    map<char,int> mp;
    mp['^'] = 3;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
	for( int i = 0 ; i < n ; i++){
        char c = exp[i];
        int ascii = int( exp[i] );
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;
        else if( c == '(' )
            st.push(c);
        else if( c == ')' ){
            while( !st.empty() && st.top() != '(' ){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while( !st.empty() && mp[c] <= mp[st.top()] ){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }    
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

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