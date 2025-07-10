class Solution {
public:
// Shreya
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

    for (int ast : asteroids)
    {
        bool destroyed = false;

        while (!st.empty() && ast < 0 && st.top() > 0) 
        {
            // Collision happens
            if (abs(ast) > st.top())
            {
                st.pop(); // current asteroid is larger, pop from stack
                continue;
            } else if (abs(ast) == st.top()) 
            {
                st.pop(); // both destroy each other
                destroyed = true;
                break;
            } 
            else 
            {
                // current asteroid is smaller, it is destroyed
                destroyed = true;
                break;
            }
        }

        if (!destroyed) 
        {
            st.push(ast);
        }
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) 
    {
        result[i] = st.top();
        st.pop();
    }

    return result;
    }
};