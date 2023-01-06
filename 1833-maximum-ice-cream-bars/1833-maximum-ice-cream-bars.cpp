class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Store ice cream costs in ascending order.
        sort(costs.begin(), costs.end());

        int n = costs.size();
        int icecream = 0;

        // Pick ice creams till we can.
        while (icecream < n && costs[icecream] <= coins) {
            // We can buy this icecream, reduce the cost from the coins. 
            coins -= costs[icecream];
            icecream += 1;
        }

        return icecream;
    }
};