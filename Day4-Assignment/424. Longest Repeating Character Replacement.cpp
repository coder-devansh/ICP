class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int right=0;
        int left=0;
        int maxi=0;
        int max_freq=0;
        while(right<s.size()){
            mp[s[right]]++; 
            max_freq=max(max_freq,mp[s[right]]);
                while(left<=right && (right-left+1)-max_freq>k){
                    mp[s[left]]--;
                    if(mp[s[left]]==0)mp.erase(s[left]);
                    left++;
                }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
        
    }
};