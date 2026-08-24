            }
        }

        // After the loop, match remaining '(' with '*' that appear AFTER them
        while (!openSt.empty() && !starSt.empty()) {
            // If the '(' appears AFTER the '*', the '*' cannot balance it (e.g., "*( ")
            if (openSt.top() > starSt.top()) {
                return false;
            }
            openSt.pop();
            starSt.pop();
        }

        // If openSt is empty, all open brackets found a match!
        return openSt.empty();
    }
};

