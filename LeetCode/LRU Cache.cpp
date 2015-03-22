class LRUCache{
public:
	vector<int> keys;
	unorder_map<int,int> mp;
	int size=0;
    LRUCache(int capacity) {
        size=capacity;
    }
    void adjust(int key){
    	int index=-1;
    	for(int i=keys.size()-1;i>=0;i--){
    		if(keys[i]==key){
    			index=i;
    			break;
    		}
    	}
    	if(index==-1) return;
    	keys.erase(keys.begin()+index);//调整优先级
    	keys.push_back(key);
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
        	adjust(key);
        	return mp[key];
        }
    }
    
    void set(int key, int value) {
        if(mp.find(key)!=mp.end()){
        	mp[key]=value;
        	adjust(key);
        	return ;
        }
        if(keys.size()>=size){
        	int idx=keys[0];
        	keys.erase(keys.begin());
        	mp.erase(idx);
        }
        keys.push_back(key);
        mp[key]=value;
    }
};
