function getAbsDiff(a: string, b: string): number {
    return Math.abs(a.charCodeAt(0) - b.charCodeAt(0));
}

function equalSubstring(s: string, t: string, maxCost: number): number {
    let left = 0, right = 0;
    let currentBudget = 0;
    let maxSubstringLength = 0;
    while(right < s.length) {
        currentBudget += getAbsDiff(s[right], t[right]);
        while(left <= right && currentBudget > maxCost) {
            currentBudget -= getAbsDiff(s[left], t[left]);
            ++left;
        }
        maxSubstringLength = Math.max(maxSubstringLength, right - left + 1);
        ++right;
    }
    return maxSubstringLength;
};
