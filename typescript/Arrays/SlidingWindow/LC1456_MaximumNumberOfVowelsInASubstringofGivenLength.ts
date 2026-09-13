function maxVowels(s: string, k: number): number {
    const isVowel = (c: string): number =>
        "aeiou".includes(c) ? 1 : 0;

    let currentVowelCount = 0;

    // First window
    for (let i = 0; i < k; i++) {
        currentVowelCount += isVowel(s[i]);
    }

    let maxVowelCount = currentVowelCount;

    // Sliding window
    for (let right = k; right < s.length; right++) {
        currentVowelCount -= isVowel(s[right - k]);
        currentVowelCount += isVowel(s[right]);

        maxVowelCount = Math.max(maxVowelCount, currentVowelCount);
    }

    return maxVowelCount;
}
