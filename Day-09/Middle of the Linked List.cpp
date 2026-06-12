class Node {
public:
    int data;  
    Node* next;     
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle node.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle node by moving
    while (temp != null) {
        mid = mid - 1;
        if (mid == 0){
        
            break;
        }
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}
