class Solution {
    int find_left_candle(const vector<pair<int, int>> &candles, int key) {
        int low = 0, high = candles.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(candles[mid].first > key) {
                high = mid - 1;
            }
            else if(candles[mid].first < key) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        if(
            high + 1 >= 0 &&
            high + 1 < candles.size() &&
            candles[high + 1].first >= key
        ) {
            return high + 1;
        }
        return -1;
    }
    int find_right_candle(const vector<pair<int, int>> &candles, int key) {
        int low = 0, high = candles.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(candles[mid].first < key) {
                low = mid + 1;
            }
            else if(candles[mid].first > key) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        if(
            low - 1 >= 0 &&
            low - 1 < candles.size() &&
            candles[low - 1].first <= key
        ) {
            return low - 1;
        }
        return -1;
    }
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int s_len = static_cast<int>(s.size());
        vector<pair<int, int>> candles;
        vector<int> output;
        output.reserve(queries.size());
        int num_plates = 0;
        for(int i = 0; i < s_len; ++i) {
            if(s[i] == '*') {
                ++num_plates;
            }
            else {
                candles.push_back({ i, num_plates });
            }
        }
        for(const auto &query: queries) {
            int left_candle = find_left_candle(candles, query[0]);
            int right_candle = find_right_candle(candles, query[1]);
            if(left_candle == -1 || right_candle == -1 || left_candle > right_candle) {
                output.push_back(0);
            }
            else{
                output.push_back(
                    candles[right_candle].second - candles[left_candle].second
                );
            }
        }
        return output;
    }
};
