

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

Node* lca(Node* root, int p, int q) {
    if (!root) {
        return nullptr;
    }
    if (root->data > p && root->data > q) {
        return lca(root->left, p, q);
    }
    if (root->data < p && root->data < q) {
        return lca(root->right, p, q);
    }
    return root;
}

