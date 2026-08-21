function isAlphanumericCode(s: string): boolean {
    const code = s.charCodeAt(0);
    const isNumeric = code >= 48 && code <= 57;   // 0-9
    const isUpperAlpha = code >= 65 && code <= 90; // A-Z
    const isLowerAlpha = code >= 97 && code <= 122; // a-z

    if (!isNumeric && !isUpperAlpha && !isLowerAlpha) {
      return false;
    }
  return true;
}


function isPalindrome(s: string): boolean {
    let L = 0, R = s.length - 1;
    while(L < R) {
        if(!isAlphanumericCode(s[L])) {
            ++L;
            continue;
        }
        if(!isAlphanumericCode(s[R])) {
            --R;
            continue;
        }
        if(s[L].toLowerCase() !== s[R].toLowerCase()) return false;
        ++L; --R;
    }
    return true;
};