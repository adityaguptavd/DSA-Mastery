class Solution {
public:
    string customSortString(string order, string s) {
        int order_len = static_cast<int>(order.length());
        // rank characters in order
        unordered_map<char, int> rank; // default rank 0
        for(int i = 0; i < order_len; ++i) {
            rank[order[i]] = i + 1; // ranking from 1
        }
        auto compare = [&rank](char a, char b) -> bool {
            return rank[a] < rank[b];
        };
        // sort s with custom comparison
        stable_sort(s.begin(), s.end(), compare);
        return s;
    }
};
