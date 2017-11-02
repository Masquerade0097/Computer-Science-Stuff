#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

#include <iostream>
#include <cstring>

using namespace std;

//structure	
template<class Item>
struct node{
	Item data;
	node<Item> *next;
};

template<class Item>
class LinearList{

	private:
		int MaxSize;
		struct node<Item> *head;
		struct node<Item> *temp;
		struct node<Item> *newNode;
		struct node<Item> *current;

		/* create a new node ( dynamic memory allocation )
		* */
		node<Item> *createNode(int value);

	public:
		int len;
		
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize);

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i); //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty();

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length();

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize();

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteIndex(const int  k);

		bool deleteKey(const Item& x);

		/* Replace the kth element with the new element 
		* */
		void replace(const int  k,const Item& x);

		/* Prints the current list
		* */
		void printList(void);	

		void append(const Item& x);

		void appendFront(const Item& x);
		
		Item pop();
};

template<class Item>
LinearList<Item>::LinearList(){
	MaxSize = 0;
	len = 0;
	head = NULL;
	temp = NULL;
	newNode = NULL;
	current = NULL;
}

template<class Item>
LinearList<Item>::~LinearList(){
	MaxSize = 0;
	len = 0;
	head = NULL;
}

template<class Item>
node<Item>* LinearList<Item>::createNode(int value){

    struct node<Item> *t;
    t = new(struct node<Item>); 
    if (t == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        t->data = value;
        t->next = NULL;     
        return t;
    }
}

template<class Item>
LinearList<Item>::LinearList(const int& maxListSizePoint){
	MaxSize = maxListSizePoint;
	len = 0;
	head = NULL;
}

template<class Item>
bool LinearList<Item>::isEmpty(){
	if(head == NULL){
		return true;
	}
	else
		return false;
}

template<class Item>
int LinearList<Item>::maxSize(){
	return MaxSize;
}

template<class Item>
int LinearList<Item>::length(){
	return len;
}

template<class Item>
void LinearList<Item>::deleteIndex(const int k){
	if(k>len){
		cout << "Element to delete has index greater than length of list" ;
	}
	temp = head;
	for(int i=0;i<k-2;i++){
		temp=temp->next;
	}
	current = temp->next;
	temp->next = current->next;
	current->next = NULL;
	delete current;
	current = NULL;
	len--;
}

template<class Item>
bool LinearList<Item>::deleteKey(const Item& x){
	
	temp = head;
	int nodeNo=1;

	for(int i=0;i<len;i++){
		if(temp->data == x){
			deleteIndex(nodeNo);
			return true;
		}else{
			temp= temp->next;
			nodeNo++;
		}
	}
	return false;
}


template<class Item>
void LinearList<Item>::replace(const int  k,const Item& x){
	temp = head;
	if(k > len){
		cout << "Can't replace : Maximum size exceeded" << endl;
	}
	if(k==1){
		temp->data = x;
		// cout << "Item is replaced : " << temp->data << endl;
		return ;
	}
	else if(k > 1){
		for(int i=0;i<k-1;i++){
			temp=temp->next;
		}
	}
	temp->data = x;
	// cout << "Item is replaced : " << temp->data << endl;
}

template<class Item>
void LinearList<Item>::printList( void ){
	temp = head;
	cout << "Printing the list -- " << endl;
	if(temp == NULL){
		cout << "No list there to print" << endl;
		return;
	}
	cout << temp->data << endl;
	for(int i=0;i<len-2;i++){
		temp = temp->next;
		cout << "  ,  " << endl;
		cout << "**/  " << temp->data << endl;
	}
}


template<class Item>
void LinearList<Item>::append(const Item& x){
	if(len==MaxSize){
		MaxSize+=1;
	}
	if(head==NULL){
		MaxSize+=1;
		head = createNode(x);
		head->next = NULL;
		len++;
		// cout << "New appended len is - " << len << endl;
		return;
	}
	else{
		temp = head;

		for(int i=0;i<len-1;i++){
			temp = temp->next;
		}

		newNode = createNode(-3);
		newNode->data = x;
		newNode->next = temp->next;
		temp->next = newNode;
	}

	len++;
	// cout << "New appended len is - " << len << endl;
	// cout << "New appended value is - " << newNode->data << endl;
}

template<class Item>
void LinearList<Item>::appendFront(const Item& x){
if(len==MaxSize){
		MaxSize+=1;
	}
	if(head==NULL){
		MaxSize+=1;
		head = createNode(x);
		head->next = NULL;
		len++;
		return;
	}
	else{
		temp = head;
		newNode = createNode(-3);
		newNode->data = x;
		head = newNode;
		newNode->next = temp;
		newNode = NULL;
		temp = NULL;
	}

	len++;
}

template<class Item>
bool LinearList<Item>::find(const Item& x){

	temp = head;
	for(int i=0;i<len;i++){
		if(temp->data == x){
			return true;
		}else{
			temp=temp->next;
		}
	}
	return false;
}

template<class Item>
Item LinearList<Item>::pop(){
	if(head == NULL){
		cout << "Can't pop, underflow" << endl;
		return -1;	
	}else{
		Item& r = head->data;
		head = head->next;
		len--;
		MaxSize--;
		return r;
	}

}




#endif
