#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int num_of_subarrays = 0, prefix_sum = 0;
        unordered_map<int, int> rem_freq_mp({{ 0, 1 }});
        for(int elem: nums) {
            prefix_sum += elem;
            int r = (prefix_sum % k + k) % k;
            num_of_subarrays += rem_freq_mp[r];
            ++rem_freq_mp[r];
        }
        return num_of_subarrays;
    }
};