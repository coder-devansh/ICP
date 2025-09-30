class Solution {
public:
    int longestOnes(vector<int>& nums,int k) {
        int left=0;
        int right=0;
        int maxi=INT_MIN;
        map<int,int>mp;
        while(right<nums.size())
        {
            mp[nums[right]]++;
            
            while(left<right && (right-left+1)-mp[1]>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if(mp[1]==0 && k==0){
                right++;
                continue;
            }
                 maxi=max(maxi,mp[1]+mp[0]);
            
            right++;

        }
        if(maxi==INT_MIN)return 0;
        return maxi;
        
    }
};