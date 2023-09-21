#include <iostream>

class Queue {
    public:
        Queue(){
            size = 10;
            arr = new int[size]{};
        }
        Queue(int size) {
            this->size = size;
            arr = new int(size);
            front = -1;
            rear = -1;
        }

        void enter_element(int );
        int delete_element();
        bool overFlow();
        bool underFlow();
        ~Queue();

    private:
        int *arr;
        int size;
        int front;
        int rear;
    
    friend std::ostream& operator << (std::ostream&, Queue &);
};


int main(){
    Queue q1(4);

    std::cout<< q1.delete_element() << " : deleted \n";
    q1.enter_element(9);
    q1.enter_element(10);
    q1.enter_element(11);
    q1.enter_element(30);
    std::cout << q1 << "\n";

    std::cout << "q1: \n" << q1 << "\n";

    std::cout<< "deleted : " << q1.delete_element() << "\n";
    std::cout<< "deleted : " << q1.delete_element() << "\n";
    
    q1.enter_element(40);
    q1.enter_element(58);

    std::cout << "q1: \n" << q1 << "\n";

    return 0;
}

void Queue::enter_element(int val){
    if(overFlow()){
        std::cout<<"OVERFLOW\n";
    }
    else{
        if(front == -1 || rear == -1)
            front = rear = 0;
        else
            ++rear;
        arr[rear] = val;
    }
}

int Queue::delete_element(){
    if(underFlow()){
        std::cout << "EMPTY QUEUE status : ";
        return -999999;
    }
    int element = arr[front++];
    return element;
}

bool Queue::overFlow(){
    if(front > rear || rear == (size - 1))
        return true;
    return false;
}

bool Queue::underFlow(){
    if(front > rear || front == -1 || rear == -1)
        return true;
    return false;
}

std::ostream& operator << (std::ostream& out, Queue& q ){
    std::cout << "Display Queue\n";
    std::cout << "front : " << q.front << "rear : " << q.rear << "\n";
    if(q.front == -1 || q.rear == -1 || q.front > q.rear)
        out<<"Empty Queue\n";
    else
        for(int i = q.front; i <= q.rear; i++)
            out << q.arr[i] <<" ";
    return out;
}

Queue::~Queue(){
    std::cout<<"~Queue \n";
}