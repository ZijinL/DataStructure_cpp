#include <iostream>
using namespace std;

// 1 线性表通用模板
template <class T>
class List
{
    public:
        void clear();
        int length();
        bool isEmpty();
        bool append(const T value);
        bool insert(const int p, const T value);
        bool delete(const int p);
        bool getPos(int& p, const T value);
        bool getValue(const int p, T& value);
        bool setValue(const inn p, const T value);
};

// 2 顺序表定义
template <class T>
class arrList: public List<T>
{
    private:
        T* aList;       //存储顺序表的实例
        int maxSize;    //顺序表最大长度
        int curLen;     //顺序表当前长度
        int position;   //当前处理位置
    public:
        arrList(const int size)  //构造函数，开辟空间
        {
            maxSize = size;
            aList = new T[maxSize];
            curLen = position = 0;
        }
        ~arrList()  // 析构函数，释放空间
        {
            delete [] aList;
        }
        void clear()
        {
            delete [] aList;
            curLen = position = 0;
            aList = new T[maxSize];
        }
};

// 2.1 顺序表插入的实现
template <class T>
bool arrList<T>::insert(const int p, const T value) //类模板 "arrList<T>" 没有成员 "insert"
{
    int i;
    if(curLen >= maxSize)  
    {  // 检查顺序表本身是否还可插入
        cout << "Overflow" << endl;
        return false;
    }
    if (p<0 || p>curLen)  
    {  //检查插入点位置是否正确
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for (i = curLen; i > p; i--)
    {  //从表尾开始逐个向后挪动
        aList[i] = aList[i-1];
    }
    aList[p] = valuee;
    curLeen++;
    return true;
    
}