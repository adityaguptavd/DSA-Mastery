function checkInclusion(s1: string, s2: string): boolean {
    if (s1.length > s2.length) return false;

    // Build frequency map for s1
    const freq1: number[] = new Array(26).fill(0);
    let matchesRequired = 0;

    for (const c of s1) {
        const index = c.charCodeAt(0) - 'a'.charCodeAt(0);

        if (++freq1[index] === 1) {
            ++matchesRequired;
        }
    }

    // Initialize window for s2
    let left = 0;
    let right = s1.length - 1;

    let matchesFound = 0;

    // Build frequency map for window in s2
    const freq2: number[] = new Array(26).fill(0);

    for (let i = 0; i <= right; ++i) {
        const index = s2.charCodeAt(i) - 'a'.charCodeAt(0);

        const oldFreq = freq2[index];
        const newFreq = ++freq2[index];
        const s1Freq = freq1[index];

        if (s1Freq > 0) {
            if (oldFreq === s1Freq) {
                --matchesFound;
            } else if (newFreq === s1Freq) {
                ++matchesFound;
            }
        }
    }

    if (matchesFound === matchesRequired) {
        return true;
    }

    // Shift window
    ++left;
    ++right;

    const n = s2.length;

    while (right < n) {
        const leavingCharIndex =
            s2.charCodeAt(left - 1) - 'a'.charCodeAt(0);

        const enteringCharIndex =
            s2.charCodeAt(right) - 'a'.charCodeAt(0);

        const leavingCharOldFreq = freq2[leavingCharIndex];
        const leavingCharNewFreq = --freq2[leavingCharIndex];
        const leavingCharFreqS1 = freq1[leavingCharIndex];

        const enteringCharOldFreq = freq2[enteringCharIndex];
        const enteringCharNewFreq = ++freq2[enteringCharIndex];
        const enteringCharFreqS1 = freq1[enteringCharIndex];

        // Process leaving character
        if (leavingCharFreqS1 > 0) {
            if (leavingCharOldFreq === leavingCharFreqS1) {
                --matchesFound;
            } else if (leavingCharNewFreq === leavingCharFreqS1) {
                ++matchesFound;
            }
        }

        // Process entering character
        if (enteringCharFreqS1 > 0) {
            if (enteringCharOldFreq === enteringCharFreqS1) {
                --matchesFound;
            } else if (enteringCharNewFreq === enteringCharFreqS1) {
                ++matchesFound;
            }
        }

        if (matchesFound === matchesRequired) {
            return true;
        }

        ++left;
        ++right;
    }

    return false;
}
