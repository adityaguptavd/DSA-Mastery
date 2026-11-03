class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto comp = [](const string& a, const string& b) -> bool {
            int a_del = a.find(' ');
            int b_del = b.find(' ');
            bool is_a_digit = isdigit(a[a_del + 1]);
            bool is_b_digit = isdigit(b[b_del + 1]);
            if(is_a_digit && is_b_digit) {
                return false;
            }
            if(!is_a_digit && is_b_digit) {
                return true;
            }
            if(is_a_digit && !is_b_digit) {
                return false;
            }
            string a_content = a.substr(a_del + 1);
            string b_content = b.substr(b_del + 1);
            if(a_content != b_content) {
                return a_content < b_content;
            }
            string a_id = a.substr(0, a_del);
            string b_id = b.substr(0, b_del);
            return a_id < b_id;
        };

        stable_sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};
