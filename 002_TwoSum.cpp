class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                result[0] = map[target - nums[i]];
                result[1] = i + 1;
                break;
            } else {
                map[nums[i]] = i + 1;
            }
        }
        
        return result;
    }
};
