class StockSpanner {
private:
// Shreya
    stack<pair<int, int>> st; 

public:
    StockSpanner() 
    {
        while (!st.empty()) st.pop(); 
    }

    int next(int price) 
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});

        return span;
    }
};