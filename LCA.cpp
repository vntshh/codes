bool findpath(TreeNode* root, int num, vector<int> &v) {
    if(root == NULL) return false;
    v.push_back(root->val);
    if(root -> val == num) return true;
    if(findpath(root->left, num, v) || findpath(root->right, num, v)) return true;
    v.pop_back();
    return false;
}
int Solution::lca(TreeNode* A, int val1, int val2) {
    vector<int> path1, path2;
    findpath(A, val1, path1);
    findpath(A, val2, path2);
    int lca = -1;
    for(int i = 0; i < min(path1.size(), path2.size()); i++) {
        if(path1[i] != path2[i]) break;
        lca = path1[i];
    }
    return lca;
}
