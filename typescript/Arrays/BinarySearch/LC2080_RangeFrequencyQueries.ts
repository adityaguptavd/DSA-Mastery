class RangeFreqQuery {
    idxMap = new Map<number, number[]>();
    constructor(arr: number[]) {
        arr.forEach((num, i) => {
            const indices = this.idxMap.get(num) ?? [];
            indices.push(i);
            this.idxMap.set(num, indices);
        });
    }

    lowerBound(indices: number[], key: number): number {
        let left = 0, right = indices.length;
        while(left < right) {
            let mid = left + Math.floor((right - left) / 2);
            if(indices[mid] >= key) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    upperBound(indices: number[], key: number): number {
        let left = 0, right = indices.length;
        while(left < right) {
            let mid = left + Math.floor((right - left) / 2);
            if(indices[mid] > key) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    query(left: number, right: number, value: number): number {
        const indices = this.idxMap.get(value);
        if(!indices) return 0;
        return this.upperBound(indices, right) - this.lowerBound(indices, left);
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */
