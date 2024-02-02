class Solution {
public:
    int digit(int num){
        int c=0;
        while(num){
            num= num/10;
            c++;
        }
        return c;
    }
    void add(vector<int>&ans, int i,int low, int high){
        
        string temp="";
        for(char x='0';x<='8';x++){
           
            if(x+i <='9'){
                for(int j=1;j<=i ;j++){
                    temp+=x+j;
                }
                // cout<<temp<<endl;
            
                int no =stoi(temp);
                temp="";
                if(no>= low && no<=high){
                    // cout<<no<<endl;
                    ans.push_back(no);
                }
                else if(no>high)    break;
                temp="";
            }
            else{
                break;
            }
        }
        
    }
    
    vector<int> sequentialDigits(int low, int high) {
        int ld= digit(low);
        int hd= digit(high);
        
        vector<int> ans;
        
        for(int i=ld;i<=hd;i++){
            add(ans, i,low,high);
        }
        
        return ans;
    }
};