class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int k,int v){
        val=v;
        key=k;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    map<int,Node*> mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }

    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    void insert(Node* node){
        node->prev=head;
        node->next=head->next;
        node->next->prev=node;
        head->next=node;
    }
    int get(int key) {
        if (mpp.find(key)!=mpp.end()){
            removeNode(mpp[key]);
            insert(mpp[key]);
            return mpp[key]->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (mpp.find(key)!=mpp.end()){
            removeNode(mpp[key]);
            insert(mpp[key]);
            mpp[key]->val=value;
        }else if (mpp.size()<cap){
            Node* temp=new Node(key,value);
            insert(temp);
            mpp[key]=temp;
            
        }else{
            Node* temp=tail->prev;
            removeNode(temp);
            mpp.erase(temp->key);
            delete temp;
            Node* newNode=new Node(key,value);
            insert(newNode);
            mpp[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
