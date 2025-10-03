class Solution {
public:
set<vector<int>>st;
void find(int i,vector<int>&candidates,int target,vector<int>temp){
    if(target==0){
        st.insert(temp);
        return;
    }
    if(i>=candidates.size())return ;
    for(int j=i;j<candidates.size();j++){
        if(j>i && candidates[j]==candidates[j-1])continue;
        if(target<candidates[j])break;
        if(target>=candidates[j]){
            temp.push_back(candidates[j]);
            find(j+1,candidates,target-candidates[j],temp);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        find(0,candidates,target,temp);
        vector<vector<int>>result;
        for(auto it:st){
            result.push_back(it);
        }
        return result;
        
    }
};