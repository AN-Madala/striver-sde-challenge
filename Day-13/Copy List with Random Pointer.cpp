/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertCopyInBetween(Node* head){
        Node* temp = head;

        while(temp){
            Node* nextNode = temp->next;

            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextNode;

            temp = nextNode;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;

        while(temp){
            Node* copyNode = temp->next;

            if(temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;

            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* temp = head;

        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {

        if(!head) return nullptr;

        insertCopyInBetween(head);

        connectRandomPointers(head);

        return getDeepCopyList(head);
    }
};
