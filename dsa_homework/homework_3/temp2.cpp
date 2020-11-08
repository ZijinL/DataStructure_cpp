# include <iostream>
# include <string>
# include <stack>
# include <queue>
# include <vector>

using namespace std;

// 定义结点
struct node {
    char data;
    node *left, *right;
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
}


// 建立表达式二叉树
node* buildTree(string str)
{
    // 是不带括号的中缀表达式
    str = "a+b*c-d+e";
    vector<node*> expr;
    for (char item: str)
    {
        node* temp;
        temp->data=item;
        expr.push_back(temp);
    }
    // 分别定义操作符栈和操作数栈
    stack<node*> stk_oper, stk_operand;
    for(node* item: expr)
    {
        if (isdigit(item->data))
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
}

int main()
{
    node node1('a'), node2('b');
    cout << node1.data << endl << node2.data;
}



