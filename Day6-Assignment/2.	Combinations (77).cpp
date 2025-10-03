class Solution {
public:
vector<vector<int>>result;
void find_combo(int j,int n,int k,vector<int>&temp){
    if(k==0){
        result.push_back(temp);
        return;   
    }
    for(int i=j;i<=n;i++){
        temp.push_back(i);
        find_combo(i+1,n,k-1,temp);
        temp.pop_back();

    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        find_combo(1,n,k,temp);
        return result;
        
    }
};