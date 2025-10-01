static bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int prev_end=0;;
        int count=0;
         prev_end=max({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int b=intervals[i][0];
           
            if(b<prev_end){
                count++;
            }else{
                prev_end=intervals[i][1];
            }
        }
        return count;
        
    }
};