class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_in_string;
        nums_in_string.reserve(nums.size());
        for(int n: nums) {
            nums_in_string.push_back(to_string(n));
        }
        auto compare = [](const string& a, const string& b) -> bool {
            return a + b > b + a;
        };
        stable_sort(nums_in_string.begin(), nums_in_string.end(), compare);
        if(nums_in_string.empty() || nums_in_string[0] == "0") {
            return "0";
        }
        string largest_number;
        for(string& s: nums_in_string) {
            largest_number += s;
        }
        return largest_number;
    }
};
