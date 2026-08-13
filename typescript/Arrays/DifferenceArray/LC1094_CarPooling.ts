function carPooling(trips: number[][], capacity: number): boolean {
    const diff: number[] = Array(1001).fill(0);
    for(const [num_of_passengers, from, to] of trips) {
        diff[from] += num_of_passengers;
        diff[to] -= num_of_passengers;
    }
    let current = 0;
    for(let i = 0; i < 1000; ++i) {
        current += diff[i];
        if(current > capacity) return false;
    }
    return true;
};