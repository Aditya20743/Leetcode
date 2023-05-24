//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++

// 1 1 2 5 14 42 132 429 1430 4862
// 

class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int> dp(101,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i]+= dp[i-1-j]*dp[j];
            }
        }
        return dp[n];
       
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends