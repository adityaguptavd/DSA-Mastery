Optimized Algorithm 1:
    - if s.length is not equal to t.length, return false
    - create two hashmaps: s_mp and t_mp
    - iterate both strings simultaneously
    - if current characters are present in their respective hashmaps, then increment frequency
    - else set character -> frequency with frequency = 1
    - finally compare characters' frequencies from both hashmaps and return true if equal otherwise false

Optimized Algorithm 2 (easy, simple and early exit possible but two pass requires in worst case):
    - if s.length is not equal to t.length, return false
    - create one hashmap: mp
    - iterate s
    - if current character is present in hashmap, then increment frequency
    - else set character -> frequency with frequency = 1
    - now iterate t
    - if current character is present in hashmap and character's frequency > 0, then decrement frequency
    - else return false
    - finally return true if all characters' frequence is zero at the end
    - else false

Optimized Algorithm 3 (no early exit, but one complete pass requires):
    - if s.length is not equal to t.length, return false
    - create one hashmap: mp
    - iterate s and t in one single pass
    - if current character is from s and present in hashmap, then increment frequency and if current character is from t and present in hashmap then decrement frequency
    - else set character -> frequency with frequency = 1 for s and frequency = -1 for t
    - finally return true if all characters' frequence is zero at the end
    - else false

Note:
    - Since the characters are only lowercase and alphabet is fixed to 26 letters, we can replace HashMap with a fixed size array for better constant factors.
    - Example: 
        int freq[26];
        freq[c - 'a']++;