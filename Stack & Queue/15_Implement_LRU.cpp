class LRUCache {
    public:
        list<int> l;
        map<int,int> m;
        map<int,list<int>::iterator> address;
        int cap;
        int size;
    
    
        LRUCache(int capacity) {
            cap = capacity;
            size=0;
            
        }
        
        int get(int key) {
            if(m.find(key)==m.end())return -1;
            l.erase(address[key]);
            address.erase(key);
            l.push_front(key);
            address[key]=l.begin();
            return m[key];
        }
        
        void put(int key, int value) {
            if(m.find(key)!=m.end())
            {
                l.erase(address[key]);
                address.erase(key);
                l.push_front(key);
                address[key]=l.begin();
                m.erase(key);
                m[key]=value;
            }
            else
            {
                if(size==cap)
                {
                    int k = l.back();
                    l.pop_back();
                    l.push_front(key);
                    address.erase(k);
                    address[key]=l.begin();
                    m.erase(k);
                    m[key]=value;
                }
                else{
                    l.push_front(key);
                    address[key]=l.begin();
                    m[key]=value;
                    size++;
                }
            }
        }
    };