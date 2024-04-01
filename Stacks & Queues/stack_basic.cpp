#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// Stack class.
class Stack {
    
public:
    int size = 0, top_ptr = -1;
    int* arr;
    Stack(int capacity) {
    this->size = capacity;
    this->arr = new int[capacity];
    this->top_ptr = -1;
    }

    int isEmpty() {
        return ( top_ptr == -1 );
    }
    
    int isFull() {
        return ( top_ptr == this->size-1 );
    }

    void push(int num) {
        if( isFull() )
            return;
        arr[++top_ptr] = num;
    }

    int pop() {
        if( isEmpty() )
            return -1;
        return arr[top_ptr--];
    }
    
    int top() {
        if( isEmpty() )
            return -1;
        return arr[top_ptr];
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