#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

bool isValidParenthesis(string s)
{
    if( s.length() == 0 )
        return true;
    stack<char> char_stack;
    for( auto it : s ){
        if( it == '{' || it == '(' || it == '[' )
            char_stack.push( it );
        else if( it == '}' || it == ')' || it == ']' ){
            if( char_stack.empty() )
                return false;
            char temp = char_stack.top();
            char_stack.pop();
            if( it == '}' ){
                if( temp != '{' )
                    return false;
            }
            else if( it == ')' ){
                if( temp != '(' )
                    return false;
            }
            else if( it == ']' ){
                if( temp != '[' )
                    return false;
            }
        }
    }
    return true;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        string s; cin >> s;
        cout << isValidParenthesis( s ) << "\n";
   }
}