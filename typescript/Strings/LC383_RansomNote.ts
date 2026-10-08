function canConstruct(ransomNote: string, magazine: string): boolean {
    const freq: number[] = new Array(26).fill(0);

    for (const c of magazine) {
        ++freq[c.charCodeAt(0) - 97];
    }

    for (const c of ransomNote) {
        const index = c.charCodeAt(0) - 97;

        if (freq[index] === 0) {
            return false;
        }

        --freq[index];
    }

    return true;
}
