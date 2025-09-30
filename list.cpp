#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }
    
    void push_front(int val){
        Node* newNode = new Node(val);  //dynamic
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "invalid pos\n";
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout << "invalid pos\n";
                return;
            }
            temp = temp->next;         
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAt(int pos) {
    if (pos < 0) {
        cout << "invalid pos\n";
        return;
    }

    // deleting from head
    if (pos == 0) {
        if (head == NULL) {
            cout << "list is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            cout << "invalid pos\n";
            return;
        }
        temp = temp->next;
    }

    // temp points to node before the one to be deleted
    Node* delNode = temp->next;
    if (delNode == NULL) {
        cout << "invalid pos\n";
        return;
    }
    temp->next = delNode->next;
    delete delNode;
    }

    int search(int key){
        Node*  temp  = head;
        int index = 0;

        while(temp != NULL){
            if(temp->data == key){
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void printLL(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp -> data << "->";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
};
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool IsCycle = false;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                IsCycle = true;
                break;
            }
        }
        if(IsCycle == false){
            return NULL;
        }
        slow = head;
        ListNode* prev = NULL;
        while(slow!=fast){
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }
        prev->next = NULL;  //remove cycle    
        return slow;
    
    }
};
*/

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);

    ll.pop_front();
    ll.pop_back();

    ll.insert(4,1);
    ll.printLL();

    cout << ll.search(2) << endl;

    return 0;
}
