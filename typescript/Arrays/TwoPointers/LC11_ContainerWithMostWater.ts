function maxArea(height: number[]): number {
    // create two pointers
    let L = 0, R = height.length - 1;
    let max_water_volume = 0;
    while(L < R) {
        // compute volume
        let current_water_volume = Math.min(height[L], height[R]) * (R - L);
        // update max volume
        max_water_volume = Math.max(max_water_volume, current_water_volume);
        if(height[L] < height[R]) ++L;
        else --R;
    }
    return max_water_volume;
};