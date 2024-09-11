
class LRUCache {
public:
class node{
    public:
    int val;
    int key;
    node* next;
    node* prev;

    node(int k,int v){
        val=v;
        key=k;
        next=NULL;
        prev=NULL;
    }
};
node* head=new node(-1,-1),*tail=new node(-1,-1);
    unordered_map<int,node*>m;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(node* nd){
        node* temp1=nd->prev;
        node* temp2=nd->next;
        temp1->next=temp2;
        temp2->prev=temp1;
    }
     void addnode(node* nd) {
        // Add new node right after the head
        node* temp = head->next;
        nd->next = temp;
        nd->prev = head;
        head->next = nd;
        temp->prev = nd;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* nd=m[key];
            int res=nd->val;
            m.erase(key);
            deletenode(nd);
            addnode(nd);     
        //  node* temp = head->next;
        // nd->next = temp;
        // nd->prev = head;
        // head->next = nd;
        // temp->prev = nd;
            m[key]=head->next;

            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
      if(m.find(key)!=m.end()){
        node* temp=m[key];
        m.erase(key);
        deletenode(temp);
      }  
      if(m.size()==cap){
        node* tempy=tail->prev;
        m.erase(tempy->key);
        deletenode(tempy);
      }
    node * newnode=new node(key,value);
    addnode(newnode);     
        //  node* fakehead=head;
        //     head->next=newnode;
        //     newnode->prev=head;
        //     newnode->next=fakehead->next;
        //     fakehead->next->prev=newnode;

            m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */