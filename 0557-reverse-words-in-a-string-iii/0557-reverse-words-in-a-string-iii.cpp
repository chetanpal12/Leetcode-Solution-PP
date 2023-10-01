class Solution {
public:
    string reverseWords(string s) {
     // Create a stringstream to split the string
    stringstream ss(s);
    string word;
    
    // Create a vector to store the split parts
    vector<string> parts;
    
    // Use stringstream to split the string based on spaces
    while (ss >> word) {
        reverse(word.begin(), word.end());
        parts.push_back(word);
    }
    string ans="";
    for(int i=0;i<parts.size();i++){
        if(i==parts.size()-1){
            ans+=parts[i];
            return ans;
        }
            
        ans+=parts[i];
        ans+=" ";
    }
    return ans;
    }
};