class Robot {
public:
    int w;int h; string dir; int i,j;
    map<string,string> next; map<string, pair<int,int>> d;
     int mod;
    Robot(int width, int height) {
        w = height;
        h = width;
        dir = "East"; i=0;j=0;
        next["East"] = "North"; next["North"] = "West";  next["West"] = "South"; next["South"] = "East";
        d["East"] = {1,0}; d["West"] = {-1,0} ; d["North"] = {0,1}; d["South"] = {0,-1};
        mod = 2*(h+w-2);
    }
    
    void step(int num) {
        int n = num;
        while(n>0){
            auto x = d[dir];
            //cout<< dir<< " ";
            
            if(i + x.first*n >=0 and i+x.first*n< h and (j + x.second*n >=0 and j+x.second*n< w) ){
                i = i+x.first*n;
                j = j+x.second*n;        
                return ;
            }
            else{
                 //cout<< i << " " <<  j << endl;
                if(dir == "East"){ n = n-(h-i-1); i=h-1; }
                else if(dir=="West"){n -= i; i=0; }
                else if(dir=="North"){n = n-(w-j-1) ; j=w-1; }
                else{ n -= j ; j =0;}
                //cout<< i << " " <<  j << endl;
                n = n%mod;
                if(n>0)
                    dir = next[dir];
            }
            
           
           
        }

    }
    
    vector<int> getPos() {
        return {i,j};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */