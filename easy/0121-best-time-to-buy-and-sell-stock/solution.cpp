        int max_profit = 0;
        
        for (int price : prices) {
            min_price = min(min_price, price);
            int current_profit = price - min_price;
            max_profit = max(max_profit, current_profit);
        }
        
        return max_profit;
    }
};
 int min_price = INT_MAX;
    int maxProfit(vector<int>& prices) {
public:
class Solution {
