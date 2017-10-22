#ifndef DOUBLELINKQUEUE_HPP
#define DOUBLELINKQUEUE_HPP

#include <iostream>
#include <cstring>

using namespace std;

//structure	
template<class Item,class Item2>
struct tode{
	Item data;
	// Item2 metaData;
	tode<Item,Item2> *next;
	tode<Item,Item2> *prev;
};

template<class Item,class Item2>
class DoubleLinkQueue{

	private:
		int MaxSize;
		struct tode<Item,Item2> *head;
		struct tode<Item,Item2> *tail;
		/* create a new tode ( dynamic memory allocation )
		* */
		tode<Item,Item2> *createNode(int value);

	public:
		int len;
		
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		DoubleLinkQueue();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		DoubleLinkQueue(const int& MaxListSize);

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~DoubleLinkQueue();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * DoubleLinkQueue L;
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
		// Item  ReturnsKeyAtIndex(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const Item& x);

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		// Item2 returnValueForKey(const Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteNodeAtIndex(const int k);

		bool deleteNodeForKey(const Item& x);

		/* Insert x after k-th element.
		 * */
		// void  insert(const int  k, const Item& x, const Item2& y);

		/* Replace the kth element with the new element 
		* */
		void replace(const int  k,const Item& x);

		/* Prints the current list
		* */
		void printList(void);	

		void enqueue(const Item& x);
		void dequeue(void);

		void appendFront(const Item& x);
		int getIndexForKey(const Item& x);

		bool shiftKeyAtTail(const Item& x);
};

template<class Item,class Item2>
DoubleLinkQueue<Item,Item2>::DoubleLinkQueue(){
	MaxSize = 0;
	len = 0;
	head = NULL;
	tail = NULL;
}

// template<class Item>
// Item& DoubleLinkQueue<Item>::operator[](const int& i){

// } 

template<class Item,class Item2>
DoubleLinkQueue<Item,Item2>::~DoubleLinkQueue(){
	MaxSize = 0;
	len = 0;
	head = NULL;
	tail = NULL;
}

template<class Item,class Item2>
tode<Item,Item2>* DoubleLinkQueue<Item,Item2>::createNode(int value){

    struct tode<Item,Item2> *t;
    t = new(struct tode<Item,Item2>); 
    if (t == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        t->data = value;
        t->next = NULL;
        t->prev = NULL;     
        return t;
    }
}

template<class Item,class Item2>
DoubleLinkQueue<Item,Item2>::DoubleLinkQueue(const int& maxListSizePoint){
	MaxSize = maxListSizePoint;
	len = 0;
	head = NULL;
}

template<class Item,class Item2>
bool DoubleLinkQueue<Item,Item2>::isEmpty(){
	if(head == NULL){
		return true;
	}
	else
		return false;
}


template<class Item,class Item2>
int DoubleLinkQueue<Item,Item2>::maxSize(){
	return MaxSize;
}

template<class Item,class Item2>
int DoubleLinkQueue<Item,Item2>::length(){
	return len;
}

// template<class Item,class Item2>
// Item DoubleLinkQueue<Item,Item2>::returnKeyAtIndex(const int k){
// 	tode<Item,Item2> *temp;
// 	if(k>len){
// 		cout << "Index is greater than maximum size" << endl;
// 		return -1;
// 	}
// 	if(k<=0){
// 		cout << "Invalid request: k must be positive" << endl;
// 		return -1;
// 	}
// 	temp = head;
// 	for(int i=0;i<k-1;i++){
// 		temp = temp->next;
// 	}
// 	Item k = temp->data;
// 	temp = NULL;
// 	return data;
// }

template<class Item,class Item2>
void DoubleLinkQueue<Item,Item2>::deleteNodeAtIndex(const int k){
	tode<Item,Item2> *temp,*current;
	if(k>=len){
		cout << "Element to delete has index greater than length of list" ;
	}
	//if you wanna remove first element use dequeue() instead, this function will not work for that
	if(k == 0 ){
		dequeue();
		return ;
	}
	if(k == len-1){
		temp = tail;
		tail = tail->prev;
		temp->prev = NULL;
		delete temp;
		temp = NULL;
		len--;
		return ;
	}

	temp = head;
	for(int i=0;i<k-1;i++){
		temp=temp->next;
	}
	current = temp->next;
	temp->next = current->next;
	current->next->prev = temp;
	current->prev = NULL;
	current->next = NULL;
	delete current;      //freeing memory associated with pointer
	temp = NULL;
	current = NULL;
	len--;
}

template<class Item,class Item2>
bool DoubleLinkQueue<Item,Item2>::deleteNodeForKey(const Item& x){
	tode<Item,Item2> *temp;
	temp = head;
	int todeNo=1;

	for(int i=0;i<len;i++){
		if(temp->data == x){
			deleteNodeAtIndex(todeNo);
			temp = NULL;
			return true;
		}else{
			temp= temp->next;
			todeNo++;
		}
	}
	temp = NULL;
	return false;
}


template<class Item,class Item2>
void DoubleLinkQueue<Item,Item2>::replace(const int  k,const Item& x){
	tode<Item,Item2> *temp;
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
	temp = NULL;
}

template<class Item,class Item2>
void DoubleLinkQueue<Item,Item2>::printList( void ){
	struct tode<Item,Item2> *temp;
	temp = head;
	if(head == NULL || len==0){
		cout << "The list is empty" << endl;
		return;
	}
	cout << "Printing the list -- " << endl;
	cout << "("<< temp->data;
	// cout << " ," << temp->metaData << ")" << endl;
	for(int i=0;i<len-1;i++){
		temp = temp->next;
		cout << "("<< temp->data << ")" << endl;
		// cout << " ," << temp->metaData << ")" << endl;
	}
}

// template<class Item>
// void DoubleLinkQueue<Item>::moveBack(const int currentIndex){
// 	struct tode<Item> *prev = head;
// 	for(i=0;i<currentIndex-2;i++){
// 		prev = prev->next;
// 	}
// 	current = prev;
// }


template<class Item,class Item2>
void DoubleLinkQueue<Item,Item2>::enqueue(const Item& x){
	if(len==MaxSize){
		MaxSize+=1;
	}
	if(head==NULL){
		MaxSize+=1;
		head = createNode(x);
		// head->metaData = y;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		len++;
		cout << "New appended len is - " << len << endl;
		return;
	}
	else{
		struct tode<Item,Item2> *temp;
		temp = createNode(-3);
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
		tail->data = x;
		// tail->metaData = y;
		tail->next = NULL;
		temp = NULL;
	}

	len++;
	cout << "New appended len is - " << len << endl;
}

template<class Item,class Item2>
void DoubleLinkQueue<Item,Item2>::dequeue(){
	if(head==NULL){
		cout << "DoubleLinkList dequeue: list is empty, can't delete" << endl;
		return;
	}
	else{
		struct tode<Item,Item2> *temp;
		temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}

	len--;
	cout << "New dequeued len is - " << len << endl;
}



// template<class Item,class Item2>
// Item2 DoubleLinkQueue<Item,Item2>::returnValueForKey(const Item& x){
// 	tode<Item,Item2> *temp;
// 	temp = head;
// 	for(int i=0;i<len;i++){
// 		if(temp->data == x){
// 			Item2 mtData = temp->metaData;
// 			return mtData;
// 		}else{
// 			temp=temp->next;
// 		}
// 	}
// 	temp = NULL;
// 	return -1;
// }

template<class Item,class Item2>
bool DoubleLinkQueue<Item,Item2>::find(const Item& x){
	tode<Item,Item2> *temp;
	temp = head;
	for(int i=0;i<len;i++){
		if(temp->data == x){
			temp = NULL;
			return true;
		}else{
			temp=temp->next;
		}
	}
	temp = NULL;
	return false;
}



template<class Item,class Item2>
int DoubleLinkQueue<Item,Item2>::getIndexForKey(const Item& x){
	tode<Item,Item2> *temp;
	temp = head;
	for(int i=0;i<len;i++){
		if(temp->data == x){
			// int mtData = temp->metaData;
			temp = NULL;
			return i;
		}else{
			temp=temp->next;
		}
	}
	temp = NULL;
	return -1;
}

template<class Item,class Item2>
bool DoubleLinkQueue<Item,Item2>::shiftKeyAtTail(const Item& x){
	tode<Item,Item2> *temp;
	temp = head;
	for(int i=0;i<len;i++){
		if(temp->data == x){
			// Item2& mtData = temp->metaData;
			deleteNodeAtIndex(i);
			enqueue(x);
			return true;
		}else{
			temp=temp->next;
		}
	}
	temp = NULL;
	return false;

}


#endif
