Learning Journal:
    Input:
        - two integer arrays nums1 and nums2
        - duplicates possible
        - positive inetegers (according to constraints)
        - at least one element will be present (according to constraints)
        - may or may not be sorted

    Output:
        - array of common elements present in both
        - result can be in any order

    Edge Cases:
        - one array's size is less than other's
        - sorted array
        - both contains exactly one element
        - all the elements are common in both arrays
        - none element is common
        
    Brute Force:
        - pick one element from nums1 and search for its occurrence in both arrays
        - push min(freq_nums1, freq_nums2) times that element in result array
        - continue this for all elements in nums1
        - But there's a catch in this solution:
            - For repeated elements, we have to track which element we have already counted, since we may end up with duplicate entry for same element
            - So we have to skip visited elements
            - This has two solutions:
                - we may use hashset for existence checking
                - or we can replace the visited elements with -1 (since according to constraint 0 <= nums1[i], nums2[i] <= 1000)

    Complexity:
        - If nums1 size is n and nums2 size is m, then:
            Time: O(m*n)
            Space: O(1) if replacing with -1 otherwise for using hashset O(max(k, k')), where k and k' are distinct elements in nums1 and nums2

    Constraints:
        - 1 <= nums1.length, nums2.length <= 1000
        - 0 <= nums1[i], nums2[i] <= 1000
        - Current solution is acceptable, but we have room for improvements
    
    Repeated Work:
        - We are visiting same elements again and again

    Information to Remember:
        - We can store the existence and frequency of an element

    Pattern:
        - element -> frequency mapping (hashmap)