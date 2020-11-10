# include <iostream>
using namespace std;

template <class T>
class MinHeap
{
    "堆元素从0开始编号"
    private:
        T* heapArray;
        int CurrentSize;
        int MaxSize;
        void BuildHeap();
    public:
        MinHeap(const int n)
        {
            if (n <= 0) return;
            CurrentSize = 0;
            MaxSize = n;
            heapArray = new T[MaxSize];
            BuildHeap();
        }
        
        virtual ~MinHeap() {delete [] heapArray;}

        bool isLeaf(int pos) const {return (pos >= CurrentSize/2)&&(pos < CurrentSize);}

        int leftchild(int pos) const {return 2*pos + 1;}

        int rightchild(int pos) const {return 2*pos + 1;}

        int parent(int pos) const {return (pos-1)/2;}

        bool Remove(int pos, T& node);
        {

        }

        bool Insert(constT& newNode);

        T& RemoveMin();

        void SiftUp(int position)
        {
            int i = postion;


        }

        void SiftDown(int position)
        {
            int i = position;
            int j = 2*i + 1;
            T temp = heapArray[i];
            while (j < CurrentSize)
            {
                
            }

        }
}