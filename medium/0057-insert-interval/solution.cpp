            i++;

        }
        result.push_back(newInterval);
        while(i<n){
            result.push_back(intervals[i]);
            i++;

        }

        return result;

    }

};
