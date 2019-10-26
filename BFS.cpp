#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node * right;
    Node * left;

    Node(int d) {
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

vector<int> BFS(Node* root)
{
    queue<Node*> q;
    vector<int> v;
    Node* t;
    q.push(root);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t->right!=nullptr) q.push(t->right);
        if(t->left!=nullptr)  q.push(t->left);

        v.push_back(t->data);
    }
    return v;
}
// Construct a test tree
Node* Build_tree()
{
 Node * root = new Node(0);
    root->left =new Node(1);
    root->right = new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
    root->right->left= new Node(5);
    root->right->right= new Node(6);

return root;
}


int main()
{

    vector<int> v =BFS(Build_tree());
    for(int i: v)
    {
        cout<<i<<" ";

    }
    cout<<endl;
    return 0;
}
