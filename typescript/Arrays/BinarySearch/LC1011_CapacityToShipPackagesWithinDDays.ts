function canShip(weights: number[], days: number, capacity: number): boolean {
    let requiredDays = 1;
    let remainingCapacity = capacity;
    for(const w of weights) {
        if(remainingCapacity >= w) {
            remainingCapacity -= w;
        }
        else {
            ++requiredDays;
            remainingCapacity = capacity - w;
        }
    }
    return requiredDays <= days;
};

function shipWithinDays(weights: number[], days: number): number {
    // find max and total weights
    let maxPackageWeight = 0;
    let totalWeights = 0;
    for(const w of weights) {
        maxPackageWeight = Math.max(maxPackageWeight, w);
        totalWeights += w;
    }
    // initialize binary search and its boundary
    let left = maxPackageWeight, right = totalWeights;
    while(left < right) {
        let mid = left + Math.floor((right - left) / 2);
        if(canShip(weights, days, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
};
