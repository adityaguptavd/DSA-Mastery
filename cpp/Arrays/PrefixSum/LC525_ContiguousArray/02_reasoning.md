Learning Journal:
    Input:
        - binary array nums
        - nums[i] is either 0 or 1

    Output:
        - length of longest subarray that has equal number of zeros and ones
        - only non-negative value
        - single value
        - multiple subarrays of same length can be possible

    Edge Cases:
        - No subarray exists that has equal zeros and ones
        - Size of array is 1
        - Contains all zeros
        - Contains all ones

    Brute Force:
        - initialize max_length_subarray = 0
        - for ith element in nums:
            - initialize freq = 0
            - for jth (starting with i) element in nums:
                - decrement freq if zero encountered and increment if one is encountered
                - wherever freq become zero update:
                    - max_length_subarray = max(max_length_subarray, j - i + 1)
                - continue until j reaches end of nums

            - continue until i reaches end of nums
        - finally return max_length_subarray

    Time Complexity:
        Time: O(n^2)
        Space: O(1)

    Repeated Work:
        - We are incrementing and decrementing freq based on occurrence of zeros and ones again and again for each element while iterating
    
    Information to Remember:
        - On encountering zero we are adding -1 while for one we are adding +1.
        - This is becoming continuous sum of -1 and +1 based on zeros and ones.
        - Kind of prefix sum but involves only addition of -1 and +1.
        - Now if a prefix sum is 0, then that means we have encountered equal number of zeroes and ones since first element
        - If prefix sum of two distinct indices are equal, then that means we the elements between them has sum equal to 0 which means equal number of zeroes and ones
        - If we somehow know index of the first occurrence of this exact prefix sum, we will clrealy know the subarray between these two indices will have equal number of zeroes and ones.

    Pattern:
        - Prefix Sum -> First occurrence Index
        - Prefix Sum + HashMap