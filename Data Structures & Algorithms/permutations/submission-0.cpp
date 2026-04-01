class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> perm;
        backtrack(perm, pick, nums);
        return res;
    }
private:
    void backtrack(vector<int>& perm, vector<bool>& pick, vector<int>& nums) {
        if(perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(!pick[i]){
                perm.push_back(nums[i]);
                pick[i] = true;
                backtrack(perm,pick,nums);
                perm.pop_back();
                pick[i] = false;
            }
        }
    }
};
