class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAliceMonth = stoi(arriveAlice.substr(0,2));
        int arriveAliceDay = stoi(arriveAlice.substr(3,2));
        int leaveAliceMonth = stoi(leaveAlice.substr(0,2));
        int leaveAliceDay = stoi(leaveAlice.substr(3,2));
        int arriveBobMonth = stoi(arriveBob.substr(0,2));
        int arriveBobDay = stoi(arriveBob.substr(3,2));
        int leaveBobMonth = stoi(leaveBob.substr(0,2));
        int leaveBobDay = stoi(leaveBob.substr(3,2));

        vector<int> dates = {31,28,31,30,31,30,31,31,30,31, 30, 31};
        for(int i = 1; i < 12; i++){
            dates[i] = dates[i-1] + dates[i];
        }
        int aliceStartDate = 0;
        if(arriveAliceMonth != 1) aliceStartDate = dates[arriveAliceMonth-2];
        aliceStartDate += arriveAliceDay;
        int aliceEndDate = 0;
        if(leaveAliceMonth != 1) aliceEndDate = dates[leaveAliceMonth-2];
        aliceEndDate += leaveAliceDay;
        int BobStartDate = 0;
        if(arriveBobMonth != 1) BobStartDate = dates[arriveBobMonth-2];
        BobStartDate += arriveBobDay;
        int BobEndDate = 0;
        if(leaveBobMonth != 1) BobEndDate = dates[leaveBobMonth-2];
        BobEndDate += leaveBobDay;
        
        if(aliceEndDate < BobStartDate || BobEndDate < aliceStartDate) return 0;
        int start = max(aliceStartDate, BobStartDate);
        int end = min(aliceEndDate, BobEndDate);
        return end - start + 1;
    }
};