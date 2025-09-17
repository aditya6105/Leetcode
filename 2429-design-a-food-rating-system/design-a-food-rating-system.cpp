class compare{
public:
    bool operator()(const pair<string, int>& a , const pair<string, int> &b) const{
        if(a.second == b.second){   //if the rating of both the fooditems is same
            return a.first < b.first;   //return in the lexicographical order
        }
        return a.second > b.second;     //otherwise just return the highest rated food item
    }
};
class FoodRatings {
public:
    unordered_map<string , string> foodMap;
    unordered_map<string , int> ratingMap;

    unordered_map<string , set<pair<string, int> , compare>> cuisineTop;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for(int i = 0; i < foods.size() ; i++){

            foodMap[foods[i]] = cuisines[i];
            ratingMap[foods[i]] = ratings[i];
            cuisineTop[cuisines[i]].insert({foods[i] , ratings[i]});
        }  
    }
    
    void changeRating(string food, int newRating) {

        string cuisine = foodMap[food];
        int oldRating = ratingMap[food];
        ratingMap[food] = newRating;

        cuisineTop[cuisine].erase({food , oldRating});

        cuisineTop[cuisine].insert({food , newRating});
        
    }
    
    string highestRated(string cuisine) {

        return cuisineTop[cuisine].begin()->first;        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */