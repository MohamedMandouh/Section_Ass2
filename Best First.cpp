#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char data;
    Node * right;
    Node * left;
    int h;

    Node(char d,int he) {
        data=d;
        h=he;
        left=nullptr;
        right=nullptr;
    }
};

struct comparator {
 bool operator()(Node* i, Node* j) {
 return i->h > j->h;
 }
};
vector<char> BFS(Node* root,char goal)
{
    vector<bool> visited(100,false);
    priority_queue<Node*,vector<Node*>,comparator> pq;
    vector<char> res;
    Node* t;
    pq.push(root);
    while(!pq.empty())
    {
        t=pq.top();
        pq.pop();
        if(t->data==goal)
        {
            res.push_back(t->data);
            return res;
        }
        if(t->left!=nullptr)
        {
            if(visited[t->left->data]==false)
            {
            visited[t->left->data]==true;
            pq.push(t->left);
            }
        }
        if(t->right!=nullptr)
        {
           if(visited[t->data]==false)
            {
            visited[t->right->data]==true;
            pq.push(t->right);
            }
        }
        res.push_back(t->data);
    }
    return res;
}
// Construct a test tree
Node* Build_tree()
{
 Node * root = new Node('S',0);
    root->left =new Node('A',3);
    root->right = new Node('C',5);
    root->left->left= new Node('D',9);
    root->left->right= new Node('E',8);
    root->right->left= new Node('H',7);
    root->right->right= nullptr;
    root->right->left->left= new Node('I',5);
    root->right->left->right= new Node('J',6);
    root->right->right= nullptr;

return root;
}


int main()
{
    Node * r = Build_tree();
    vector<char> v =BFS(r,'I');
    for(char i: v)
    {
        cout<<i<<" ";

    }
    cout<<endl;
    return 0;
}
