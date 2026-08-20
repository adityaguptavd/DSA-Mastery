/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    let L: number = -1, R: number = s.length;
    let temp: string;
    while(++L < --R) {
        temp = s[L];
        s[L] = s[R];
        s[R] = temp;
    }
};