class Solution {
public:
    string helper(int n){
        string ans="";
        while(n){
            int rem= n%2;
            ans+= rem+'0';
            n= n/2;
        }
        while(ans.size()!= 32){
            ans+= '0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int minFlips(int a, int b, int c) {
        string x= helper(a);
        // cout<<x<<endl;
        string y= helper(b);
        // cout<<y<<endl;
        string z= helper(c);
        // cout<<z<<endl;
        
        int flip=0; 
        
        for(int i=0;i<z.size();i++){
            if(z[i]=='1'){
                if(x[i]!='1' && y[i]!='1'){
                    flip++;
                }
            }
            else{
                if(x[i]=='1'){
                    flip++;
                }
                if(y[i]=='1'){
                    flip++;
                }
            }
        }
        return flip;
    }
};