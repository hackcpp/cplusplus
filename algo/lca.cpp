#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& values) {
    if (values.empty() || values[0] == "#") return nullptr;
    TreeNode* root = new TreeNode(stoi(values[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (values[i] != "#") {
            node->left = new TreeNode(stoi(values[i]));
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != "#") {
            node->right = new TreeNode(stoi(values[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// 查找最近公共祖先的主函数
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 基线条件：遇到空节点或找到目标节点时直接返回
    if (!root || root == p || root == q) return root;
    
    // 后序遍历：先递归处理左右子树
    TreeNode* left = lowestCommonAncestor(root->left, p, q);  // 左子树查找结果
    TreeNode* right = lowestCommonAncestor(root->right, p, q);// 右子树查找结果
    
    // 结果判断逻辑
    if (left && right) 
        return root;  // 当前节点是LCA的情况：左右子树各含一个目标节点
    return left ? left : right; // 单子树包含目标节点时，返回找到的结果（可能传递LCA或目标节点本身）
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

void testCase(const vector<string>& treeValues, int pVal, int qVal, int expected) {
    TreeNode* root = buildTree(treeValues);
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    
    cout << "Test case (" << pVal << ", " << qVal << "): ";
    if (lca && lca->val == expected) {
        cout << "✓ Passed (LCA = " << expected << ")";
    } else {
        cout << "✕ Failed (Expected " << expected 
             << ", Got " << (lca ? to_string(lca->val) : "null") << ")";
    }
    cout << endl << "----------------------------------------" << endl;
}

int main() {
    cout << endl << "========= LCA Test Results =========" << endl;
    // 测试案例1：节点5和1的LCA是3
    testCase({"3","5","1","6","2","0","8","#","#","7","4"}, 5, 1, 3);
    
    // 测试案例2：节点5和4的LCA是5
    testCase({"3","5","1","6","2","0","8","#","#","7","4"}, 5, 4, 5);
    
    // 测试案例3：节点2和7的LCA是2
    testCase({"3","5","1","6","2","0","8","#","#","7","4"}, 2, 7, 2);
    
    // 测试案例4：节点0和8的LCA是1
    testCase({"3","5","1","6","2","0","8","#","#","7","4"}, 0, 8, 1);
    
    return 0;
}
