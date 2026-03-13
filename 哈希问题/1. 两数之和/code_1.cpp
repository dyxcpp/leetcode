
// // 解法一：直接双层遍历,时间复杂度是O(n^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         for(int i = 0; i < nums.size(); ++i) {
//             int tmp = nums[i];
//             for(int j = i+1; j < nums.size(); ++j) {
//                 if(nums[j] == target - tmp) {
//                     res = {i, j};
//                 }
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res;
//         unordered_set<int> recoder;
//         for(int i = 0; i < nums.size(); ++i) {
//             if(recoder.find(nums[i]) != recoder.end()) {
//                 res.push_back(i);        
//                 break;
//             }
//             else recoder.insert(target - nums[i]);
//         }
//         for(int i = 0; i < nums.size(); ++i) {
//             if(nums[i] == target - nums[res[0]]) {
//                 res.push_back(i);
//                 break;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> recoder;
        for(int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator it = recoder.find(nums[i]);
            if(it != recoder.end()) {
                res = {it->second, i};        
                break;
            }
            else recoder[target - nums[i]] = i;
        }
        
        return res;
    }
};
