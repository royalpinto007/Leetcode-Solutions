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
    ListNode* removeNthFromEndFunc(ListNode* head, int& n, ListNode* &ans) {
        if(!head){
            return head;
        }     
        
        head->next = removeNthFromEndFunc(head->next, n, ans);
        
        if(n == 0){
            ans = head;
        }
        n--;
        
        return head;
    }   
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = NULL;
        ListNode* root = removeNthFromEndFunc(head, n, ans);    
        
        if(!ans){
            return head->next;
        }
        
        ans->next = (ans->next)->next;
        return head;
    }
};


/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int len = 0;
        
        while(cur){
            ++len;
            cur = cur->next;
        }
        
        if(n == len){
            //delete the head
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        
        cur = head;
        for(int i = 0; i < len; ++i){
            if(i == len-n-1){
                //the node previous to the node to be deleted
                ListNode* to_delete = cur->next;
                cur->next = cur->next->next;
                delete to_delete;
                break;
            }
            cur = cur->next;
        }
        
        return head;
    }
};
*/

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* cur;
        int len = 0;
        
        cur = dummy->next;
        while(cur){
            ++len;
            cur = cur->next;
        }
        
        // cout << "len: " << len << endl;
        
        cur = dummy;
        for(int i = 0; i < len; ++i, cur = cur->next){
            //i is 1-based
            // cout << i << " : " << cur->val << endl;
            if(i == len-n){
                //this is the node previous to the node to be deleted
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                break;
            }
        }
        
        return dummy->next;
    }
};
*/

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        
        for(int i = 0; i < n+1; ++i){
            fast = fast->next;
        }
        //slow and fast are n+1 apart
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        //slow is n+1 from tail->next, so n from tail
        //so it's (n+1)-last node
        
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy->next;
    }
};
*/