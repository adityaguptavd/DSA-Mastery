function groupAnagrams(strs: string[]): string[][] {
    const anagramsGroup: string[][] = [];
    const groupIndexMap = new Map<string, number>();
    for(const str of strs) {
        const sortedStr: string = str.split("").sort().join("");
        if(groupIndexMap.has(sortedStr)) {
            anagramsGroup[groupIndexMap.get(sortedStr)!].push(str);
        }
        else {
            groupIndexMap.set(sortedStr, anagramsGroup.length);
            anagramsGroup.push([str]);
        }
    }
    return anagramsGroup;
};