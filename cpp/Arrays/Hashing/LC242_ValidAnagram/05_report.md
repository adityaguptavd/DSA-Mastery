Problem:
    LC242 - Valid Anagram
Pattern:
    HashMap (Frequency Counting)
Difficulty:
    Easy
Implementation:
    - Two-pass HashMap with early exit
    - Single-pass increment/decrement solution
Mistakes:
    - Initially wrote:
        if(s != t) instead of if(s.length != t.length)
        implementation slip, not conceptual
    - Initially wrote frequency = 0 instead of frequency = 1 while designing algorithm
    - Added a final frequency verification in Algorithm 2 which is correct but unnecessary because the early-exit logic already guarantees correctness.
Lesson:
    - HashMaps are not only used to remember whether something exists or where it exists
    - They can also maintain frequencies.
    - Whenever a problem asks:
        "How many times does each element appear?"
        Think: Element -> Frequency