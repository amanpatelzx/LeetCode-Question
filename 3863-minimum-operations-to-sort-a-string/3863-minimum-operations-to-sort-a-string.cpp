class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 1) return 0;
        if(n == 2){
            if(s[0] > s[1]) return -1;
            return 0;
        }
        bool whole = false;

        int count = 0;
        bool maxCheck = false;
        char minCh = 'z';
        char maxCh = 'a';
        int minCount = 0;
        for(int i = 0; i < n; i++){
            if(i+1 < n && s[i+1] < s[i]) whole = true;
            if(s[i] == s[0]) count++;
            if(s[i]  > s[0]) maxCheck = true;
            if(s[i] == minCh) minCount++;
            if(s[i] < minCh){
                minCh = s[i];
                minCount = 1;
            }
            if(s[i] > maxCh) maxCh = s[i];
        }

        if(whole == false) return 0;

        if(s[0] == maxCh && s[n-1] == minCh && count == 1 && s[n-1] == minCh && minCount == 1) return 3;
        if(s[0] != minCh && s[n-1] != maxCh) return 2;

        // if(s[0] != maxCh && s[n-1] == minCh) return 2;
        
        return 1;

    }
};