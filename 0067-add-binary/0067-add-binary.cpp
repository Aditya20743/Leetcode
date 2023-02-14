class Solution {
public:
    // unsigned long long BinaryToInt(string a){
    //     unsigned long long n= a.size();
    //     unsigned long long ans=0;
    //     for( long long i= n-1;i>=0 ;i--){
    //         ans+= (a[i]-'0')* pow(2,n-(i+1)); 
    //     }
    //     return ans;
    // }
    // string IntToBinary(unsigned long long a){
    //     if(a== 0)   return "0";
    //     string ans="";
    //     while(a!=1){
    //         char x= a%2+'0';
    //         ans+= x;
    //         a/=2;
    //     }
    //     ans+= '1';
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }
    string addBinary(string a, string b) {
        if(a.size()< b.size()){
            swap(a,b);
        }
        int l= a.size()-1;
        int r= b.size()-1;
        string ans="";
        int carry=0;
        while(l>=0 && r>=0){
            int t= a[l]-'0' + b[r]-'0' + carry;
            if(t>=2)    carry=1;
            else    carry=0;
            ans+= char(t%2 + '0');
            l--; r--;
        }
        while(l>=0){
            int t= a[l]-'0' + carry;
            if(t>=2)    carry=1;
            else carry=0;
            ans+= char(t%2 + '0');
            l--;
        }
        if(carry==1){
            ans+= '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
        
        // unsigned long long x= BinaryToInt(a);
        // unsigned long long y= BinaryToInt(b);
        // x= x+y;
        // return IntToBinary( x );
    }
};