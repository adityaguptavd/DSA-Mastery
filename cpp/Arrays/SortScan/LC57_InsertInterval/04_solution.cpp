class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // create output intervals array
        vector<vector<int>> new_merged_intervals;
        for(size_t i = 0; i < intervals.size(); ++i) {
            // if new interval is completely before interval
            if(newInterval[1] < intervals[i][0]) {
                // push new interval
                new_merged_intervals.push_back(newInterval);
                // copy remaining intervals and finish
                for(size_t j = i; j < intervals.size(); ++j) {
                    new_merged_intervals.push_back(intervals[j]);
                }
                return new_merged_intervals;
            }
            // if new interval is completely after interval
            else if(newInterval[0] > intervals[i][1]) {
                // push current interval
                new_merged_intervals.push_back(intervals[i]);
            }
            // else if overlapping
            else {
                // expand newInterval by merging into interval
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        new_merged_intervals.push_back(newInterval);
        return new_merged_intervals;
    }
};