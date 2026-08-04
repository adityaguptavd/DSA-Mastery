class NumArray {
    private prefixSum: number[] = [];
    constructor(nums: number[]) {
        for(const elem of nums) {
            if(this.prefixSum.length === 0) {
                this.prefixSum.push(elem);
            }
            else {
                const lastPrefixSum: number = this.prefixSum.at(-1)!;
                this.prefixSum.push(lastPrefixSum + elem);
            }
        }
    }

    sumRange(left: number, right: number): number {
        if(left === 0) {
            return this.prefixSum[right];
        }
        return this.prefixSum[right] - this.prefixSum[left - 1];
    }
}