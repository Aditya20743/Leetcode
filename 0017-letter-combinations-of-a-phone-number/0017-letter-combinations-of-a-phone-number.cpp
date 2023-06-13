class Solution {
public:
    void helper(int i, int j, string digits, vector<string>&ans, vector<string>&chars,
               string &temp){
        // i -> index of digits
        // j -> index of chars[digits[i]-'0']
        
        if(i== digits.size()){
            ans.push_back(temp);
            return;
        }
        if(j== chars[digits[i]-'0'].size()-1){
            // if we are on last index of chars[digits[i]-'0'] we will have to take that index and move to next i;
            
            temp+= chars[digits[i]-'0'][j];
            
            helper( i+1 ,0 , digits, ans, chars, temp);
            
            temp.erase(temp.begin()+temp.size()-1);
            
        }
        else{
            
            temp+= chars[digits[i]-'0'][j];
            
            helper(i+1, 0, digits, ans, chars, temp); //take
            
            temp.erase(temp.begin()+temp.size()-1);

            helper(i, j+1, digits, ans, chars, temp ); // not_take
  
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size()==0)
            return ans;
        
        string temp="";
        
        vector<string> chars(10);

        chars[2]="abc";
        chars[3]="def";
        chars[4]="ghi";
        chars[5]="jkl";
        chars[6]="mno";
        chars[7]="pqrs";
        chars[8]="tuv";
        chars[9]="wxyz";
        
        helper(0, 0, digits, ans, chars, temp);
        
        return ans;
    }
};