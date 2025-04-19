#include <iostream> 
#include <cstring>  
using namespace std; 
struct node { 
char data; 
node* left; 
node* right; 
}; 
class tree { 
char prefix[20]; 
public: 
node* top; 
tree() { top = NULL; } 
void expression(char[]); 
void display(node*); 
void non_rec_postorder(node*); 
void del(node*); 
}; 
class stack1 { 
node* data[30]; 
int top; 
public: 
stack1() { top = -1; } 
int empty() { return top == -1; } 
void push(node* p) { data[++top] = p; } 
node* pop() { return (top >= 0) ? data[top--] : NULL; } 
}; 
// Constructs expression tree from prefix expression 
void tree::expression(char prefix[]) { 
stack1 s; 
node *t1, *t2; 
int len = strlen(prefix); 
for (int i = len - 1; i >= 0; i--) { 
top = new node; 
        top->left = NULL; 
        top->right = NULL; 
        top->data = prefix[i]; 
 
        if (isalpha(prefix[i])) { 
            s.push(top); 
        } else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' || prefix[i] == '/') { 
            t1 = s.pop(); 
            t2 = s.pop(); 
            top->left = t1; 
            top->right = t2; 
            s.push(top); 
        } 
    } 
    top = s.pop(); 
} 
 
// Displays tree in inorder traversal 
void tree::display(node* root) { 
    if (root != NULL) { 
        display(root->left); 
        cout << root->data << " "; 
        display(root->right); 
    } 
} 
 
// Performs non-recursive postorder traversal 
void tree::non_rec_postorder(node* top) { 
    stack1 s1, s2; 
    node* T = top; 
     
    s1.push(T); 
    while (!s1.empty()) { 
        T = s1.pop(); 
        s2.push(T); 
        if (T->left != NULL) s1.push(T->left); 
        if (T->right != NULL) s1.push(T->right); 
    } 
 
    while (!s2.empty()) { 
        top = s2.pop(); 
        cout << top->data << " "; 
    } 
} 
 
// Deletes tree using postorder traversal 
void tree::del(node* node) { 
    if (node == NULL) return; 
 
    del(node->left); 
    del(node->right); 
    cout << "\nDeleting node: " << node->data; 
    delete node; 
} 
 
int main() { 
char expr[20]; 
tree t; 
cout << "Enter prefix Expression: "; 
cin >> expr; 
t.expression(expr); 
cout << "\nInorder Traversal: "; 
t.display(t.top); 
cout << "\npostorder Traversal: "; 
t.non_rec_postorder(t.top); 
t.del(t.top); 
t.top = NULL; 
cout<<endl; 
return 0; 
}