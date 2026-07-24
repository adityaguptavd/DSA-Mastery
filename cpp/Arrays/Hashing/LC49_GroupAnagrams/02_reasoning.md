Learning Journal:
    Input:
        - array of strings strs
        - array cannot be empty (according to contraints)
        - strings can be empty
        - lowercase english letters

    Output:
        - array of array of strings
        - single answer
        - order doesn't matter

    Edge Cases:
        - array contains exactly one string -> ["ab"]
        - array contains exactly one empty string -> [""]
        - array contains all the strings as anagrams -> ["abb", "bab"]
        - array contains same strings -> ["aba", "aba"]
        - array contains two strings with different lengths -> ["abc", "a"]
        - array contains all the strings as empty -> ["", "", ""]
        
    Brute Force:
        - given strs
        - if strs.length == 1 -> return [strs]
        - create array:
            group = [strs[0]]
        - iterate over the strs (say i) and and pick str: -> O(n)
                curr_str = strs[i]
                - iterate over group (say j)  and pick any one str (prefer 0th) from current group: -> O(n) in worst case
                    curr_group_str = group[j][0]
                    if curr_str.length != curr_group_str.length
                        move to next iteration of j
                    else
                        for each character in curr_str: -> O(k)
                            check all occurences in curr_str and increment count -> O(k)
                            check all occurence in curr_group_str and decrement count -> O(k)
                                if count becomes negative
                                    move to next iteration of j
                            if count is positive
                                move to next iteration of j
                            else
                                push curr_str into group[j]
                - if not pushed in any group (we can detect via a boolean flag), then push as a new group
        - finally return group

    
    Complexity:
        Time: O(n * n * k * (k + k)) = O(n^2 * k^2)
        Space: O(1) -> since group is expected to be created according to problem

    Constraints:
        - 1 <= strs.length <= 10^4 -> O(n*klogk) or O(n*k)
        - 0 <= strs[i].length <= 100
        - strs[i] consists of lowercase English letters.
    
    Repeated Work:
        - Each group strings are being counted repeatedly for each string in strs
        - At character level comparison, we are repeatedly counting characters in both strings (strs[i] and group[j][0])

    Information to Remember:
        - We have already fixed second repetation in LC242.
        - This leads to O(k) time complexity for character level comparison.
        - But we still have issue of O(n^2) for outer group iteration and strs iteration
        - If we somehow know that a group with current string's exact frequency mapping exists at what index, then we don't have to traverse through group array.
        - This can be achieved if we store information in the way like:
            {{a -> 2, b -> 3} -> index_in_group}, something like unordered_map<unordered_map<char, int>, size_t>. If doesn't exist, the set {current_mapping -> group_size_as_index) and also push that string as new group in group array
        - This will avoid traversing group array with the trade off memory
        - But the problem is that we unordered_map isn't a thing that can be hashed. So we have to try for another approach
        - Instead of focusing on frequency, we can focus on direct string comparison since k << n.
        - We first copy and sort current string then check if it already exists in a hashmap/hashset.
        - If exists, then pick the corresponding mapped index and push the current string at that index array.
        - If doesn't exist then store { sorted_string -> group_size_as_index } and then push current string into the group array.
    
    Complexity:
        Time: O(n*(klogk + k)) -> k for copying and klogk for sorting
        Space: O(n) for storing group's hashmaps(sorted_string -> index)

    Pattern:
        - Hashmap, since we have to store mapping of sorted_string to index in group