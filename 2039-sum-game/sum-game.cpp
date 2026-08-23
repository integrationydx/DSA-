class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int aliceSum = 0;
        int bobSum = 0;

        int aliceQ = 0;
        int bobQ = 0;

      
        for(int i = 0; i < n / 2; i++)
        {
            if(num[i] == '?')
                aliceQ++;
            else
                aliceSum += num[i] - '0';
        }

       
        for(int i = n / 2; i < n; i++)
        {
            if(num[i] == '?')
                bobQ++;
            else
                bobSum += num[i] - '0';
        }

        
        if((aliceQ + bobQ) % 2 == 1)
            return true;

        int diff = aliceSum - bobSum;
        int qdiff = bobQ - aliceQ;

       
        if(diff == 9 * (qdiff / 2))
            return false;

        return true;
    }
};