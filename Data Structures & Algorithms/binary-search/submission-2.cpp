class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size(), l = 0, mid = (r - 1) / 2;

        while(l < r) {
            int val = nums[mid];
            if (val == target){
                return mid;
            } else if (val > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
            mid = (l + r - 1) / 2;
        }

        return -1;
    }
};
