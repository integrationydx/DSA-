class Solution {
public:
    char repeatedCharacter(string s) {
  for (int high = 1; high < s.size(); high++) {
    for (int low = 0; low < high; low++) {
        if (s[low] == s[high])
            return s[high];
    }
}
return -1;
    }
};