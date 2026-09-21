class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals based on start
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        // initialize output array
        vector<vector<int>> merged_intervals;
        // track current merged interval
        vector<int> current_merged_interval = intervals[0];
        for(size_t i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= current_merged_interval[1]) {
                current_merged_interval[1] = max(current_merged_interval[1], intervals[i][1]);
            }
            else {
                merged_intervals.push_back(current_merged_interval);
                current_merged_interval = intervals[i];
            }
        }
        merged_intervals.push_back(current_merged_interval);
        return merged_intervals;
    }
};