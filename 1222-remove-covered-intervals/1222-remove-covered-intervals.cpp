class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i-1][1] >= intervals[i][1] && intervals[i-1][0] <= intervals[i][0]){
                intervals.erase(intervals.begin()+i);
                i--;
            }else if(intervals[i][0] <= intervals[i-1][0] && intervals[i][1] > intervals[i-1][1]){
                intervals.erase(intervals.begin()+i-1);
                i--;
            }
        }

        return intervals.size();
    }
};