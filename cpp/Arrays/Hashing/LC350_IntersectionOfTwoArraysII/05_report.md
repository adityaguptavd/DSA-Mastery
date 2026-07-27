Problem:
    LC350 Intersection Of Two Arrays II
Pattern:
    HashMap + Frequency Counting
Difficulty:
    Easy
Complexity:
    Time: O(n + m)
    Space: O(k)
Mistakes:
    - Forgot to increment iterator if element not found in hashmap
Lesson:
    When building a frequency map from one of two collections, prefer the smaller collection whenever correctness is unchanged. This minimizes the maximum auxiliary space.