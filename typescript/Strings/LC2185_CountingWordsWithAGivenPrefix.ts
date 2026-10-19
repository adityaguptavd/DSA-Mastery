// Approach A: Using startsWith() for readability
function prefixCount(words: string[], pref: string): number {
    let count = 0;
    for (const word of words) {
        if (word.startsWith(pref)) {
            count++;
        }
    }
    return count;
}

// Approach B: Functional style single-liner
function prefixCountFunctional(words: string[], pref: string): number {
    return words.filter(word => word.startsWith(pref)).length;
}
