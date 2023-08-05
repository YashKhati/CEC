
// Approach 1 :
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* tailA = headA;
        ListNode* tailB = headB;
        int lenA = 0 ,lenB = 0;
        while(tailA != NULL)
        {
            lenA++ ;
            tailA = tailA->next;
        } 
        while(tailB != NULL)
        {
            lenB++ ;
            tailB = tailB->next;
        } 
        tailA = headA;
        tailB = headB;
        int diff = abs(lenA - lenB);
        if(lenA > lenB)
        {
            while(diff--)
            {
                tailA = tailA->next;
            }
        }
        else
        {
            while(diff--)
            {
                tailB = tailB->next;
            }
        }

        while(tailA != NULL && tailB != NULL)
        {
            if(tailA == tailB)
            {
                break;
            }
            tailA = tailA->next;
            tailB = tailB->next;
        }
        return tailA;
    }
};


// Approach 2:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tailA = headA;
        ListNode* tailB = headB;

        while(tailA != tailB)
        {
            tailA = tailA == NULL ? headB : tailA->next;
            tailB = tailB == NULL ? headA : tailB->next;
        }
        return tailA;
    }
};