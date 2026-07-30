Learning Journal:
    Input:
        - string s
        - lowercase english letters
        - non-empty (based on constraints)

    Output:
        - index of first non-repeating character
        - -1 if none such element exists
        - single value

    Edge Cases:
        - string contains exactly one element
        - every character in string is repeated
        - none element is repeated
        - all element is same "aaaaa"
        - more than one non-repeating character present
        
    Brute Force:
        - if size is 1 -> return 0
        - for each character c in string s:
            - find occurrences of c in s
            - if at least one index is found where c is present other than current index, skip searching for c and move to next character in s
            - after searching complete -> return current index
        - finally return -1
    
    Complexity:
        Time: O(n^2)
        Space: O(1)

    Constraints:
        - 1 <= s.length <= 10^5
        - s consists of only lowercase English letters.
        - we need more optimized solution like O(nlogn) or O(n) 
    
    Repeated Work:
        - we are scanning whole string again and again for each character in string s

    Information to Remember:
        - we need to check whether we have already scanned this character or not
        - we require to store frequency, so that we can check which element appears only once and return its index

    Pattern:
        - element -> freq mapping
        - HashMap best fits here