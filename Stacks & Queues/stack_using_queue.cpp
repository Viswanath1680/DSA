#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

class Stack {
	// Define the data members.

    int size = 0;
    queue<int> q;
   public:
    Stack() {
        this->size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/
    void push(int element) {
        int n = q.size();
        q.push( element );
        for( int i = 0; i < n ; i++ ){
            q.push( q.front() );
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return ( q.size() == 0 );
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