Optimized Algorithm:
    - minEnding = maxEnding = bestSoFar = totalSum = nums[0]
    - isAllNegative = true
    - for i = 1 to n - 1:
        - calculate minEnding, maxEnding, totalSum, minSoFar and bestSoFar
        - if nums[i] >= 0:
            - isAllNegative = false
    - if isAllNegative:
        - return bestSoFar
    - max(bestSoFar, totalSum - minSoFar)

Complexity:
    Time: O(n)
    Space: O(1)