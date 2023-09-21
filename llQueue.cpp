#include <iostream>

class Node {
	public:
		Node() : data(0), next(nullptr){}
		Node(int data) : data(data), next(nullptr){}
		// ~Node() { data = 999999; next = nullptr; }
		void  setData(const int data) { this->data = data; }
		int   getData(void) { return data; }
		void  setNextNode(Node * next) { this->next = next; }
		Node* getNextNode(void) { return next; }
	private:
		int   data;
		Node* next;
};

class Queue {
	public:
		Queue() : head(nullptr){ front = head; rear = head; }
		Queue(int data) : head(new Node(data)){ front = head; rear = head;}	//	Queue(const Queue& Queue) {}  
		~Queue();
		
		void enqueue(int data);
		int  dequeue();
        void showFrontRear(){
            std::cout << "front: " << front->getData() << " rear: " << rear->getData();
        };
	private:
		Node *head;
        Node *front;
        Node *rear;

	friend std::ostream& operator<<(std::ostream&, Queue&);
};


void Queue::enqueue(int data) {
	Node* newNode = new Node(data);
	
	if(!newNode) {
		std::cout << "failed to create a new node";
		return;	//  you can return a Boolean 'false' to communicate 'failure'
	}
	
	// case of first node in the Queue
	if (head == nullptr) {
		head = newNode;
        front = rear = head;
		return;  // you can return a Boolean 'true' to communicate 'success' too
	}	
	
	// any other node
	Node* currentHead = head;
	while(currentHead->getNextNode() != nullptr) {
		currentHead = currentHead->getNextNode();
	}
	currentHead->setNextNode(newNode);
    rear = newNode;
}

int Queue::dequeue() {
	if (head == nullptr) {
		return -9999999;  // some error code
	}
	
	Node* currentHead = head;
	int   data = currentHead->getData();
	
	head = currentHead->getNextNode(); // move head to the next node
    front = head;
	delete currentHead;	               // delete the previous head
	currentHead = nullptr;
	return data;
}

Queue::~Queue() {
	// std::cout << "\n~Queue() called:\n";
	// Node* currentHead = head;
	// while(currentHead->getNextNode() != nullptr) {
	// 	head = currentHead->getNextNode();
	// 	std::cout << "\t" << reinterpret_cast<void *>(currentHead) << " : deleted" <<"\n" ;
	// 	currentHead = head;
	// }
	// delete currentHead;	
	// std::cout << "\t" << reinterpret_cast<void *>(currentHead) << " : deleted";
	// head = nullptr;
}

std::ostream& operator << (std::ostream& os , Queue& Queue) {
	Node *currentHead = Queue.head;  // save the original head
	
	// define how you want to display the Queue
	if(currentHead == nullptr) {  // linked list is empty
		os << ""; 
		return os;
	}
	
	while(currentHead->getNextNode() != nullptr) {  // not empty
		os << "\t" << reinterpret_cast<void *>(currentHead) << " : " << currentHead->getData() << "\n";
		currentHead = currentHead->getNextNode();
	}
	os << "\t" << reinterpret_cast<void *>(currentHead) << " : " << currentHead->getData();
	
	return os;
}

int main()
{
	Queue l1;
	std::cout << "Queue (l1) : " << l1;

	// make a linked list of some numbers;
	for (int i = 1; i <= 10; i++) {
		l1.enqueue(i); 
		std::cout << "\n   insert - " << i;		
	}
	std::cout << "\nQueue (l1) : \n" << l1;


    // l1.showFrontRear();
    // // std::cout << l1.dequeue() << std::endl;
    // l1.showFrontRear();
	
	Queue l2 = l1;  // i am using default copy constructor
	std::cout << "\nQueue (l2) : \n" << l2;
//	std::cout << "\nl1.removeData() : " << l1.dequeue();
//	std::cout << "\nl1.~Queue() : ";  l1.~Queue();
	std::cout << "\nQueue (l1) : \n" << l1;
	std::cout << "\nQueue (l2) : \n" << l2;
	
	return 0;
}