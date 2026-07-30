function wordPattern(pattern: string, s: string): boolean {
    // split string s
    const words = s.split(" ");
    if(words.length !== pattern.length) return false;
    // create two hashmaps for bi-directional mappings
    const patternToWordMap = new Map<string, string>();
    const wordToPatternMap = new Map<string, string>();
    for(let i = 0; i < pattern.length; ++i) {
        const patternInMap = patternToWordMap.get(pattern[i]);
        const wordInMap = wordToPatternMap.get(words[i]);
        if(patternInMap !== undefined && wordInMap !== undefined) {
            if(patternInMap !== words[i] || wordInMap !== pattern[i]) return false;
        }
        else if(patternInMap === undefined && wordInMap === undefined) {
            // store in hashmap
            patternToWordMap.set(pattern[i], words[i]);
            wordToPatternMap.set(words[i], pattern[i]);
        }
        // invalid mapping 
        else return false;
    }
    return true;
};
