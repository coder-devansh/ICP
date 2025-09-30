// fuction to check whether pemutation occur in the s2


class Solution {
public:
    vector<int>findAnagrams(string s2, string s1) {
        map<char,int>mp;
        for(auto it:s1){
            mp[it]++;
        }
        int right=0;
        int left=0;
        map<char,int>compare;
        vector<int>ans;
        while(right<s2.size()){
            compare[s2[right]]++;
            while(compare[s2[right]]>mp[s2[right]]){
                compare[s2[left]]--;
                if(compare[s2[left]]==0)compare.erase(s2[left]);
                left++;
            }
            if(mp==compare)ans.push_back(left);
            right++;


        }
        return ans;
        
    }
};