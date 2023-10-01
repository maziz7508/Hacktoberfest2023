#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << ": ";
    if (root->left)
    {
        cout << "L" << root->left->data;
    }
    if (root->right)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftBacha = takeInput();
    BinaryTreeNode<int> *rightBacha = takeInput();
    root->left = leftBacha;
    root->right = rightBacha;
    return root;
}

BinaryTreeNode<int> *takeInputLevel()
{
    int num;
    cin >> num;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(num);
    queue<BinaryTreeNode<int> *> bus;
    bus.push(root);
    while (!bus.empty())
    {
        auto front = bus.front();
        bus.pop();
        int x;
        cin >> x;
        if (x != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(x);
            front->left = newNode;
            bus.push(newNode);
        }
        else
            front->left = NULL;
        int y;
        cin >> y;
        if (y != -1)
        {
            BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(y);
            front->right = node1;
            bus.push(node1);
        }
        else
            front->right = NULL;
    }
    return root;
}

void printTreeLevel(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    queue<BinaryTreeNode<int> *> bus;
    bus.push(root);
    while (bus.size() != 0)
    {
        auto front = bus.front();
        bus.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            bus.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            bus.push(front->right);
        }
        cout << endl;
    }
}

int nodeFrequency(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return 1 + nodeFrequency(root->left) + nodeFrequency(root->right);
}

bool xPresentOrNot(BinaryTreeNode<int> *root, int x)
{
    if (!root)
        return 0;
    if (root->data == x)
        return true;
    return xPresentOrNot(root->left, x) || xPresentOrNot(root->right, x);
}

int binaryheight(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return 1 + max(binaryheight(root->left), binaryheight(root->right));
}

void mirrorTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    auto temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// constructing tree

// simplifying function

BinaryTreeNode<int> *majdoorFunction(vector<int> pre, vector<int> ino, int ins, int ine, int ps, int pe)
{
    if (ins > ine || ps > pe)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[ps]);
    int rootIndex = -1;
    for (int i = ins; i <= ine; i++)
    {
        if (ino[i] == pre[ps])
        {
            rootIndex = i;
            break;
        }
    }
    int linS = ins;
    int linE = rootIndex - 1;
    int lprS = ps + 1;
    int lprE = linE - linS + lprS;
    int rinS = rootIndex + 1;
    int rinE = ine;
    int rprS = lprE + 1;
    int rprE = pe;
    root->left = majdoorFunction(pre, ino, linS, linE, lprS, lprE);
    root->right = majdoorFunction(pre, ino, rinS, rinE, rprS, rprE);
    return root;
}

BinaryTreeNode<int> *majboorfunction(vector<int> inorder, vector<int> postorder, int ins, int ine, int ps, int pe, unordered_map<int, int> umap)
{
    if (ins > ine || ps > pe)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[pe]);
    int rootIndex = umap[postorder[pe]];
    int rinS = rootIndex + 1;
    int rinE = ine;
    int rpE = pe - 1;
    int rpS = rpE - rinE + rinS;
    int linS = ins;
    int linE = rootIndex - 1;
    int lpS = ps;
    int lpE = rpS - 1;
    root->left = majboorfunction(inorder, postorder, linS, linE, lpS, lpE, umap);
    root->right = majboorfunction(inorder, postorder, rinS, rinE, rpS, rpE, umap);
    return root;
}

BinaryTreeNode<int> *constructFromPreorderInorder()
{
    int n;
    cin >> n;
    vector<int> inOrder(n);
    vector<int> preOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    BinaryTreeNode<int> *root = majdoorFunction(preOrder, inOrder, 0, inOrder.size() - 1, 0, preOrder.size() - 1);
    return root;
}
BinaryTreeNode<int> *constructFromPostorderInorder()
{
    int n;
    cin >> n;
    unordered_map<int, int> umap;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        umap[inorder[i]] = i;
    }
    BinaryTreeNode<int> *root = majboorfunction(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, umap);
    return root;
}

pair<int, int> minmax(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return make_pair(INT_MIN, INT_MAX);
    }
    auto p1 = minmax(root->left);
    auto p2 = minmax(root->right);
    auto p3 = make_pair(max(root->data, max(p1.first, p2.first)), min(root->data, min(p1.second, p2.second)));
    return p3;
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (!root)
        return make_pair(0, 0);
    auto p1 = heightDiameter(root->left);
    auto p2 = heightDiameter(root->right);
    return make_pair(1 + max(p1.first, p2.first), max(p1.first + p2.first, max(p1.second, p2.second)));
}

bool balanced(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return abs(binaryheight(root->left) - binaryheight(root->right)) <= 1 ? true : false;
}

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreeNode<int> *root = takeInputLevel();
    // printTreeLevel(root);
    // cout << endl;
    // cout << nodeFrequency(root);
    // cout << xPresentOrNot(root, 4);
    // cout << binaryheight(root);
    // mirrorTree(root);
    // cout << "preOrder: ";
    // preOrder(root);
    // cout << endl;
    // cout << "inOrder: ";
    // inOrder(root);

    // BinaryTreeNode<int> *root = constructFromPostorderInorder();
    // cout << endl;
    // cout << "Maximum: " << minmax(root).first << endl;
    // cout << "Minimum: " << minmax(root).second << endl;
    // auto p1 = heightDiameter(root);
    // printTreeLevel(root);
    // cout << endl;
    // cout << p1.first;
    // cout << endl;
    // cout << p1.second;
    // cout << balanced(root) << endl;
    BinaryTreeNode<int> *root = takeInputLevel();
    // 1 2 3 -1 -1 -1 -1
    delete root;
}