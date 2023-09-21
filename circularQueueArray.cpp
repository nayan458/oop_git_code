#include <iostream>

class CircularQueue {
    public:
        CircularQueue(){
            size = 10;
            arr = new int[size]{};
            front = -1;
            rear = -1;
        }
        CircularQueue(int size) {
            this->size = size;
            arr = new int(size);
            front = -1;
            rear = -1;
        }

        void enter_element(int );
        int delete_element();
        bool overFlow();
        bool underFlow();
        ~CircularQueue();

    private:
        int *arr;
        int size;
        int front;
        int rear;
    
    friend std::ostream& operator << (std::ostream&, CircularQueue &);
};


int main(){
    CircularQueue q1(5);

    q1.enter_element(9);
    q1.enter_element(10);
    q1.enter_element(11);
    q1.enter_element(30);
    q1.enter_element(46);

    std::cout << "q1: \n" << q1 << "\n";

    std::cout<< "deleted : " << q1.delete_element() << "\n";
    std::cout<< "deleted : " << q1.delete_element() << "\n";
    
    q1.enter_element(17);
    q1.enter_element(26);
    q1.enter_element(26);

    std::cout << "q1: \n" << q1 << "\n";
    q1.enter_element(26);

    return 0;
}

void CircularQueue::enter_element(int val){
    if(overFlow()){
        std::cout<<"OVERFLOW\n";
    }
    else{
        if(front == -1 || rear == -1)
            front = rear = 0;
        else
            rear = (rear + 1)%size;
        arr[rear] = val;
    }
}

int CircularQueue::delete_element(){
    if(underFlow()){
        std::cout << "EMPTY CircularQUEUE status : ";
        return -999999;
    }
    int element = arr[front];
    if( front == rear)
        front = rear = -1;
    else
        front = (front+1)%size;
    return element;
}

bool CircularQueue::overFlow(){
    if((rear+1)%5 == front)
        return true;
    return false;
}

bool CircularQueue::underFlow(){
    if(front == -1 || rear == -1 )
        return true;
    return false;
}

std::ostream& operator << (std::ostream& out, CircularQueue& q ){
    std::cout << "Display CircularQueue\n";
    std::cout << "front : " << q.front << " rear : " << q.rear << "\n";
    if(q.front == -1 || q.rear == -1)
        out<<"Empty CircularQueue\n";
    else{
        int i = q.front;
        if(q.front < q.rear){
            for(i; i <= q.rear ;i++){
                std::cout << q.arr[i] << " ";
            }
        }else{
            while(i != q.rear){
                std::cout << q.arr[i] << " ";
                i = (i+1)%q.size;
            }
            std::cout<<q.arr[i];
        }
        std::cout << "\n";
    }
    return out;
}

CircularQueue::~CircularQueue(){
    std::cout<<"~CircularQueue \n";
}