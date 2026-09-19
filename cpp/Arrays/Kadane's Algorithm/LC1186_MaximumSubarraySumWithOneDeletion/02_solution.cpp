class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int bestWithDeletion = numeric_limits<int>:: min(),
            bestWithoutDeletion = arr[0],
            bestSoFar = arr[0];

        for(size_t i = 1; i < arr.size(); ++i) {
            if(bestWithDeletion == numeric_limits<int>:: min()) {
                bestWithDeletion = max({
                    arr[i],
                    bestWithoutDeletion
                });
            }
            else {
                bestWithDeletion = max({
                    bestWithDeletion + arr[i],
                    bestWithoutDeletion
                });
            }
            bestWithoutDeletion = max({
                bestWithoutDeletion + arr[i],
                arr[i]
            });
            bestSoFar = max({
                bestSoFar,
                bestWithDeletion,
                bestWithoutDeletion
            });
        }
        return bestSoFar;
    }
};