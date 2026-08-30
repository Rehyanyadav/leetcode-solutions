          for(int i =1; i<intervals.size(); i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }

            else{
                result.push_back(intervals[i]);
            }


          }
          return result;

    }
};
