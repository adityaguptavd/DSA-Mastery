Problem:
    LC290 - Word Pattern
Pattern:
    HashMap (Bidirectional)
Difficulty:
    Easy
Implementation:
    - A valid mapping requires:
        pattern character <--> word
Mistakes:
    - Minor implementation slip:
        wrote === instead of ==
Lesson:
    - Whenever a problem describes replacing or transforming one object into another, first ask:
        - Is the mapping one-way, or must it be one-to-one?
        - If the mapping must be one-to-one, verify both directions.