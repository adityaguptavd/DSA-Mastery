function isAlienSorted(words: string[], order: string): boolean {
    const orderLen = order.length;
    const totalWords = words.length;

    const rank: number[] = new Array(26).fill(0);

    for (let i = 0; i < orderLen; ++i) {
        rank[order.charCodeAt(i) - 97] = i;
    }

    for (let i = 0; i < totalWords - 1; ++i) {
        const currWord = words[i];
        const nextWord = words[i + 1];

        const currWordLen = currWord.length;
        const nextWordLen = nextWord.length;

        const smallerLen = Math.min(currWordLen, nextWordLen);

        let isSamePrefix = true;

        for (let j = 0; j < smallerLen; ++j) {
            const currRank = rank[currWord.charCodeAt(j) - 97];
            const nextRank = rank[nextWord.charCodeAt(j) - 97];

            if (currRank > nextRank) {
                return false;
            } else if (currRank < nextRank) {
                isSamePrefix = false;
                break;
            }
        }

        if (
            isSamePrefix &&
            currWordLen !== nextWordLen &&
            smallerLen === nextWordLen
        ) {
            return false;
        }
    }

    return true;
}
