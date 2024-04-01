#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// intuition - First reverse the given LLs. Then take two pointers, start from the last.
// Iterate over the LLS until they're same.

ListNode* reverse_ll( ListNode* head ){
    if( head == nullptr || head->next == nullptr )
        return head;
    ListNode* temp = head, *temp2 = head->next ;
    if( temp2->next == nullptr ){
        temp->next = nullptr;
        temp2->next = temp;
        return temp2;
    }
    ListNode *temp3 = head->next->next;
    temp->next = nullptr;
    while( temp3 ){
        temp2->next = temp;
        temp = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }
    temp2->next = temp;
    return temp2;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* newheadA = reverse_ll( headA );
        ListNode* newheadB = reverse_ll( headB );
        ListNode* temp1 = newheadA , *temp2 = newheadB;
        if( temp1 != temp2 )
            return nullptr;
        while( temp1->next == temp2->next ){
            temp1 = temp1->next;
            temp2 = temp2->next;
        } 
        return temp1;
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
        ListNode* head = Convert_to_LL( arr );
        Solution sol;
        head = reverse_ll( head );
        ListNode* temp = head;
        while( temp ){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
   }
}