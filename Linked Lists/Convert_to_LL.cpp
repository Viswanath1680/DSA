#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

class Node{
    public:
        int data;
        Node* ptr;
    public:
    Node( int data1 , Node* ptr1 ){
        data = data1;
        ptr = ptr1;
    }

    public:
    Node( int data1 ){
        data = data1;
        ptr = NULL;
    }
};

Node *deleteLast(Node *Head){
    Node* temp = Head ;
    Node* temp_next = Head->ptr;
    while( temp_next->ptr ){
        temp = temp->ptr;
        temp_next = temp_next->ptr;
    }
    temp->ptr = NULL;
    return Head;
}

Node* Convert_to_LL( vector<int> & arr ){
    int n = arr.size();
    Node* Head = new Node( arr[0] );
    Node* temp = Head;
    Node* tail;
    for( int i = 1 ; i < n ; i++ ){
        Node* temp2 = new Node( arr[i] );
        temp->ptr = temp2;
        temp = temp2;
        if( i == n-1 ){
            tail = temp;
        }
    }
    return Head;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<int> array;
    Node* temp = head;
    while( temp ){
        array.emplace_back( temp->data );
        temp = temp->ptr;
    }
    sort( array.begin() , array.end() );
    vector<pair<int , int>> answer;
    int n = array.size();
    for( int i = 0 ; i < n ; i++){
        int j = n-1;
        while( j>=i && array[i] + array[j] >= k ){
            if( array[i] + array[j] == k )
                answer.emplace_back( array[i] , array[j] );
            j--;
        }
    }
    for( auto it : answer )
        cout << it.first << " " << it.second << "\n";
    // cout << "\n";
    return answer;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        vector<int> arr = { 1 , 10 ,  11 ,  12 ,  27 };
        Node* Head = Convert_to_LL( arr );
        findPairs( Head , 12 );
        // Head = deleteLast( Head );
        // Node* temp = Head;
        // while( temp->ptr )
        //     temp = temp->ptr;
        // cout << temp->data ;

   }
}