/********************************************************************************
 * Given an array of integers, return indices of the two numbers such that they 
 * add up to a specific target. You may assume that each input would have exactly
 * one solution, and you may not use the same element twice.
 * Example:
 *      Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1] = 2 +
 *      7 = 9,
 *      
 *      return [0, 1].
 * *****************************************************************************/


#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < nums.size() ; i ++){
            int complete = target - nums[i];
            if(map.end() == map.find(complete)) {
                map[nums[i]] = i;
                cout << "add " << nums[i] << "'s index into map" << endl;
                continue;
            }
            return vector<int>({map[complete], i});
        }
        return vector<int>();
    }
};

int main(void)
{
    vector<int> nums({33,6,3,2,35,76,58,67,9,789,52,67,56,32});
    int target = 69;
    
    vector<int> result = Solution().twoSum(nums, target);

    cout << result[0] << ", " << result[1] << endl;

    return 0;
}
