class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // find maximum pile size
        int max_pile_size = 0;
        for(int p: piles) {
            max_pile_size = max(max_pile_size, p);
        }
        // search for the feasible solution over the range [1, max_pile_size] using binary search
        int left = 1, right = max_pile_size;
        while(left < right) {
            int mid = left + (right - left) / 2;
            // calculate total hours required with speed mid
            int hours = 0;
            for(int pile: piles) {
                hours += (pile / mid) + (pile % mid != 0);
            }
            if(hours <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};