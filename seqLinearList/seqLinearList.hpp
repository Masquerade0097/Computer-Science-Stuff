#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP

#include <iostream>
#include <cstring>

using namespace std;

//structure	
template<class Item,class Item2>
struct node{
	Item data;
	Item2 metaData;
	node<Item,Item2> *next;
};

template<class Item,class Item2>
class LinearList{

	private:
		int MaxSize;
		struct node<Item,Item2> *head;
		struct node<Item,Item2> *temp;
		struct node<Item,Item2> *newNode;
		struct node<Item,Item2> *current;

		/* create a new node ( dynamic memory allocation )
		* */
		node<Item,Item2> *createNode(int value);

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

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const Item& x);

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		Item2 search(const Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteIndex(const int  k);

		bool deleteKey(const Item& x);

		/* Insert x after k-th element.
		 * */
		// void  insert(const int  k, const Item& x, const Item2& y);

		/* Replace the kth element with the new element 
		* */
		void replace(const int  k,const Item& x);

		/* Prints the current list
		* */
		void printList(void);	

		void append(const Item& x, const Item2& y);

		void appendFront(const Item& x, const Item2& y);
};

template<class Item,class Item2>
LinearList<Item,Item2>::LinearList(){
	MaxSize = 0;
	len = 0;
	head = NULL;
	temp = NULL;
	newNode = NULL;
	current = NULL;
}

// template<class Item>
// Item& LinearList<Item>::operator[](const int& i){

// } 

template<class Item,class Item2>
LinearList<Item,Item2>::~LinearList(){
	MaxSize = 0;
	len = 0;
	head = NULL;
}

template<class Item,class Item2>
node<Item,Item2>* LinearList<Item,Item2>::createNode(int value){

    struct node<Item,Item2> *t;
    t = new(struct node<Item,Item2>); 
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

template<class Item,class Item2>
LinearList<Item,Item2>::LinearList(const int& maxListSizePoint){
	MaxSize = maxListSizePoint;
	len = 0;
	head = NULL;
	// // struct node *p = new node;
	// temp = head;
	// // p->data = 5;
	// for(int i=0;i<MaxSize-1;i++){
	// 	temp->next = createNode(-3);
	// 	temp = temp->next;
	// }
	// temp->next = NULL;
}

template<class Item,class Item2>
bool LinearList<Item,Item2>::isEmpty(){
	if(head == NULL){
		return true;
	}
	else
		return false;
}

// template<class Item,class Item2>
// void LinearList<Item,Item2>::insert(const int k, const Item& x, const Item2& y){
	
// 	temp = head;
// 	if(k>=MaxSize){
// 		while(k!=MaxSize){
// 			MaxSize+=1;
// 		}
// 		MaxSize += 1;
// 		for(int i=0;i<k-1;i++){
// 			temp = temp->next;
// 		}	
// 	}
// 	if(head == NULL){
// 		temp = createNode(-3);
// 		temp->data = x;
// 		temp->metaData = y;
// 		temp->next = NULL;
// 		head = temp;
// 		return ;
// 	}else{
		
// 		for(int i=0;i<k-1;i++){
// 			temp = temp->next;
// 		}
// 	}
// 	newNode = createNode(-3);
// 	newNode->data = x;
// 	newNode->metaData = y;
// 	newNode->next = temp->next;
// 	temp->next = newNode;

// 	cout << "Inside Inside -- " << endl << "value of len after insertion is"; 
// 	len++;
// 	cout << len << endl;
// }

template<class Item,class Item2>
int LinearList<Item,Item2>::maxSize(){
	return MaxSize;
}

template<class Item,class Item2>
int LinearList<Item,Item2>::length(){
	return len;
}

template<class Item,class Item2>
Item LinearList<Item,Item2>::returnListElement(const int k){
	if(k>len){
		cout << "Index is greater than maximum size" << endl;
		return -1;
	}
	if(k<=0){
		cout << "Invalid request: k must be positive" << endl;
		return -1;
	}
	temp = head;
	for(int i=0;i<k-1;i++){
		temp = temp->next;
	}
	// cout << "temp data returned is -- " << temp->data << endl;
	return temp->metaData;
}

template<class Item,class Item2>
void LinearList<Item,Item2>::deleteIndex(const int k){
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

template<class Item,class Item2>
bool LinearList<Item,Item2>::deleteKey(const Item& x){
	
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


template<class Item,class Item2>
void LinearList<Item,Item2>::replace(const int  k,const Item& x){
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

// template<class Item>
// void LinearList<Item>::printList( void ){
// 	temp = head;
// 	cout << "Printing the list -- " << endl;
// 	cout << temp->data << endl;
// 	for(int i=0;i<len-2;i++){
// 		temp = temp->next;
// 		cout << "  ,  " << endl;
// 		cout << "**/  " << temp->data << endl;
// 	}
// }

// template<class Item>
// void LinearList<Item>::moveBack(const int currentIndex){
// 	struct node<Item> *prev = head;
// 	for(i=0;i<currentIndex-2;i++){
// 		prev = prev->next;
// 	}
// 	current = prev;
// }


template<class Item,class Item2>
void LinearList<Item,Item2>::append(const Item& x, const Item2& y){
	if(len==MaxSize){
		MaxSize+=1;
	}
	if(head==NULL){
		MaxSize+=1;
		head = createNode(x);
		head->metaData = y;
		head->next = NULL;
		len++;
		cout << "New appended len is - " << len << endl;
		return;
	}
	else{
		temp = head;

		for(int i=0;i<len-1;i++){
			temp = temp->next;
		}

		newNode = createNode(-3);
		newNode->data = x;
		newNode->metaData = y;
		newNode->next = temp->next;
		temp->next = newNode;
	}

	len++;
	cout << "New appended len is - " << len << endl;
	cout << "New appended value is - " << newNode->data << endl;
}

template<class Item,class Item2>
void LinearList<Item,Item2>::appendFront(const Item& x, const Item2& y){
if(len==MaxSize){
		MaxSize+=1;
	}
	if(head==NULL){
		MaxSize+=1;
		head = createNode(x);
		head->metaData = y;
		head->next = NULL;
		len++;
		return;
	}
	else{
		temp = head;
		newNode = createNode(-3);
		newNode->data = x;
		newNode->metaData = y;
		head = newNode;
		newNode->next = temp;
		newNode = NULL;
		temp = NULL;
	}

	len++;
}

template<class Item,class Item2>
Item2 LinearList<Item,Item2>::search(const Item& x){

	temp = head;
	for(int i=0;i<len;i++){
		if(temp->data == x){
			return temp->metaData;
		}else{
			temp=temp->next;
		}
	}
	return -1;
}

template<class Item,class Item2>
bool LinearList<Item,Item2>::find(const Item& x){

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




#endif
