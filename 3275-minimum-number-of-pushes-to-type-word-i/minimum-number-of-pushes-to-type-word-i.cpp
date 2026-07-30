class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        int n = word.size();
        for(int i=0;i<word.size();i++)
        {
           if(i <8) count+= 1;
           else if(i<16) count+= 2;
           else if(i<24) count+= 3;
           else 
           {
            count = count + 4;
           }
           
        }
        return count;
    }
};