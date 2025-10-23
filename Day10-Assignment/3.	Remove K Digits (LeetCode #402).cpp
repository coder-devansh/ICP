class Solution {
public:
    string removeKdigits(string num, int k) {
        k=num.size()-k;
        if(num.size()==1 && k==1)return "0";
        if(num.size()==k)return "0";
        if(num.size()<=k)return "0";
        stack<int>st;
        int val=k;
        int n=num.size();
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>(num[i]-'0') && ((st.size()-1+(n-i))>=k)){
                st.pop();
            }
            if(st.size()<val){
                st.push(num[i]-'0');
            }
            

        }
        string str="";
        if(st.size()==num.size()){
            for(int j=0;j<num.size()-k;j++){
                str+=num[j];
            }
            return str;
        }
        while(!st.empty()){
            auto it=st.top();
            str+=(it+'0');
            st.pop();
        }
        reverse(str.begin(),str.end());
        string temp="";
        int i=0;
        while(i<str.size() && str[i]=='0'){
            i++;
        }
        for(;i<str.size();i++)temp+=str[i];
        if(temp.size()==0)return "0";
        return temp;
        
    }
};