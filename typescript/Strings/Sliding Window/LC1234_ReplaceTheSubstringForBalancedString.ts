function balancedString(s: string): number {
    function getIndex(c: string): number {
        switch (c) {
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
            case 'R':
                return 3;
            default:
                return -1;
        }
    }

    const sLen = s.length;
    const winFreq: number[] = new Array(4).fill(0);
    const outsideFreq: number[] = new Array(4).fill(0);

    const reqFreq = sLen / 4;
    let outsideInvalidFreq = 0;

    for (const c of s) {
        if (++outsideFreq[getIndex(c)] === reqFreq + 1) {
            ++outsideInvalidFreq;
        }
    }

    if (outsideInvalidFreq === 0) return 0;

    let minimumReplaceableSubstringLength = Number.MAX_SAFE_INTEGER;
    let left = 0, right = 0;

    while (right < sLen) {
        if (--outsideFreq[getIndex(s[right])] === reqFreq) {
            --outsideInvalidFreq;
        }

        while (left <= right && outsideInvalidFreq === 0) {
            minimumReplaceableSubstringLength = Math.min(
                minimumReplaceableSubstringLength,
                right - left + 1
            );

            if (++outsideFreq[getIndex(s[left])] === reqFreq + 1) {
                ++outsideInvalidFreq;
            }

            ++left;
        }

        ++right;
    }

    return minimumReplaceableSubstringLength === Number.MAX_SAFE_INTEGER
        ? 0
        : minimumReplaceableSubstringLength;
}
