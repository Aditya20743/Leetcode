class Solution 
{
public:
    //traversing in all 8 possible directions
    void traverse(vector<vector<int>>& mat,unordered_map<int,int> &mp,int &x,int &y)
    {
        int n,m,num;
        m=mat.size();
        n=mat[0].size();
        
        num=mat[x][y];
        for(int i=x+1;i<m;i++)
        {
            num=num*10+mat[i][y];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=x-1;i>=0;i--)
        {
            num=num*10+mat[i][y];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=y+1;i<n;i++)
        {
            num=num*10+mat[x][i];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=y-1;i>=0;i--)
        {
            num=num*10+mat[x][i];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=x+1,j=y+1;i<m && j<n;i++,j++)
        {
            num=num*10+mat[i][j];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=x-1,j=y-1;i>=0 && j>=0;i--,j--)
        {
            num=num*10+mat[i][j];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=x+1,j=y-1;i<m && j>=0;i++,j--)
        {
            num=num*10+mat[i][j];
            mp[num]++;
        }
        
        num=mat[x][y];
        for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
        {
            num=num*10+mat[i][j];
            mp[num]++;
        }
    }
    
    bool isPrime(int n)
    {
        if(n==2)
        {
            return true;
        }

        if(n<=1 || n%2==0)
        {
            return false;
        }

        for(int i=3;i*i<=n;i=i+2)
        {
            if(n%i==0)
            {
                return false;
            }
        }
     
        return true;
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) 
    {
        int n,m,ans;
        m=mat.size();
        n=mat[0].size();
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                traverse(mat,mp,i,j);        
            }
        }
        
        int maxv=0;
        int maxp=0;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(!isPrime(it->first))
            {
                continue;
            }
            
            if(it->second>maxv)
            {
                maxv=it->second;
                maxp=it->first;   
            }
            
            else if(it->second==maxv && it->first>maxp)
            {
                maxp=it->first;
            }
        }
        
        return maxv==0?-1:maxp;
    }
};