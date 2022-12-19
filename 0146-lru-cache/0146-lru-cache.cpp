class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val){
            key= _key;
            val= _val;
        }
    };
    
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
    
    void addnode(node *newnode){
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deletenode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;  
    }
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key_) {
        if(m.find(key_)!=m.end()){
            node *resnode = m[key_];
            int ans=resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end()){
            node *resnode= m[key_];
            m.erase(key_);
            deletenode(resnode);
        }
        else if(m.size()==cap){
            node *lru=tail->prev;
            m.erase(lru->key);
            deletenode(lru);
        }
    
        node *newnode = new node(key_,value);
        addnode(newnode); 
        m[key_]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */