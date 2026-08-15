function isCovered(ranges: number[][], left: number, right: number): boolean {
    const diff: number[] = Array(52).fill(0);
    for(const [start, end] of ranges) {
        ++diff[start];
        --diff[end + 1];
    }
    let current = 0;
    for(let i = 0; i <= 50; ++i) {
        current += diff[i];
        if(
            i >= left &&
            i <= right &&
            current === 0
        ) {
            return false;
        }
    }
    return true;
};