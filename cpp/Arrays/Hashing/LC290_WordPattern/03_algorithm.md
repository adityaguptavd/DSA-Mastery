Optimized Algorithm:
- split given string s into array of words
- if words.length != pattern.length return false
- create two hashmaps wtp and ptw
- for each character in pattern p:
    - if p[i] exists in ptw and words[i] exists in wtp:
        - if p[i]'s mapping != words[i] or words[i]'s mapping != p[i], immediately return false
    - else if both doesn't exist: store p[i] -> words[i] and words[i] -> p[i] in ptw and wtp respectively
    - else invalid mapping, immediately return false
- finally return true