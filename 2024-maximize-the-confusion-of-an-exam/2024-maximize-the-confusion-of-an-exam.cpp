class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0, j=0;
        int n=answerKey.size();
        int res=0;
        int countF=0;
        
        // case 1  // T
        while(j<n){
            if(answerKey[j]=='F'){
                countF++;
            }
            
            while(countF>k){
                if(answerKey[i]=='F'){
                    countF--;
                }
                i++;
            }
            res= max(res,j-i+1);
            
            j++;
        }
        
        
        j=0,i=0;
        int countT=0;
        
        while(j<n){
            if(answerKey[j]=='T'){
                countT++;
            }
            
            while(countT>k){
                if(answerKey[i]=='T'){
                    countT--;
                }
                i++;
            }
            res= max(res,j-i+1);
            j++;
        }
        
        return res;
        
    }
};