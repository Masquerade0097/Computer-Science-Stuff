
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#define FILLED 1
#define EMPTY 0
#define DELETED -1

#include <iostream>
// #include <stdlib.h>
#include <cstring>


using namespace std;

template<class Item,class Item2>
struct node{
	Item data;
	Item2 metaData;
	int flag;
};

template<class Item,class Item2>
class ArrayList{

	private:
		int MaxSize;
		int len;
		struct node<Item,Item2>* head;    // 1D dynamic array

	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		ArrayList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		ArrayList(const int& MaxListSize);

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~ArrayList(){};

		ArrayList(ArrayList<Item,Item2> &al);

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
		// Item  returnListElement(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		int findIndexLinearSearch(const int k, const Item& x);
		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		Item2& linearSearch(int startIndex,const Item& x);

		Item2 getValue(int startIndex,const Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		// void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		int insert(const int k, const Item& x, const Item2& y);

		/* Replace the kth element with the new element 
		* */
		// void replace(const int  k, const Item& x);

		/* Prints the current list
		* */
		// void printList(void);

		int deleteNode(const int k);

		node<Item,Item2> getNode(const int k);

		void copyValues(const int k,const Item& x, const Item2& y, int fl);

		void printFuck();
		
};


template<class Item,class Item2>
ArrayList<Item,Item2>::ArrayList(){
	MaxSize = 0;
	head = NULL;
	len = 0;
}

template<class Item,class Item2>
ArrayList<Item,Item2>::ArrayList(const int& MaxListSize){
	MaxSize = MaxListSize;
	len = 0;
	head = new struct node<Item,Item2>[MaxSize];
	memset(head,0,MaxSize);
}

// template<class Item,class Item2>
// ArrayList<Item,Item2>::~ArrayList(){
// 	delete [] head;
// 	MaxSize =0;
// 	len = 0;
// }

template<class Item,class Item2>
int ArrayList<Item,Item2>::insert(const int k,const Item& x, const Item2& y){
	
	int i;
	if(k > MaxSize){
		cout << "K is " << k << "Maxsize is " << MaxSize<< endl;
		cout << "ArrayList: Max Size exceeded, inside insert function " << endl;
		return -1;
	}
	if((head+k)->flag == EMPTY || (head+k)->flag==DELETED){
		(head + k)->data = x;
		(head + k)->metaData = y;
		(head+k)->flag = FILLED;
		len++;
		return 1;
	}
	if((head+k)->flag == FILLED){
		return 0;
	}
	
}

template<class Item,class Item2>
void ArrayList<Item,Item2>::copyValues(const int k,const Item& x, const Item2& y, int fl){
	
	if(k > MaxSize){
		cout << "ArrayList: Max Size exceeded, inside insert function " << endl;
		return ;
	}
		(head + k)->data = x;
		(head + k)->metaData = y;
		(head+k)->flag = fl;
}

template<class Item,class Item2>
int ArrayList<Item,Item2>::length(){
	return len;
}

template<class Item,class Item2>
int ArrayList<Item,Item2>::maxSize(){
	return MaxSize;
}


template<class Item,class Item2>
bool ArrayList<Item,Item2>::isEmpty(){
	return true?len==0:false;
}

template<class Item,class Item2>
Item2& ArrayList<Item,Item2>::linearSearch(int startIndex,const Item& x){

	for(int i=startIndex;i<MaxSize;i++){
		if((head+i)->data == x){
			return (head+i)->metaData;
		}
	}
	for(int i=0;i<startIndex;i++){
		if((head+i)->data == x){
			return (head+i)->metaData;
		}
	}
	cout << "Arraylist search fn: Key not found " << endl;
	return -1;

}


template<class Item,class Item2>
Item2 ArrayList<Item,Item2>::getValue(int startIndex,const Item& x){
	if((head + startIndex)->data == x){
		return (head + startIndex)->metaData;
	}else{
		return -1;
	}
}

template<class Item,class Item2>
int ArrayList<Item,Item2>::findIndexLinearSearch(const int k, const Item& x){
	for(int i=k;i<MaxSize;i++){
		if((head+i)->data == x){
			return i;
		}
	}
	for(int i=0;i<k;i++){
		if((head+i)->data == x){
			return i;
		}
	}
	cout << "Arraylist find fn: Key not found " << endl;
	return -1;
}


template<class Item,class Item2>
int ArrayList<Item,Item2>::deleteNode(const int k){
	if(k>MaxSize){
		cout << "ArrayList delete fn: index entered is greater than maxsize" << endl;
		return -1;
	}
	// Item x;
	(head+k)->data = 0;
	(head+k)->metaData = 0;
	(head+k)->flag = DELETED;
	len--;
	return 1;
}

template<class Item,class Item2>
node<Item,Item2> ArrayList<Item,Item2>::getNode(const int k){
	node<Item,Item2>* pointer = head;
	return *(pointer + k);
}



template<class Item,class Item2>
ArrayList<Item,Item2>::ArrayList(ArrayList<Item,Item2> &al){
	
	for(int i=0;i<al.length();i++){
		node<Item,Item2> t = al.getNode(i);
		(head + i)->data = t.data;
		(head + i)->metaData = t.metaData;
		(head + i)->flag = t.flag;
	}
}

template<class Item,class Item2>
void ArrayList<Item,Item2>::printFuck(){
	cout << "len is " << len << "  Maxsize is " << MaxSize << endl;
	for(int i=0;i<MaxSize;i++){
		cout << "( " << (head+i)->data << "," << (head+i)->metaData << "," << (head+i)->flag << ")" << endl;
	}
}

// template<class Item,class Item2>
// Item& ArrayList<Item,Item2>::operator[](const int &i){
// 	if(i>len){
// 		cout << "the index os out of bound";
// 		return NULL;
// 	}
// 	return (head + i);
// }

#endif