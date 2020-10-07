/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        k = k%(getCount(head));
        int lastVal = head->val;
        
        for(int i = 0; i<k; i++){
            rotateHelper(head, head->val, lastVal);
            head->val = lastVal;
        }
        return head;
    }
    int getCount(ListNode* head)  
    {  
        int count = 0; // Initialize count  
        ListNode* current = head; // Initialize current  
        while (current != NULL)  
        {  
            count++;  
            current = current->next;  
        }  
    return count;  
}  
   void rotateHelper(ListNode* currNode,int preVal,int &lastVal){
        if( currNode->next != nullptr){
            rotateHelper(currNode->next, currNode->val, lastVal);
        }
        if( currNode->next == nullptr){
            lastVal = currNode->val;
        }
        currNode->val = preVal;
    }
};
