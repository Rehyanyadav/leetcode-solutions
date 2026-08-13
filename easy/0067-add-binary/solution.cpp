            }

            // Append the remainder bit (carry % 2) converted back to a character
            result += (carry % 2) + '0'; 
            
            // Calculate the new carry (carry / 2) for the next column
            carry /= 2;                  
        }

        // The result is built backwards, so we flip it right-side up
        std::reverse(result.begin(), result.end());
        
        return result;

    }
