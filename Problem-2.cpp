// https://leetcode.com/problems/merge-k-sorted-lists/
// Time Complexity : O(N log k) where N = nk where n is the length of linked lists and k is the number of linked lists
// Space Complexity : O(k) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach
// Store the first elements of the linked lists in a min heap.
// Pop the smallest element and add it to a new linked list. 
// Add the next element of the smallest element if it exists to the heap.

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
        struct compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, compare> pq;
            for(auto li:lists){
                if(li) pq.push(li);
            }
            ListNode* dummy = new ListNode(-1);
            ListNode* curr = dummy;
            while(!pq.empty()){
                ListNode* temp = pq.top();
                pq.pop();
                curr->next = temp;
                curr = curr->next;
                if(curr->next){
                    pq.push(curr->next);
                }
            }
            return dummy->next;
        }
    };