
        // Greedily pick intervals that start after or when the last one ends
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= last_end) {
                count_non_overlapping++;
                last_end = intervals[i][1];
            }
        }

        // Minimum removals needed = Total intervals minus maximum compatible intervals
        return intervals.size() - count_non_overlapping;
    }
};

