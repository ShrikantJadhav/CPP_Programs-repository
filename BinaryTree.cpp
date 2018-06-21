#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

class BinaryTree
{
private:
    struct node *root;
    bool rootSet;
    int count;


    void copyTree(struct node **t, struct node **s)
    {
        if( *s != NULL)
        {
            insertIntoTree(t,(*s)->data);
            copyTree(t,&((*s)->left));
            copyTree(t,&((*s)->right));
        }
    }

    void preOrder(struct node **p)
    {
        if( *p != NULL)
        {
            preOrder(&((*p)->left));
            cout<<"\t"<<(*p)->data;
            preOrder(&((*p)->right));
        }
    }


public:
    //Empty constructor
    BinaryTree()
    {
        root = NULL;
    }

    //Constructor which initializes tree from input array
    BinaryTree(int a[], int n)
    {
        root = NULL;
        int i = 0;
        for(i=0; i<n; i++)
        {
            insertIntoTree(&root,a[i]);
        }
        count = i; //Number of nodes
    }

    //copy constructor
    BinaryTree(const BinaryTree &bt)
    {
        root = NULL;
        struct node *p;
        p = bt.root;
        copyTree(&root,&p);
    }

    void insertIntoTree(struct node **p,int d)
    {
        struct node *tmp = new node();
        tmp->data = d;
        tmp->left = NULL;
        tmp->right = NULL;

        if(*p == NULL)
        {
            if(rootSet == false)
            {
                root = tmp;
                rootSet = true;
            }
            *p = tmp;
        }
        else
        {
            if((*p)->data > d)
            {
                insertIntoTree(&((*p)->left),d);
            }
            else
            {
                insertIntoTree(&((*p)->right),d);
            }
        }
    }

    void print()
    {
        struct node *p;
        p = root;
        cout<<endl<<"Preorder traversal:";
        preOrder(&p);
    }

    void deleteItem(struct node **t,int d)
    {
        struct node *p;
        p = *t;

        if((*t)->left == NULL)
        {
            //Left subtree is NULL
            *t = (*t)->right;
        }
        else
        {
            if((*t)->right == NULL)
            {
                *t = (*t)->left;
            }
            else
            {
                //get the extreme right node of the left subtree
                *t = (*t)->left;
                while((*t)->right != NULL)
                {
                    *t = (*t)->right;
                }
                p->data = (*t)->data;
                searchAndDeleteItem(t,d);
            }
        }
    }

    void searchAndDeleteItem(struct node **t,int d)
    {
        if((*t)->data > d)
        {
            //Node to be deleted in left subtree
            searchAndDeleteItem(&((*t)->left),d);
        }
        else
        {
            if((*t)->data < d)
            {
                //Node to be deleted is in right subtree
                searchAndDeleteItem(&((*t)->right),d);
            }
            else
                //Node to be deleted is t
                deleteItem(t,d);
        }
    }

    void deleteNode(int d)
    {
        struct node *p;
        p = root;
        if( p == NULL)
        {
            return;
        }
        searchAndDeleteItem(&p,d);
    }

    void levelOrderPrint(){
        std::queue<struct node *> nodeQueue;
	    struct node *p;
	    p = root;

	    if( p == NULL) return;

	    nodeQueue.push(p);
	    std::cout<<"\nenqued: "<<(nodeQueue.front())->data;

        std::cout<<"\n";
	    while(!nodeQueue.empty()){
	       std::cout<<"\t"<<(nodeQueue.front())->data;
	       if((nodeQueue.front())->left)
	           nodeQueue.push((nodeQueue.front())->left);

	       if((nodeQueue.front())->right)
	           nodeQueue.push((nodeQueue.front())->right);

	       nodeQueue.pop();
	    }
    }
};

int main()
{
    int a[6] = {42,11,12,9,34,98};
    BinaryTree bt(a,6);
    bt.print();
    BinaryTree bt1(bt);
    bt1.print();
    bt1.deleteNode(98);
    bt1.print();
    bt1.levelOrderPrint();
    bt.levelOrderPrint();
    return 0;
}
