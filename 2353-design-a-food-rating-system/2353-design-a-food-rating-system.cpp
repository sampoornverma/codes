class FoodRatings {
public:
    unordered_map<string, pair<string, int>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        cuisineFoods[cuisine].erase({-oldRating, food});
        cuisineFoods[cuisine].insert({-newRating, food});
        foodInfo[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};