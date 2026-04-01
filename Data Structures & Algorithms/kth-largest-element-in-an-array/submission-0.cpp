class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(int num : nums){
            maxHeap.push(-1 * num);
        }

        int res = 0;
        for(int i = 0; i <= nums.size() - k; i++){
            res = maxHeap.top();
            maxHeap.pop();
        }
        return - 1 * res;
    }
};
