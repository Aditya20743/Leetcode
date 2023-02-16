//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<int,int> mp, mpp;
	    int i=0,c=0,k= pat.size();
	    for(i=0;i<k;i++){
	        mp[txt[i]]++;
	        mpp[pat[i]]++;
	    }
	    if(mpp == mp)   c++;
	    
	    while(i<txt.size()){
	        mp[txt[i-k]]--;
	        if( mp[txt[i-k]]==0 )   mp.erase(txt[i-k]);
	        mp[txt[i]]++;
	        if(mp == mpp)   c++;
	        i++;
	    }
	    return c;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends