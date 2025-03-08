// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Time Complexity : O(n log k)
// Space Complexity : O(k) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach
// Declare a min-heap that stores the k largest elements so far.
// For every element, insert it into the heap and remove the smallest element so far.
// Return the top element.

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            priority_queue<int, vector<int>, greater<int>> pq;
            for(auto i:nums){
                pq.push(i);
                if(pq.size() > k){
                    pq.pop();
                }
            }
            return pq.top();
        }
    };