// fuction to check whether pemutation occur in the s2


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp;
        for(auto it:s1){
            mp[it]++;
        }
        int right=0;
        int left=0;
        map<char,int>compare;
        while(right<s2.size()){
            compare[s2[right]]++;
            while(compare[s2[right]]>mp[s2[right]]){
                compare[s2[left]]--;
                if(compare[s2[left]]==0)compare.erase(s2[left]);
                left++;
            }
            if(mp==compare)return true;
            right++;


        }
        return false;
        
    }
};