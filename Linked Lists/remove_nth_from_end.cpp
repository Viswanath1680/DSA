#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // int ans = 0;
        // while( temp ){
        //     temp = temp->next;
        //     ans++;
        // }
        // if( ans == n )
        //     return head->next;

        ListNode* ptr = head , *ptr_preceeding , *end_ptr = head;
        for( int i = 0 ; i < n-1 ; i++ )
            end_ptr = end_ptr->next;

        if( end_ptr->next == nullptr ){
            return ptr->next;
        }
        else{
            ptr_preceeding = head;
            ptr = ptr->next;
            end_ptr = end_ptr->next;
        }

        while( end_ptr->next ){
            ptr = ptr->next;
            ptr_preceeding = ptr_preceeding->next;
            end_ptr = end_ptr->next;
        }
        ptr_preceeding->next = ptr->next;
        return head;
    }
};

ListNode* Convert_to_LL( vector<int> & arr ){
    int n = arr.size();
    ListNode* Head = new ListNode( arr[0] );
    ListNode* temp = Head;
    ListNode* tail;
    for( int i = 1 ; i < n ; i++ ){
        ListNode* temp2 = new ListNode( arr[i] );
        temp->next = temp2;
        temp = temp2;
        if( i == n-1 ){
            tail = temp;
        }
    }
    return Head;
}


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        int pos; cin >> pos;
        ListNode* head = Convert_to_LL( arr );
        Solution sol;
        head =  sol.removeNthFromEnd( head , pos );
        while( head ){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
   }
}