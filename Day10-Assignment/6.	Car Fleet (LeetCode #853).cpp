class Solution {
public:

    static bool compare(const pair<int,int>& a,const pair<int,int>& b){
        return a.first > b.first;
    }
    double find_meet(double posA, double posB, double spA, double spB){
        if(spA <= spB) return posA; // will never meet before target
        double time = (posB - posA) / (spA - spB);
        return posA + spA * time;
    }
    double calculate(int p, int s, int target){
        return (double)(target - p) / s;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++)
            vec.push_back({position[i], speed[i]});

        sort(vec.begin(), vec.end(), compare); // descending

        stack<pair<int,int>> st; // store {position, speed}

        for(int i = 0; i < n; i++){
            int posA = vec[i].first;
            int spA = vec[i].second;
            double timeA = calculate(posA, spA, target);

            if(!st.empty()){
                auto it = st.top();
                int posB = it.first;
                int spB = it.second;
                double timeB = calculate(posB, spB, target);

                if(timeA <= timeB){
                    // Merge fleets
                    st.pop();
                    int min_speed = min(spA, spB);
                    double meeting_pos = (posA < posB && spA > spB) ? find_meet(posA, posB, spA, spB) : posA;
                    st.push({(int)meeting_pos, min_speed});
                } else {
                    // New fleet
                    st.push({posA, spA});
                }
            } else {
                st.push({posA, spA}); // first fleet
            }
        }

        return st.size(); // number of fleets
    }
};
