function totalFruit(fruits: number[]): number {
    // intiate window's left boundary
    let left = 0;
    // intialize filled basket
    let filled_baskets = 0;
    // max size
    let max_size = 0;
    // initalize fruits collected
    const fruits_collected = new Map<number, number>();
    // intialize right boundary and expand
    for(let right = 0; right < fruits.length; ++right) {
        const fruit_in_basket = fruits_collected.get(fruits[right]) ?? 0;
        fruits_collected.set(fruits[right], fruit_in_basket + 1);
        if(filled_baskets === 2) {
            if(fruit_in_basket === 0) {
                while(left < right) {
                    ++left;
                    let leaving_fruit_in_basket = fruits_collected.get(fruits[left - 1]) ?? 0;
                    --leaving_fruit_in_basket;
                    fruits_collected.set(fruits[left - 1], leaving_fruit_in_basket);
                    if(leaving_fruit_in_basket === 0) {
                        break;
                    }
                }
            }
        }
        else {
            if(fruit_in_basket === 0) {
                ++filled_baskets;
            }
        }
        max_size = Math.max(max_size, right - left + 1);
    }
    return max_size;
};
