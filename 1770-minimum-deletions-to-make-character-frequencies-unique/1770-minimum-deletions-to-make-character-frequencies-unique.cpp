class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for (char c : s) {
            v[c - 'a']++;
        }
        int c = 0;
        unordered_set<int> set;
        for (int i = 0; i < 26; i++) {
            while (v[i] && set.find(v[i]) != set.end()) {
                v[i]--;
                c++;
            }
            set.insert(v[i]);
        }
        return c;
    }
};