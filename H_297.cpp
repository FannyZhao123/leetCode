/*
297. Serialize and Deserialize Binary Tree
rialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/


//Runtime: 128 ms, faster than 20.97% of C++ online submissions for Serialize and Deserialize Binary Tree.
//Memory Usage: 39.3 MB, less than 17.24% of C++ online submissions for Serialize and Deserialize Binary Tree.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }  
    // Helper for deserialization
    TreeNode* deserializeUtil(istringstream &ss) {
        string str;
        ss >> str;
        if (str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeUtil(ss);
        root->right = deserializeUtil(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeUtil(ss);
    }
};