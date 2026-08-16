function shiftAndNormalize(value: string, shift: number = 0): string {
    const left: number = 97, right: number = 122;
    const range: number = right - left + 1;
    const shifted_value_in_ascii: number = value.charCodeAt(0) + shift;
    return String.fromCharCode((left + (((shifted_value_in_ascii - left) % range) + range) % range));
}

function shiftingLetters(s: string, shifts: number[][]): string {
    const s_size = s.length;
    const netShift: number[] = Array(s_size + 1).fill(0);
    for(const [start, end, dir] of shifts) {
        const shiftValue = dir === 0 ? -1: 1;
        netShift[start] += shiftValue;
        netShift[end + 1] -= shiftValue;
    }
    let currentShift = 0;
    let finalString: string = "";
    for(let i = 0; i < s_size; ++i) {
        currentShift += netShift[i];
        finalString += shiftAndNormalize(s[i], currentShift);
    }
    return finalString;
};