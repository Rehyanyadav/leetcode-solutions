     }
             candies[i] = candies[i-1]+1;
        }

     for(int i = n-2; i>=0; i--){
        if(ratings[i]> ratings[i+1]){
            candies[i] = max(candies[i] ,candies[i
        }
            +1] +1);
     }

     int totalCandies = 0;
     for(int i =0; i<n; i++){
        totalCandies+= candies[i];
     }
     return totalCandies;
    }

};
