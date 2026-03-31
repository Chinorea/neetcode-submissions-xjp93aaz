class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size(), l = 0;

        while(l < r) {
            int mid = (l + (r - 1)) / 2;
            int val = nums[mid];
            if (val == target){
                return mid;
            } else if (val > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
