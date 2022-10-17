class LRUCache {
public:
    
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    int size, cap;
    unordered_map<int, Node*> mp;
    
    Node* createNode(int k, int v){
        Node* x = new Node();
        x->key = k;
        x->value = v;
        x->next = head->next;
        head->next = x;
        x->prev = head;
        x->next->prev = x;
        
        mp[k] = x;
        
        return x;
    }
    
    void moveToHead(Node* x){
        if(head->next == x){
            return;
        }
        
        x->prev->next = x->next;
        x->next->prev = x->prev;
        
        x->next = head->next;
        head->next->prev = x;
        //x->next->prev = x;
        head->next = x;
        x->prev = head;
        
    }
    
    
    void removeTail(){
        Node* x = tail->prev;
        x->prev->next = tail;
        tail->prev = x->prev;
        
        mp.erase(x->key);
    }
    
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
        cap = capacity;
    }
    
    void printList(){
        Node* tmp = head->next;
        while(tmp!= tail){
            cout<<tmp->key<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
    
    int get(int k) {
        //cout<<"inGet"<<endl;
        if(mp.find(k) == mp.end()){
            return -1;
        }
        Node* x = mp[k];
        moveToHead(x);
        
        //printList();
        
        return x->value;
    }
    
    void put(int k, int v) {
        //cout<<"inPut"<<endl;
        
        if(mp.find(k) != mp.end()){
            //key already present
            Node* x = mp[k];
            x->value = v;
            moveToHead(x);
            return;
        }
        
        createNode(k,v);
        if(size < cap){
            size++;
            //printList();
            return ;
        }
        else{
            removeTail();
            //printList();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */