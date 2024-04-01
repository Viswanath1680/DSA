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

// class Solution {
// public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_ptr = head , *even_ptr = head->next , *even_head = even_ptr;
        while( even_ptr != nullptr && even_ptr->next != nullptr ){
            odd_ptr->next = even_ptr->next;
            odd_ptr = odd_ptr->next;
    
            even_ptr->next = odd_ptr->next;
            even_ptr = even_ptr->next;
        }

        odd_ptr->next = even_head;
        ListNode* temp = head;
        while( temp ){
            cout << temp->val << " ";
            temp = temp->next;
        }
        return head;
    }
// };

// ListNode* oddEvenList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }

//         ListNode* odd_ptr = head;
//         ListNode* even_ptr = head->next;
//         ListNode* even_head = even_ptr;  // Save the head of even list

//         while (even_ptr != nullptr && even_ptr->next != nullptr) {
//             odd_ptr->next = even_ptr->next;
//             odd_ptr = odd_ptr->next;

//             even_ptr->next = odd_ptr->next;
//             even_ptr = even_ptr->next;
//         }

//         odd_ptr->next = even_head; // Connect the odd list to the even list
//         ListNode* temp = head;
//         while( temp ){
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//         return head;
// }


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        ListNode* head = Convert_to_LL( arr );
        oddEvenList( head );
   }
}