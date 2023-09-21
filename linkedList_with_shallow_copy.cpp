#include <iostream>
#include <string>

class Node {
public:
	int data;
	Node *next;
	Node() : data(0), next(nullptr) {}             // default constructor
	Node(int data) : data(data), next(nullptr) {}  // parameterized constructor
};

class LinkedList {
friend std::ostream& operator<<(std::ostream&, LinkedList&);
public:
	LinkedList() : head(nullptr) {}                // default constructor
	LinkedList(int data) : head(new Node(data)) {} // parameterized constructor
	LinkedList(const LinkedList&);                 // copy constructor
	~LinkedList();                                 // destructor
	
	void addNewNode(int data);        // add a node at the end of the list
	void removeNode();                // remove a node from the head of the list
private:
	Node *head;
};

// custom copy constructor to be written 
LinkedList::LinkedList(const LinkedList& list) {
	head = new Node(list.head->data);
	Node * ptr = list.head->next;
	while(ptr){
		addNewNode(ptr->data);
		ptr = ptr->next;
	}
}

// custom destructor to be written
LinkedList::~LinkedList() {
	std::cout << "\ndestructor\n";
	Node * curr = head;
	while(head){
		head = head->next;
		std::cout << curr->data << " ";
		delete curr;
		curr = head;
	}
	delete curr;
}

void LinkedList::addNewNode(int data) {
	// keyword <new> should return a non zero number (address) if successful
	Node * newNode = new Node(data);  
	
	if(!newNode) {
		std::cout << "failed to create a new node";
		return; // you can return a Boolean 'false' to communicate 'failure'?
	}
	
	// case of first node in the LinkedList
	if (head == nullptr) {
		head = newNode;
		return;  // you can return a Boolean 'true' to communicate 'success' too
	}	
	
	// any other node
	Node * cur = head;
	while(cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = newNode;
	return;  // you can return a Boolean 'true' to communicate 'success' too
}

void LinkedList::removeNode() {
// remove node from the head of the list
	if (head == nullptr) {
		return;
	}
	
	Node * cur = head;
	head = cur->next;   // move head to the next node
	delete cur;	        // now delete the head (earlier) node
}

std::ostream& operator << (std::ostream &os , LinkedList &ll) {
	Node *cur = ll.head;
	
	if(cur == nullptr) {
		os << "empty linked list";
		return os;
	}
	
	// for your linkedList to display
	while(cur->next != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	os << cur->data;
	return os; // return the formatted LinkedList to std::cout
}

// the following two functions are to format display of program and output 
void display(std::string str) {	std::cout << "\n" << str; }
void output() {	std::cout << "\nOUTPUT -  "; }

int main()
{
	// make true to false and vice-versa to see the output
	bool showStatementAndOutput = false ; 
	
	// to display the two program statement following this block 
	if (showStatementAndOutput){ 
		display("LinkedList varListOne;");
		display("std::cout << \"varListOne :\" << varListOne;");
		output(); 
	}
	
	LinkedList varListOne;
	std::cout << "varListOne : " << varListOne;
	
	std::cout << std::endl;
	// to display the following FOR loop after this block and its outcome
	if (showStatementAndOutput){ 
		display("for (int i = 1; i <= 10; i++) { \n\tvarListOne.addNewNode(i); \n}");
		display("std::cout << \"varListOne :\" << varListOne;");
		output(); 
	}
	
	for (int i = 1; i <= 10; i++) {
		varListOne.addNewNode(i); 		
	}
	std::cout << "varListOne : " << varListOne;
	
	std::cout << std::endl;
	// display the effects of the following assingment statement after this block 
	if (showStatementAndOutput){ 
		display("LinkedList varListTwo = varListOne;");
		display("std::cout << \"\\nvarListTwo : \" << varListTwo;");
		output(); 	
	}
	
	LinkedList varListTwo = varListOne;
	std::cout << "varListTwo : " << varListTwo;
	
	std::cout << std::endl;
	// display the effect of removing a node from list 2 on list 1 (shallow copy) 
	if (showStatementAndOutput){
		std::cout << std::endl;
		display("varListTwo.removeNode();");
		display("std::cout << \"varListTwo : \" << varListTwo;");
		output(); 
	}
	
	varListTwo.removeNode(); 
	std::cout << "varListTwo : " << varListTwo;
	
	std::cout << std::endl;
	// now what happens when we display varlistOne
	if (showStatementAndOutput){    
		display("std::cout << \"varListOne : \" << varListOne;");
		output(); 
	}
	
	// TRY THE FOLLOWING LINE ONCE AFTER COMMENTING AND UNCOMMENTING
	std::cout << "varListOne : " << varListOne;
	
	return 0;
}