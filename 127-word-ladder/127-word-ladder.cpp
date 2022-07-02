class Solution {
	// To Create a edges from "word" to all other words with difference one
    void createGraph(unordered_map<string, vector<string>>&G, vector<string>& wordList, string word, int i, int n)
    {
        for(int j=i; j<n; j++)
        {
            int set=0,ans=0;
			
			// Comparing alphanets.
            for(int k=0; k<word.length(); k++)
            {
				// if one alphabet is different
                if(!set && word[k]!=wordList[j][k]) {set=1, ans=1;}
				// if more than one alphabet is different
                else if(set && word[k]!=wordList[j][k]) {ans=0; break;}
            }
			// creating an undirected edge from node "word" to node "wordList[j]"
            if(ans)
            {
                G[word].push_back(wordList[j]);
                G[wordList[j]].push_back(word);
            }
        }  
    }
	
	// Function with the shorted path of undirected graph
    int shortestPath(unordered_map<string, vector<string>>&G, string source, string sink, vector<string>& wordList)
    {
		// ds to store dist from the source to the node
        unordered_map<string,int>dist;
		// initializing dist with max value
        for(auto c:wordList) dist[c]=INT_MAX;
		
		// Queue to perform BFS
        queue<string>Q;
        Q.push(source);
        dist[source]=0;
        
        while(!Q.empty())
        {
            string s = Q.front();
            Q.pop();
            for(auto u:G[s])
            {
                if(dist[u]>dist[s]+1)
                {
                    dist[u]=dist[s]+1;
                    Q.push(u);
                }
            }
        }
        return dist[sink];
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPresent=0;
        int n=wordList.size();
        
		// checking if endWord is not present in the wordList
        for(auto it:wordList) if(it==endWord) isPresent=1;
        if(!isPresent) return 0;
        
		// Map is used bcuz we need string to access the index
        unordered_map<string, vector<string>>G;
		
		// Adding edge from node "beginWord" to all other words of the wordList that contain one different alphabet
        createGraph(G,wordList, beginWord, 0, n);
        
        for(int i=0; i<n; i++)
            createGraph(G,wordList, wordList[i], i+1, n);
        
        int a = shortestPath(G, beginWord, endWord, wordList);
		
		// if there is no path from beginWord to endWord 
        if(a==INT_MAX) a=-1;
        return a+1;
    }
};