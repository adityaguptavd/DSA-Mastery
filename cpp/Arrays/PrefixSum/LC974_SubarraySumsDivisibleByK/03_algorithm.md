Optimized Algorithm:
    - Create a rem_freq hashmap and initialize with {0->1}
    - Initialize num_of_subarrays = 0
    - Initialize running_prefix_sum = 0
    - Iterate over nums array and update running_prefix_sum as:
        - running_prefix_sum += curr_elem
        - calculate remainder r = (running_prefix_sum % k + k) % k
        - if r exists in rem_freq:
            - num_of_subarrays += rem_freq[r]
            - increment rem_freq[r]
        - else store rem_freq[r] as 1

    - finally return num_of_subarrays

Complexity:
    Time: O(n)
    Space: O(min(n, k))