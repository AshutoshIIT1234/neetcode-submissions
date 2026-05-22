class Solution {
   public:
    bool isPalindrome(string s) {
        string filter_s;
       
        for (char c : s) {
            if (isalnum(c)) {
                filter_s.push_back(tolower(c));
            }
        }
        int n = filter_s.size();
        for (int i = 0; i < n; i++) {
            if (filter_s[i] != filter_s[n - 1]) return false;
            n--;
        }
        return true;
    }
};
