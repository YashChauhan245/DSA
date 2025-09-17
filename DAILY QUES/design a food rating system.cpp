https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17


class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings_food;
    //cuisine,rating,food
    unordered_map<string, string> food_cuisine;//food and cuisine
    unordered_map<string, int> food_rating; //food and rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; i++) {
            string food    = foods[i];
            string cuisine = cuisines[i];
            int rating     = ratings[i];
            
            cuisine_ratings_food[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food]  = rating;
            
            
        }
    }

    // RATING is negative(-)FOR LEXICOGRAPHICALLY SMALLER
    // ASSUME IN SET(DEFAULT ASC.) CUISINE =(15>abc ;16->shi,16->xyz)
    // Now, as he have to return highest we should return last and
    // if 16 rating is same it return last element xyz
    // but->thats wrong as we have to return in lexo order i.e 16
    // S0,Store in neg order like (-16 shi;-16xyz;15abc)
    // And,returns the first element 

    // or write a comparator (but thats complex)
    
    void changeRating(string food, int newRating) {
        // searching cuisine of food and its old rating
        string cuisine = food_cuisine[food];
        int oldRating  = food_rating[food];
        //deleting old rating in map and inserting new one 
        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        //changing rating
        food_rating[food] = newRating;
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second; 
        
    }
};
