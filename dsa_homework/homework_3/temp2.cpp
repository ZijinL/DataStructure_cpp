# include <iostream>
# include <string>
# include <stack>
# include <queue>
# include <vector>

using namespace std;

// 定义结点
struct node {
    char data;
    node *left;
    node *right;
    node(char alpha = '\0')
    {
        data = alpha;
        left = nullptr;
        right = nullptr;
    }
};

// 访问结点
void visit(node *T)
{
    cout << T->data << " ";
}

// 前序遍历
void preOrder(node *T)
{    
    if (T != nullptr)
    {
        visit(T);
        preOrder(T->left);
        preOrder(T->right);
    }
}

// 中序遍历
void midOrder(node *T)
{    
    if (T != nullptr)
    {
        midOrder(T->left);
        visit(T);
        midOrder(T->right);
    }
}

// 后序遍历
void postOrder(node *T)
{    
    if (T != nullptr)
    {
        postOrder(T->left);
        postOrder(T->right);
        visit(T);
    }
}

// 层次遍历
void levelOrder(node *T)
{
    queue<node*> que;
    if (T) que.push(T);
    while(!que.empty())
    {
        if (que.front()->left) que.push(que.front()->left);
        if (que.front()->right) que.push(que.front()->right);
        visit(que.front());
        que.pop();
    } 
}

stack<node*> traceRoute(node* rt, node* p)
{
    stack<node*> stk;
    stk.push(rt);
    while(!stk.empty())
    {
        stk.push(rt->left);
        stk.push(rt->right);

    } 
    return stk;
}

// 比较运算符优先级
int comOper(char x, char y)
{
    if (x == y) return 0;
    if (y == '(') return 1;
    if (isalpha(y)) return -1;
    switch (x)
    {
        case '*':
            if (y == '/') return 0;
            else return 1;
        case '/':
            if (y == '*') return 0;
            else return 1;
        case '+':
            if (y == '-') return 0;
            else return -1;
        case '-':
            if (y == '+') return 0;
            else return -1;        
        // 其他情况应该报异常
        default:
            return 2;
    }
}

// 建立表达式二叉树
node* buildTree(string str = "(a+b*(c-d))*e")
{
    // 参数str是不带括号的中缀表达式
    // 构造由运算符和运算数结点组成的容器
    vector<node*> expr;
    for (char item: str)
    {
        node* temp = new node(item);
        expr.push_back(temp);
    }
    // 分别定义操作符栈和操作数栈
    stack<node*> stk_oper, stk_operand;
    for(node* item: expr)
    {
        if (item->data == ')')
        {
            while(stk_oper.top()->data != '(')
            {
                stk_oper.top()->right = stk_operand.top();
                stk_operand.pop();
                stk_oper.top()->left = stk_operand.top();
                stk_operand.pop();
                stk_operand.push(stk_oper.top());
                stk_oper.pop();
            }
            stk_oper.pop();
        }
        else if (isalpha(item->data))
        {
            stk_operand.push(item);
        }
        else if (item->data == '(' || stk_oper.empty() || comOper(item->data, stk_oper.top()->data)==1)
        {
            stk_oper.push(item);
        }
        else
        {
            while(!stk_oper.empty() && comOper(item->data, stk_oper.top()->data)<=0)
            {
                stk_oper.top()->right = stk_operand.top();
                stk_operand.pop();
                stk_oper.top()->left = stk_operand.top();
                stk_operand.pop();
                stk_operand.push(stk_oper.top());
                stk_oper.pop();
            }
            stk_oper.push(item);
        }  
    }
    while(!stk_oper.empty())
    {
        stk_oper.top()->right = stk_operand.top();
        stk_operand.pop();
        stk_oper.top()->left = stk_operand.top();
        stk_operand.pop();
        stk_operand.push(stk_oper.top());
        stk_oper.pop();
    }
    return stk_operand.top();
}

node* commonParent(node* rt, node* p, node* q)
{
    // 递归终止条件
	if (rt == nullptr || p == nullptr || q == nullptr)
		return nullptr;
 
	if (p ==rt || q ==rt)
		return rt;
	
    // 初始化当前指针
	node* cur = nullptr;
 
    // 结点是否同时在左子树中
	node* left_tree = commonParent(rt->left, p, q);
	if (left_tree)
	{
        // 首先继续访问左子树
		cur = commonParent(left_tree->left, p, q);
        // 如果左子树为空还未找到则访问右子树
		if (cur == nullptr)
		   cur = commonParent(left_tree->right, p, q);
        // 
		if ((cur == p) && (left_tree == q) || (cur == q) && (left_tree == p))
			return rt;
	}

    // 结点是否同时在右子树中
	node* right_tree = commonParent(rt->right, p, q);
	if (right_tree)
	{
		cur = commonParent(right_tree->left, p, q);
		if (cur == nullptr)
			cur = commonParent(right_tree->right, p, q);
		if ((cur == p) && (left_tree == q) || (cur == q) && (left_tree == p))
			return rt;
	}

	if (left_tree && right_tree)
		return rt;
	if (left_tree == nullptr)
		return right_tree;
	else
		return left_tree;
}

node* commonParent2(node* rt, node* p, node* q)
{
    if (!rt || rt == p || rt == q) return rt;
    node* left = commonParent2(rt->left, p, q);
    node* right = commonParent2(rt->right, p, q);
    if (!left) return right;
    if (!right) return left;
    return rt;
}

void inOrder_bracket(node* rt)
{
    // 如果为空直接返回
    if (!rt) return;
    // 先访问左子树
    if (rt->left)
    {
        // 如果存在运算符优先级逆序，则添加括号
        if (comOper(rt->data, rt->left->data) == 1)
        {
            cout << "( ";
            inOrder_bracket(rt->left);
            cout << ")";
        }
        else inOrder_bracket(rt->left);
    }
    cout << rt->data << " ";
    if (rt->right)
    {
        if (comOper(rt->data, rt->right->data) == 1)
        {
            cout << "( ";
            inOrder_bracket(rt->right);
            cout << ")";
        }
        else inOrder_bracket(rt->right);
    }
}

int countLeaves(node* rt)
{
    if (!rt) return 0;
    if (!rt->left && !rt->right) return 1;
    return countLeaves(rt->left) + countLeaves(rt->right);
}

int main()
{
    node* rt = buildTree();
    cout << endl << "preOrder: ";
    preOrder(rt);
    cout << endl << "midOrder: ";
    midOrder(rt);
    cout << endl << "Number of leaves: ";
    cout << countLeaves(rt);

}



