// author: jaydattpatel
/*
CREATE BINARY TREE
                                                    
                                                      (1,A)
                                         _______________|________________        
                                         |                              |
                                       (2,B)                          (3,C)
                                 ________|________              ________|________        
                                 |               |              |               |
                               (4,D)          (5,E)           (6,F)           (7,G)
                              ___|___        ___|___         ___|___         ___|___
                              |     |        |     |         |     |         |     |
                            (8,H)  (9,I)  (10,J)  (11,K)  (12,L)  (13,M)  (14,N)  (15,O)
                            
Inorder is: [4, D]  [2, B]  [5, E]  [1, A]  [6, F]  [3, C]  [7, G]
Preorder is: [1, A]  [2, B]  [4, D]  [5, E]  [3, C]  [6, F]  [7, G]
Postorder is: [4, D]  [5, E]  [2, B]  [6, F]  [7, G]  [3, C]  [1, A]
BFS levelorder is:  [1, A]   [2, B]   [3, C]   [4, D]   [5, E]   [6, F]   [7, G]
Height of Tree : 3
DFS levelorder is: [4, D]  [5, E]  [6, F]  [7, G]  [2, B]  [3, C]  [1, A]
Print value of level:
        Level-1: [1, A]
        Level-2: [2, B]  [3, C]
        Level-3: [4, D]  [5, E]  [6, F]  [7, G] 
*/    
#include<iostream>
#include<deque>
using namespace std;


class BTree
{
   public: 
        BTree *left;
        BTree *right;
        int data;
        string ss; 

        BTree() //constructor
        {
            left = NULL;
            right = NULL;
            cout<<"\nNew constructed\n";
        }

        ~BTree()    //deconstructor
        {
            cout<<"\nFree: ["<<this->data<<", "<<this->ss<<"] ";
            delete(this->left);
            delete(this->right);
        }

        BTree *create(BTree *root);
        void postorder(BTree *root);
        void inorder(BTree *root);
        void preorder(BTree *root);
        void BFS_levelOrder(BTree *root);
        int height(BTree* root);
        void DFS_depthOrder(BTree *root);
        void printCurrentLevel(BTree* root, int level);

};

BTree* BTree::create(BTree *root)
{
    if(root==NULL)
    {
        root = new BTree;
        root->right=NULL;
        root->left=NULL;
        cout<<"Enter the value :";
        cin>>root->data;
        cout<<"Enter the string:";
        cin>>root->ss;
    }
    char c;
    cout<<"Left node of ["<<root->data<<", "<<root->ss<<"] (y/n) ? : ";
    cin>>c;
    if(c=='y'||c=='Y')
            root->left=create(root->left);

    cout<<"Right node of ["<<root->data<<", "<<root->ss<<"] (y/n) ? : ";
    cin>>c;
    if(c=='y'||c=='Y')
            root->right=create(root->right);

    cout<<"\n\n";
    return(root);
}
void BTree::inorder(BTree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<" ["<<root->data<<", "<<root->ss<<"] ";
    inorder(root->right);
}

void BTree::preorder(BTree *root)
{
    if(root==NULL)
    return;
    cout<<" ["<<root->data<<", "<<root->ss<<"] ";
    preorder(root->left);
    preorder(root->right);
}

void BTree::postorder(BTree *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<" ["<<root->data<<", "<<root->ss<<"] ";
}

//BFS : Breadth First Search(Level order search) in Binary Tree
void BTree::BFS_levelOrder(BTree *root)
    {
            deque< BTree* > deq;
            deq.push_back(root);
            while(!deq.empty())
            {
                cout<<"  ["<<deq[0]->data<<", "<<deq[0]->ss<<"] ";
                if(deq[0]->left != NULL)
                    deq.push_back(deq[0]->left);
                if(deq[0]->right != NULL)
                    deq.push_back(deq[0]->right);
                deq.pop_front();
            }
    }


int BTree::height(BTree* root)
{
	if (root == NULL)
		return 0;
	else 
        {
            // compute the height of each subtree 
            int left_height = height(root->left);
            int right_height = height(root->right);

            // use the larger one 
            if (left_height > right_height) 
                return (left_height + 1);
            else 
                return (right_height + 1);
            
	    }
}

//DFS : Depth First Search in Binary Tree
void BTree::DFS_depthOrder(BTree *root)
    {
        int hh = root->height(root);
        for(int i=hh ; i>=0; i--)     
            root->printCurrentLevel(root,i);  
    }

void BTree::printCurrentLevel(BTree* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout<<" ["<<root->data<<", "<<root->ss<<"] ";
	else if (level > 1) 
    {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int main()
{
    BTree *root = NULL;
    char c;
    while(1)
    {
        root = root->create(root);
        cout<<"Do you want to continue(y/n):";
        cin>>c;
        if(c=='n'||c=='N')
            break;
    }
    cout<<"\nInorder is:";
    root->inorder(root);

    cout<<"\nPreorder is:";
    root->preorder(root);

    cout<<"\nPostorder is:";
    root->postorder(root);

    cout<<"\nBFS levelorder is:";
    root->BFS_levelOrder(root);

    int hh = root->height(root);
    cout<<"\nHeight of Tree : "<<hh;

    cout<<"\nDFS levelorder is:";
    root->DFS_depthOrder(root);

    cout<<"\nPrint value of level:";
    for(int i=1; i<=hh; i++)
        {
            cout<<"\n\tLevel-"<<i<<":";
            root->printCurrentLevel(root,i);
        }

    delete(root);
    
    return 0;

}

