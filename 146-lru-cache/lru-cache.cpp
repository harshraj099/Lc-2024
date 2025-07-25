class LRUCache {
public:
    class dll{
        public:
        int k,val;
        dll* next;
        dll* prev;

        dll(int key,int value){
            k=key;
            val=value;
            next=NULL;
            prev=NULL;
        }
    };

    map<int,dll*>m;
    dll* front,*rear;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        front = new dll(-1, -1); 
        rear = new dll(-1, -1);  
        front->next = rear;
        rear->prev = front;
    }
    void add(dll* node){
        dll* temp=rear->prev;
        node->next=rear;
        temp->next=node;
        node->prev=temp;
        rear->prev=node;
    }
    void del(dll* node){
        dll* tm1=node->prev,*tm2=node->next;
        tm1->next=tm2;
        tm2->prev=tm1;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            dll* temp=m[key];
            del(temp);
            add(temp);
            return m[key]->val;  
        }
        return -1;
    }
    
    void put(int key, int value) {
        dll * node=new dll(key,value);
        if(m.find(key)!=m.end()){
            dll* temp=m[key];
            del(temp); 
            m.erase(temp->k);
        }
        if(size==m.size()){
            dll* temp=front->next;
            m.erase(temp->k);
            del(temp);
        }
         m[key]=node;
        add(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */