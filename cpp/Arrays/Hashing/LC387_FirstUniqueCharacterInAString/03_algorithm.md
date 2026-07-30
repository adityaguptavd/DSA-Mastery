Optimized Algorithm:
- if size is 1 return 0
- create an occurrence hashmap to store elem -> freq
- for ith character in string s:
    - increament hashmap[s[i]]++

- again for ith character in string s:
    - if hashmap[s[i]] == 1 return i
- finally return -1