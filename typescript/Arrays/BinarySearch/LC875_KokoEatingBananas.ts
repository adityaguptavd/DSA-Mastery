function canEatInTime(piles: number[], h: number, eatingSpeed: number): boolean {
    let requiredHours = 0;
    for(const p of piles) {
        requiredHours += Math.ceil(p / eatingSpeed);
    }
    return requiredHours <= h;
}

function minEatingSpeed(piles: number[], h: number): number {
    // max pile size
    let maxPileSize = 0;
    for(const p of piles) {
        maxPileSize = Math.max(maxPileSize, p);
    }
    // binary search and its initial boundary
    let left = 1, right = maxPileSize;
    while(left < right) {
        let mid = left + Math.floor((right - left) / 2);
        if(canEatInTime(piles, h, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
};
