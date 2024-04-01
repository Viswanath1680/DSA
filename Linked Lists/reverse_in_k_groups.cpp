
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
// intuition - first take the k-size window, reverse it and then attach it to the LL. Iterate this..
ListNode* reverseList(ListNode* head) {
        ListNode* current = head , *prev = NULL;
        while( current ){
            ListNode* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head , *runner = head;
        int k_copy = k;
        while( k_copy ){
            k_copy--;
            temp = runner;
            runner = runner->next;
        }
        temp ->next = nullptr;
        head = reverseList( head );
        temp = head;
        while( temp->next )
            temp = temp->next;
        temp->next = runner;
        if( runner == nullptr )
            return head;
        ListNode* temp_head_prev = temp;
        temp = runner;
        while( runner ){
            k_copy = k;
            while( runner && k_copy ){
                k_copy--;
                temp = runner;
                runner = runner->next;
            }
            if( k_copy )
                return head;
            else{
                temp->next = nullptr;
                ListNode* dummy = temp_head_prev->next;
                dummy = reverseList( dummy );
                temp_head_prev->next = dummy;
                temp = dummy;
                while( temp->next )
                    temp = temp->next;
                temp->next = runner;
                temp_head_prev = temp;
                temp = runner;
            }
        }
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
        int k; cin >> k;
        ListNode* head = Convert_to_LL( arr );
        Solution sol;
        head = sol.reverseKGroup( head , k );
        ListNode* temp = head;
        while( temp ){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
   }
   return 0;
}