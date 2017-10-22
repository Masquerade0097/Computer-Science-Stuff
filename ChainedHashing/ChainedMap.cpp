#include "Dictionary.hpp"
#include "ChainedMap.hpp"
#include "seqLinearList.hpp"
#include <iostream>

// template<class Key, class Value>
// class Dictionary;
namespace cs202{

template<class Key, class Value>
int ChainedMap<Key,Value>::hashFunction(const Key& key){
	return key%7;
}

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(){
	m = 7; 
	full = false;
}

// template<class Key, class Value>
// ChainedMap<Key,Value>::~ChainedMap(){
// 	m = 0; 
// 	full = false;
// 	// delete [] carray;
// }

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(const int& num){
	m = num;
	// rehash();
}

// template<class Key, class Value>
// void ChainedMap<Key,Value>::rehash(){

// }

// template<class Key, class Value>
// Value& ChainedMap<Key,Value>::operator[](const Key& key){

// }


template<class Key, class Value>
void ChainedMap<Key,Value>::put(const Key& key, const Value& value){
	int index = hashFunction(key);
	carray[index].appendFront(key,value);
}

template<class Key, class Value>
Value ChainedMap<Key,Value>::get(const Key& key){
	int index = hashFunction(key);
	Value returnValue;

	returnValue = carray[index].search(key);  //see the return type is int for false case
	if(returnValue == -1){
		cout << "ChainedMap: No such key present to get";
	}  
	return returnValue;
}

template<class Key, class Value>
bool ChainedMap<Key,Value>::has(const Key& key){
	int index = hashFunction(key);
	Value returnValue;

	return carray[index].find(key);
}


template<class Key, class Value>
void ChainedMap<Key,Value>::remove(const Key& key){
	int index = hashFunction(key);
	bool result;
	result = carray[index].deleteKey(key);

	if(result == false){
		cout << "key not found !! so not removed" << endl;
	}
}

};

