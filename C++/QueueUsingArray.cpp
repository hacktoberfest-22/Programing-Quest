#include <iostream>
using namespace std;
class QueueUsingArray
{
    int *data;
    int frontIndex;
    int NextIndex;
    int Size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new int(s);
        frontIndex = -1;
        NextIndex = 0;
        Size = 0;
        capacity = s;
    }
    int GetSize()
    {
        return Size;
    }
    bool Isempty()
    {
        return Size == 0;
    }
    void Enqueue(int element)
    {
        if (Size == capacity)
        {
            cout << "Queue Is Full"<<endl;
        }
        else
        {
            data[NextIndex] = element;
            NextIndex = (NextIndex + 1) % capacity;
            if (frontIndex == -1)
            {
                frontIndex = 0;
            }
            Size++;
        }
    }
    int Front(){
        if (frontIndex==-1)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else{
            return data[frontIndex];
        }
        
    }
    int Dequeue(){
        if (frontIndex==-1)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            int ans=data[frontIndex];
            frontIndex=(frontIndex+1)%capacity;
            Size--;
            if (Size==0)
            {
                frontIndex=-1;
                NextIndex=0;
            }
            
            return ans;

        }

        
        
    }
};
int main()
{
  QueueUsingArray q(5);
  q.Enqueue(5);
  q.Enqueue(6);
  q.Enqueue(7);
  q.Enqueue(8);
  q.Enqueue(9);
  cout<<q.Front()<<endl;
  cout<<q.Isempty()<<endl;


    return 0;
}
