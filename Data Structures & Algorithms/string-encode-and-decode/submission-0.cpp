class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string encoded="";
        for (int i=0;i<n;i++){
            int len=strs[i].size();
            encoded+=to_string(len)+"#"+strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int n=s.size();
        int i=0;
        vector<string> decoded;
        while (i<n){
            int start=i;
            while (s[i]!='#') i++;
            int len=stoi(s.substr(start,i-start));
            decoded.push_back(s.substr(i+1,len));
            i+=len+1;
        }

        return decoded;
    }
};
