class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
        stack<int>  s;
        vector<int> days(t.size());
        
        for (int i = 0; i < t.size(); i++)
        {
            while (!s.empty() && t[i] > t[s.top()])
                days[s.top()] = i - s.top(), s.pop();
            
            s.push(i);
        }
        
        return days;
    }
};