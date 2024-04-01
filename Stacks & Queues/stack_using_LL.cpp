#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)


    // Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

class Stack
{
    // Write your code here

    int size = 0;
    Node* head , *end;

public:
    Stack()
    {
        head = nullptr;
        end = nullptr;
    }

    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return ( this->size == 0 );
    }

    void push(int data)
    {
        if( size == 0 ){
            Node* temp = new Node(data);
            head = temp;
            end = temp;
            size++;
            return;
        }
        Node* temp = new Node( data, end );
        end = temp;
        size++;
    }

    void pop()
    {
        if( size == 0 )
            return;
        Node* end_successor = end->next;
        delete end;
        end = end_successor;
        size--;
    }

    int getTop()
    {
        if( this->size == 0 )
            return -1;
        return end->data;
    }
};

int32_t main()
{
    speedup;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &it : arr)
            cin >> it;
    }
}