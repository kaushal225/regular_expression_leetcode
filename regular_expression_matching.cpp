class Solution {
public:
    /*int arr[22][32];
    bool helper(string s,string p,int i,int j)
    {
        if(arr[i][j]!=-1)
            return arr[i][j];
        if(i==s.size()&&j==p.size())
            return true;
        if(j>=p.size())
            return false;
        bool match=(i<s.size()&&(s[i]==p[j]||p[j]=='.'));
        if(j+1<p.size()&&p[j+1]=='*')
                return arr[i][j]=(helper(s,p,i,j+2)||(match&&helper(s,p,i+1,j)));
        if(match)
            return arr[i][j]=helper(s,p,i+1,j+1);
       return arr[i][j]=false;

    }*/
    bool isMatch(string s, string p) {
        arr[s.size()][p.size()]=1;
        for(int i=s.size();i>=0;i--)
            for(int j=p.size()-1;j>=0;j--)
            {
                bool match=(s[i]==p[j]||p[j]=='.');
                if(j+1<p.size()&&p[j+1]=='*')
                    arr[i][j]=(arr[i][j+2]||(match&&arr[i+1][j]));
                else if(match)
                    arr[i][j]=arr[i+1][j+1];
                else
                    arr[i][j]=false;
            }
            return arr[0][0];
        //return helper(s,p,0,0);
    }
};
