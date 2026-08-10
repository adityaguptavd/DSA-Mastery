#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0), diff(length + 1, 0);
        // build diff array
        for(auto update: updates) {
            int start_index = update[0];
            int end_index = update[1];
            int inc = update[2];

            diff[start_index] += inc;
            diff[end_index + 1] -= inc;
        }
        // reconstruct result array
        int current = 0;
        for(int i = 0; i < length; ++i) {
            current += diff[i];
            result[i] = current;
        }
        return result;
    }
};