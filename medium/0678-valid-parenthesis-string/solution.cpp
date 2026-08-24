    if(st.empty()){
        return false;
    }


//* getting top element  and removing it 
 char topElement = st.top();
 st.pop();


    //* check if pop brackets are matching the 
    current closing brackets
     if(ch == ')' && topElement != '(' || 

        (ch == '}' && topElement != '{') ||
        (ch == ']' && topElement != '[')){
 }
          }
        return false;
 return st.empty();

    }
};
