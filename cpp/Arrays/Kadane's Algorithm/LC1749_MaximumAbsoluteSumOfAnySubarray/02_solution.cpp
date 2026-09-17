class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_ending = 0, min_ending = 0, best_so_far = 0;
        for(int n: nums) {
            max_ending = max(max_ending + n, n);
            min_ending = min(min_ending + n, n);
            best_so_far = max({
                best_so_far,
                abs(max_ending),
                abs(min_ending)
            });
        }
        return best_so_far;
    }
};