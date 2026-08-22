function twoSum(numbers: number[], target: number): number[] {
    let L = 0, R = numbers.length - 1;
    while(L < R) {
        const sum = numbers[L] + numbers[R];
        if(sum > target) --R;
        else if(sum < target) ++L;
        else break;
    }
    return [L + 1, R + 1];
};