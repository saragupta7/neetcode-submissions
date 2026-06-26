class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        unordered_map <char, int> inDegree;
        for (int i=0;i<n;i++){
            for (char c: words[i]) inDegree[c]=0;
        }
        
        unordered_map <char,vector<char>> adj;
        for (int i=0;i<n-1;i++){
            string a=words[i];
            string b=words[i+1];
            //handle a is a prefix of b and a.length < b.length if not given
            if (a.size()>b.size() && a.substr(0,b.size())==b) return "";
            int j=0;
            int maxLen=min(a.size(),b.size());
            while (j<maxLen && a[j]==b[j]) j++;
            if (j==maxLen) continue;

            adj[a[j]].push_back(b[j]);
            inDegree[b[j]]++;
        }

        string topo="";
        int v =inDegree.size();

        queue <char> q;
        for (auto it: inDegree){
            if (it.second==0) q.push(it.first);
        }

        while (!q.empty()){
            char ch=q.front();
            topo+=ch;
            q.pop();
            for (auto u:adj[ch]){
                inDegree[u]--;
                if (inDegree[u]==0) q.push(u);
            }
        }

        if (topo.size()!=v) return "";
        return topo;
    }
};