class Solution {
public:
    
    vector<vector<int>>graph;
    vector<bool>visited;
    
    void dfs(int i,vector<int>&index,vector<int>&letter,string s){
        visited[i]=true;
        index.push_back(i);
        letter.push_back(s[i]);
        for(int u:graph[i])
        {
            if(!visited[u])
            {
                dfs(u,index,letter,s);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        visited.resize(n,false);
        graph.resize(n);
        
        for(auto x:pairs)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int>index;
            vector<int>letter;
            if(!visited[i])
            {
                dfs(i,index,letter,s);
            }
            sort(index.begin(),index.end());
            sort(letter.begin(),letter.end());
            
            for(int i=0;i<index.size();i++)
            {
                s[index[i]]=letter[i];
            }
        }
            return s;

    }
};
