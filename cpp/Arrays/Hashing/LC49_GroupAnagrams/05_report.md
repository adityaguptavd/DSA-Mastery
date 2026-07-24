Problem:
    LC49 Group Anagrams
Pattern:
    HashMap + Canonical Representation
Difficulty:
    Medium
Complexity:
    Time: O(n * klogk)
    Space: O(n)
Mistakes:
    - Initially tried
        unordered_map<unordered_map<char, int>, size_t>
    - Not directly usable because the key type itself isn't hashable by default.
    - This wasn't a conceptual mistake. It was a representational issue.
Lesson:
    Choosing the right HashMap key is often the hardest part of a HashMap problem. A good key should be canonical: equivalent objects map to the same key, and non-equivalent objects map to different keys.