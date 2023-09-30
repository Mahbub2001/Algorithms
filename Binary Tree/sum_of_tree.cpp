#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* take_input(){

    int val;
    cin>>val;
    queue<Node*>q;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else{
        root= new Node(val);
    }

    if(root) q.push(root);

    while(!q.empty()){

        Node *f = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node *myLeft;
        Node *myRight;

        if(l == -1){
            myLeft = NULL;
        }
        else{
            myLeft = new Node(l);
        }
        if(r == -1){
            myRight = NULL;
        }
        else{
            myRight = new Node(r);
        }

        f->left = myLeft;
        f->right = myRight;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);

    }
    return root;

}

int get_sum(Node* root){
    queue<Node*>q;
    if(root)q.push(root);
    long long sum = 0;

    while (!q.empty())
    {
        Node* f = q.front();
        q.pop();

        sum+=f->val;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return sum;

}

int main()
{

    Node* root = take_input();
    cout<<get_sum(root)<<endl;

    return 0;
}