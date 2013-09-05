#include<iostream>

using namespace std;
struct node{
    int data;
    struct node *next;
};

class Llist{
private:
    struct node *head;
public:
    Llist(){ head = NULL;}
    Llist(int l1){
        addNode(l1);
    }

void addNode(int l){
    struct node *tmp = new node();
    struct node *p;
    p = head;
    tmp->data = l;
    tmp -> next = NULL;

    if(p== NULL){
        p = tmp;
        head = tmp;
    }
    else{
            while( p->next != NULL){
                p = p->next;
            }
            p->next = tmp;
    }
}

void addAtBegin(int l){
    struct node *tmp = new node();
    tmp->data = l;
    tmp -> next = head;
    head = tmp;
}

void Remove(int l){
    struct node *tmp = head;
    struct node *prev = head;

    if( tmp->data == l){
        head = head->next;
    }
    else{
        while(tmp->data != l){
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        delete tmp;
    }
}

//Function to remove nth element from the last
int PrintFromLast(int n){
    struct node *tmp = head;
    struct node *fastTmp = head;

    int i = 1;
    while( i <= n){
            fastTmp = fastTmp->next;
            i++;
    }
    while(fastTmp != NULL){
        fastTmp = fastTmp->next;
        tmp = tmp->next;
    }

    return tmp->data;
}

void printInReverse(){
    struct node *tmp;
    tmp = head;
    printReverse(&tmp);
}

void printReverse(struct node **h){
    if(*h == NULL){
            return;
    }
        printReverse(&((*h)->next));
        cout<<"\t"<<(*h)->data;
}

void print(){
    struct node *tmp;
    tmp = head;

    while(tmp != NULL){
        cout<<"\t"<<tmp->data;
        tmp = tmp->next;
    }
}

};

int main(){
    Llist l1;
    l1.addNode(98);
    l1.addNode(99);
    l1.addNode(89);
    l1.addNode(88);
    l1.addNode(99);
    l1.addAtBegin(79);
    l1.addAtBegin(77);
    l1.addAtBegin(89);
    l1.addNode(87);
    cout<<endl;
    l1.print();
    cout<<endl;
    cout<<l1.PrintFromLast(3);
    cout<<endl;
    l1.printInReverse();
    l1.Remove(79);
    cout<<endl;
    l1.print();
    l1.Remove(88);
    cout<<endl;
    l1.print();
    return 0;
}
