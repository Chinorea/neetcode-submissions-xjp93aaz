class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        
        for (int num : nums){
            if(!mp[num]) {
                mp[num] = mp[num - 1] + mp[num + 1] + 1; //update curr longest
                mp[num - mp[num - 1]] = mp[num]; //update left edge with curr longest
                mp[num + mp[num + 1]] = mp[num]; //update right edge with curr longest
                res = max(res,mp[num]); // update largest length
            }
        }
        return res;
    }
};
