class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int low=0;
        int high=people.size()-1;
        int boat=0;
        while(low<=high){
            if((people[low]+people[high])<=limit){
                boat++;
                low++;
                high--;
                

            }else{
                high--;
                boat++;
            }
        }

        return boat;
        
    }
};