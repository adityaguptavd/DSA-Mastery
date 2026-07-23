Problem:
    LC205 - Isomorphic Strings
Pattern:
    HashMap (Bidirectional character mapping)
Difficulty:
    Easy
Implementation:
    - Designed an efficient O(n) solution using two HashMaps
    - Maintained the invariant:
        s -> t and t -> s throughout the traversal
Mistakes:
    - Minor implementation slip:
        wrote === instead of ==
Lesson:
    - Whenever a problem describes replacing or transforming one object into another, first ask:
        - Is the mapping one-way, or must it be one-to-one?
        - If the mapping must be one-to-one, verify both directions.