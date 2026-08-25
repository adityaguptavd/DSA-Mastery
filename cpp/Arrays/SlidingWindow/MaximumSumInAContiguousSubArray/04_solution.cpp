#include<iostream>
#include<vector>
#include<limits>

using namespace std;

class Solution {
    public:
        long long maximumSumInASubArray(vector<int> numbers, size_t k) {
            if(k == 0 || k > numbers.size()) return numeric_limits<long long>::lowest();
            size_t left = 0, right = k - 1;
            // calculate current window sum
            long long current_sum = 0;
            for (size_t i = 0; i <= right; ++i) {
                current_sum += numbers[i];
            }
            // initialize max_sum with current_sum
            long long max_sum = current_sum;
            ++left; ++right;
            while(right < numbers.size()) {
                // find current window sum
                current_sum = current_sum - numbers[left - 1] + numbers[right];
                // update max
                max_sum = max(current_sum, max_sum);
                // shift the fixed sized window of size k
                ++left; ++right;
            }
            return max_sum;
        }
};