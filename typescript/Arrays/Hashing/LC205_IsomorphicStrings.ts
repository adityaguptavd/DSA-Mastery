function isIsomorphic(s: string, t: string): boolean {
    if(s.length === 1) return true;
    // create two hashmaps
    const s_mp = new Map<string, string>();
    const t_mp = new Map<string, string>();

    for(let i = 0; i < s.length; i++) {
        const s_exists = s_mp.get(s[i]);
        const t_exists = t_mp.get(t[i]);
        if(!s_exists && !t_exists) {
            s_mp.set(s[i], t[i]);
            t_mp.set(t[i], s[i]);
        }
        else if(s_exists && t_exists) {
            if(s_exists !== t[i] || t_exists !== s[i]) return false;
        }
        else return false;
    }
    return true;
};