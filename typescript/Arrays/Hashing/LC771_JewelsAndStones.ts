function numJewelsInStones(jewels: string, stones: string): number {
    const jewelsSet = new Set<string>();
    let counter = 0;
    // build hashset from jewels
    for(const j of jewels) {
        jewelsSet.add(j);
    }

    // count stones that are jewels
    for(const s of stones) {
        if(jewelsSet.has(s)) ++counter;
    }
    return counter;
};