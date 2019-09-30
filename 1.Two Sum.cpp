Approach 1: brute force:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;  
    }       
};


Approach 2: hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if(m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};
