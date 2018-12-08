/********************************************************************************
 * Given a string, find the length of the longest substring without repeating 
 * characters.
 * Example 1:
 *      Input: "abcabcbb"
 *      Output: 3 
 *
 *      Explanation: The answer is "abc", with the length of 3. 
 *
 *      
 * Example 2:
 *      Input: "bbbbb"
 *      Output: 1
 *
 *      Explanation: The answer is "b", with the length of 1.
 *
 * 
 * Example 3:
 *      Input: "pwwkew"
 *      Output: 3
 *
 *      Explanation: The answer is "wke", with the length of 3. Note that the 
 *      answer must be a substring, "pwke" is a subsequence and not a substring.
 * *****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;
using std::string;


class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        size_t slen = s.size();
        if(slen < 2){
            return slen;
        }

        vector<int> map(256, -1);
        size_t index = 0;
        size_t start = 0;
        size_t max = 0;
        size_t tmp;

        for(index = 0 ; index < slen ; index ++){
            int pos = map[s[index]];
            if(pos >= 0){
                tmp = index - start;
                if(tmp > max){
                    max = tmp;
                }
                tmp = pos + 1;
                if(tmp > start){
                    start = tmp;
                }
            }
            map[s[index]] = index;
        }
        
        tmp = index - start;
        if(tmp > max){
            max = tmp;
        }

        return max;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        size_t index = 0;
        size_t start = 0;
        size_t max = 0;
        size_t tmp = 0;
        size_t slen = 0;

        slen = s.size();
        if(slen < 2){
            return slen;
        }

        for(index = 0 ; index < s.size() ; index ++){
            auto itr = map.find(s[index]);
            if( itr != map.end()){
                tmp = index - start;
                if(max < tmp){
                    max = tmp;
                    //cout << "tmp max: " << max << endl;
                }
                tmp = itr->second + 1;
                if(start < tmp){
                    start = tmp;
                }
                //cout << "set start to " << start << endl;
            }
            map[s[index]] = index;
            //cout << start << ", " << index << endl;
        }

        tmp = index - start;
        if(max < tmp){
            max = tmp;
            //cout << "final max: " << max << endl;
        }

        return max;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    Solution1 solution1;

    cout << solution.lengthOfLongestSubstring(argv[1]) << endl;
    cout << solution1.lengthOfLongestSubstring(argv[1]) << endl;

    return 0;
}

