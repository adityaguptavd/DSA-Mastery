function reverseWords(s: string): string {
    let reverse: string = "";
    let i: number = s.length - 1;

    while (i >= 0) {
        // Skip trailing spaces
        while (i >= 0 && s[i] === ' ') {
            --i;
        }

        // Find the end and start of the word
        const end: number = i;

        while (i >= 0 && s[i] !== ' ') {
            --i;
        }

        // Construct the word
        let word: string = "";

        for (let j = i + 1; j <= end; ++j) {
            word += s[j];
        }

        // Append the word
        if (word.length > 0) {
            if (reverse.length === 0) {
                reverse = word;
            } else {
                reverse = reverse + ' ' + word;
            }
        }
    }

    return reverse;
}
