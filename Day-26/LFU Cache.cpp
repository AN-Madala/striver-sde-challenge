class Node {
public:
    int key, value, cnt;
    Node *next, *prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        cnt = 1;
        next = NULL;
        prev = NULL;
    }
};

class List {
public:
    int size;
    Node *head;
    Node *tail;

    List() {
        size = 0;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {

        Node *temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node *node) {

        Node *delPrev = node->prev;
        Node *delNext = node->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache {
public:

    int maxSizeCache;
    int minFreq;
    int curSize;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

    LFUCache(int capacity) {

        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreq(Node *node) {

        keyNode.erase(node->key);

        freqListMap[node->cnt]->removeNode(node);

        if(node->cnt == minFreq &&
           freqListMap[node->cnt]->size == 0) {

            minFreq++;
        }

        node->cnt++;

        List *nextHigherFreqList;

        if(freqListMap.find(node->cnt)
           != freqListMap.end()) {

            nextHigherFreqList =
                freqListMap[node->cnt];
        }
        else {

            nextHigherFreqList = new List();

            freqListMap[node->cnt] =
                nextHigherFreqList;
        }

        nextHigherFreqList->addFront(node);

        keyNode[node->key] = node;
    }

    int get(int key) {

        if(keyNode.find(key) ==
           keyNode.end()) {

            return -1;
        }

        Node *node = keyNode[key];

        int ans = node->value;

        updateFreq(node);

        return ans;
    }

    void put(int key, int value) {

        if(maxSizeCache == 0)
            return;

        if(keyNode.find(key)
           != keyNode.end()) {

            Node *node = keyNode[key];

            node->value = value;

            updateFreq(node);

            return;
        }

        if(curSize == maxSizeCache) {

            List *list = freqListMap[minFreq];

            Node *node =
                list->tail->prev;

            keyNode.erase(node->key);

            list->removeNode(node);

            curSize--;
        }

        curSize++;

        minFreq = 1;

        List *listFreq;

        if(freqListMap.find(minFreq)
           != freqListMap.end()) {

            listFreq =
                freqListMap[minFreq];
        }
        else {

            listFreq = new List();

            freqListMap[minFreq] =
                listFreq;
        }

        Node *node =
            new Node(key, value);

        listFreq->addFront(node);

        keyNode[key] = node;
    }
};
