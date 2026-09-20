function findAnagrams(s: string, p: string): number[] {
    function updateFrequencies(
        patternFreq: number[],
        windowFreq: number[],
        key: string,
        updateValue: number,
        matchedFrequencies: number
    ): number {
        const index = key.charCodeAt(0) - 97;

        const oldFreq = windowFreq[index];
        windowFreq[index] += updateValue;

        const newFreq = windowFreq[index];
        const reqFreq = patternFreq[index];

        if (reqFreq > 0) {
            if (oldFreq === reqFreq) {
                --matchedFrequencies;
            } else if (newFreq === reqFreq) {
                ++matchedFrequencies;
            }
        }

        return matchedFrequencies;
    }

    const anagramIndices: number[] = [];

    const m = p.length;
    const n = s.length;

    if (m > n) return anagramIndices;

    let requiredFrequencies = 0;

    const patternFreq: number[] = new Array(26).fill(0);

    for (const c of p) {
        const index = c.charCodeAt(0) - 97;

        if (++patternFreq[index] === 1) {
            ++requiredFrequencies;
        }
    }

    const windowFreq: number[] = new Array(26).fill(0);

    let left = 0;
    let right = m - 1;
    let matchedFrequencies = 0;

    for (let i = 0; i <= right; ++i) {
        matchedFrequencies = updateFrequencies(
            patternFreq,
            windowFreq,
            s[i],
            1,
            matchedFrequencies
        );
    }

    if (matchedFrequencies === requiredFrequencies) {
        anagramIndices.push(left);
    }

    ++left;
    ++right;

    while (right < n) {
        matchedFrequencies = updateFrequencies(
            patternFreq,
            windowFreq,
            s[left - 1],
            -1,
            matchedFrequencies
        );

        matchedFrequencies = updateFrequencies(
            patternFreq,
            windowFreq,
            s[right],
            1,
            matchedFrequencies
        );

        if (matchedFrequencies === requiredFrequencies) {
            anagramIndices.push(left);
        }

        ++left;
        ++right;
    }

    return anagramIndices;
}
