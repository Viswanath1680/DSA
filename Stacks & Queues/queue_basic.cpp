#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

class Queue {

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        arr[++rear] = e;
		if( front == -1 )
			front++;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
		if( front == rear+1 || front == -1 )
			return -1;
        return arr[ front++ ];
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