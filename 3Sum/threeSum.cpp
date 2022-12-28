#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        std::vector<int> a{};
        std::set<std::vector<int>> solutionSet;
        
        for(int i =0; i+2 < nums.size(); i++) {
           if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == 0) {
                    a = {nums[i], nums[j], nums[k]};
                    solutionSet.insert(a);
                    k--;

                    // Skip all duplicates from right
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum > 0) {
                    // Decrement k to reduce sum value
                    k--;
                } else {
                    // Increment j to increase sum value
                    j++;
                }
            }
        }
        
        std::vector<std::vector<int>> answer;
        for (auto x: solutionSet) {
            answer.push_back(x);
        }
        return answer;     
        
    }
};