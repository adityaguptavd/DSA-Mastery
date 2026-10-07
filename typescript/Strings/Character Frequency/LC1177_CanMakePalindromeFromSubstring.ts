function getOddCount(prefixFreq: Map<string, number>[], query: number[]) {
    const l = query[0],
        r = query[1];
    let oddCount = 0;
    for(let i = 0; i < 26; ++i) {
        const rightFreq = prefixFreq[r + 1].get(String.fromCharCode(i + 97)) ?? 0;
        const leftFreq = prefixFreq[l].get(String.fromCharCode(i + 97)) ?? 0;
        if((rightFreq - leftFreq) % 2 !== 0) {
            ++oddCount;
        }
    }
    return oddCount;
}

function canMakePaliQueries(s: string, queries: number[][]): boolean[] {
    const prefixFreq: Map<string, number>[] = [];
    prefixFreq.push(new Map<string, number>());
    for(const c of s) {
        const currentPrefix = new Map<string, number>(prefixFreq.at(-1));
        const freq = currentPrefix.get(c) ?? 0;
        currentPrefix.set(c, freq + 1);
        prefixFreq.push(currentPrefix);
    }
    const queryResults: boolean[] = [];
    for(const query of queries) {
        const k = query[2];
        const oddCount = getOddCount(prefixFreq, query);
        queryResults.push((oddCount - 2 * k) <= 1);
    }
    return queryResults;
};
