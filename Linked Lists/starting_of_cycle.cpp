/**/
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    
    public:
    ListNode( int data1 ){
    val = data1;
    next = nullptr;
    }
};
 
/*
    Intuition:

    m - Distance before the cycle
    l - length of cycle
    n - posn where fast and slow met

    distance moved by,
    slow = m + n + l*i;
    fast = m + n + l*j ( j > i obv)

    We know that 
    fast = 2*slow
    => m + n = l*( j - 2i )
    m = l*( j - 2i ) - n    => m and n are complement w.r.t the cycle.
    therefore slow travelling m = fast travelling l-n, making them meet at starting point!
*/


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
                return nullptr;
            if( slow == fast ){
                slow = head;
                while( slow != fast ){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};