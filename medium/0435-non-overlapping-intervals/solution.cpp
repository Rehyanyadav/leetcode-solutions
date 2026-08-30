class Solution {
public:
static bool compare (vector<int> & a, vector<int> & b){
    return a[1]< b[1];

}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if(intervals.empty()) return 0;
      sort (intervals.begin(), intervals.end(),compare);


      int removed_count = 0;
      int last_end_time = intervals[0][1];



for(int i =1; i<intervals.size(); i++){
    if(intervals[i][0] >= last_end_time){
 last_end_time = intervals[i][1];
    }
    else{
        removed_count++;

    }
   

}

 return removed_count;



    }
};