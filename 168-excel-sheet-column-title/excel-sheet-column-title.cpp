class Solution {
public:
    string convertToTitle(int columnNumber) {
        int x = columnNumber;
        map<int, char> mp;

for (int i = 1; i <= 26; i++) {
    mp[i] = 'A' + (i - 1);
}
        string res = "";
        while(x>0)
        {
            x--;
         int y = x%26;
           res+= mp[y+1];
           x=x/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};