https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
    stack<pair<int,int>>st; //pair storing {price,span};
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty()&& price>=st.top().first){
            span=span+st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
