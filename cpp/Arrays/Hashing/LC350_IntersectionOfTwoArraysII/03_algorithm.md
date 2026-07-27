Optimized Algorithm:
    - Create a HashMap mp(int, int)
    - create result array
    - We have two options for traversing:
        - we can traverse both arrays in parallel (but have to handle carefully if one array finishes early)
        - we can traverse both arrays one by one (will chose this for simplicity)
    - We'll traverse either array first (say nums1)
    - store element -> frequency in hashmap: mp[nums1[i]]++
    - Then start traversing second array (say nums2)
    - for each element:
        - if it is present in hashmap mp and mp[nums2[i]] > 0:
            - mp[nums2[i]]--
            - push nums2[i] into result array
        - else skip
    - finally return result array
    
Complexity:
    Time: O(n + m) -> O(max(n, m)), where n is nums1 size and m is nums2 size
    Space: O(max(k, k')), where k and k' are distinct elements in nums1 and nums2