class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // fruits size
        int n = fruits.size();
        // initialize empty window
        int left = 0, right = 0;
        // initialize fruits collected type
        int basket_filled = 0;
        // hashmap for fruits collected by types
        unordered_map<int, int> fruits_collected;

        int max_size = 0;
        while(right < n) {
            ++fruits_collected[fruits[right]];
            if(fruits_collected[fruits[right]] == 1) {
                if(basket_filled == 2) {
                    max_size = max(max_size, right - left);
                    while(left < right) {
                        ++left;
                        if(--fruits_collected[fruits[left - 1]] == 0) {
                            --basket_filled;
                            break;
                        }
                    }
                }
                ++basket_filled;
            }
            ++right;
        }
        return max_size;
    }
};