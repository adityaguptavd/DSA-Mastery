class RangeFreqQuery {
    unordered_map<int, vector<int>> idx_map;

    int firstOccurrenceInRange(const vector<int> &arr, int key) {
        int left = 0;
        int right = static_cast<int>(arr.size());
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] >= key) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    int lastOccurrenceInRange(const vector<int> &arr, int key) {
        int left = 0;
        int right = static_cast<int>(arr.size());
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] > key) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        int arr_size = static_cast<int>(arr.size());
        for(int i = 0; i < arr_size; ++i) {
            idx_map[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        const auto& it = idx_map.find(value);
        if(it == idx_map.end()) return 0;
        const auto& indices = it->second;
        int lower_bound = firstOccurrenceInRange(indices, left);
        int upper_bound = lastOccurrenceInRange(indices, right);
        return upper_bound - lower_bound;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
