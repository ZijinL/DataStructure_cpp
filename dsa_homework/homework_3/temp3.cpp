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
    que.push(T);
    while(!que.empty())
    {
        if (que.front()->left) que.push(que.front()->left);
        else if (que.front()->right) que.push(que.front()->right);
        visit(que.front());
        que.pop();
    } 
}

// 比较运算符优先级
int comOper(char x, char y)
{
    if (x == y) return 0;

    if (x == '*')
    {
        if (y == '/') return 0;
        else return 1;
    }
    else if (x == '/')
    {
        if (y == '*') return 0;
        else return 1;
    }
    else if (x == '+')
    {
        if (y == '-') return 0;
        else return -1;
    }
    else if (x == '-')
    {
        if (y == '+') return 0;
        else return -1;
    }
    // 其他情况应该报异常
    return 2;
}

// 建立表达式二叉树
node* buildTree(vector<node*> expr)
{
    // 分别定义操作符栈和操作数栈
    stack<node*> stk_oper, stk_operand;
    for(node* item: expr)
    {
        if (isalpha(item->data))
        {
            stk_operand.push(item);
        }
        else if (stk_oper.empty() || comOper(item->data, stk_oper.top()->data)==1)
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



int main()
{
    // 构造由运算符和运算数结点组成的容器
    vector<node*> expression;
    for (char item: "a+b*c-d+e")
    {
        node* temp = new node(item);
        expression.push_back(temp);
    }
    node* tree = buildTree(expression);
    cout << tree->data;
    // midOrder(tree);
}



