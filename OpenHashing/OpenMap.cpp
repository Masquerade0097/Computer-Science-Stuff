#include "Dictionary.hpp"
#include "ArrayList.hpp"
#include "OpenMap.hpp"

#include <iostream>


namespace cs202{
	
template<class Key, class Value>
OpenMap<Key,Value>::OpenMap(){
	m = 17;
	carray = ArrayList<Key,Value>(17);

}

template<class Key, class Value>
OpenMap<Key,Value>::OpenMap(const int& num){
	m = num;
	carray = ArrayList<Key,Value>(m);
}

// template<class Key, class Value>
// OpenMap<Key,Value>::~OpenMap(){
// 	m = 0;
// }

template<class Key, class Value>
int OpenMap<Key,Value>::hashFunction(const Key& x){
	return x%m;
}

template<class Key, class Value>
int OpenMap<Key,Value>::getSize(){
	return m;
}


template<class Key, class Value>
void OpenMap<Key,Value>::rehash(){
	
	darray = ArrayList<Key,Value>(nextPrime(m));
	for(int i=0;i<m;i++){
		node<Key,Value> rec = carray.getNode(i);
		darray.copyValues(i,rec.data,rec.metaData,rec.flag);
	}
	carray = ArrayList<Key,Value>(darray);
	return ;
}

template<class Key, class Value>
bool OpenMap<Key,Value>::isPrime(int number){
    
    if(number == 2 || number == 3)
        return true;
    if(number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while(divisor * divisor - 2 * divisor + 1 <= number){

        if (number % (divisor - 1) == 0)
            return false;
        if (number % (divisor + 1) == 0)
            return false;
        divisor += 6;
    }
    return true;
}

template<class Key, class Value>
int OpenMap<Key,Value>::nextPrime(int a){
    while (!isPrime(++a)){}
    return a;
}

template<class Key, class Value>
void OpenMap<Key,Value>::printAll(){
   carray.printFuck();
}

template<class Key, class Value>
OpenMap<Key,Value>::OpenMap(OpenMap<Key, Value>& ht){

	darray = new ArrayList<Key,Value>(ht.getSize());
	for(int i=0;i<ht.getSize();i++){
		node<Key,Value> *rec = ht.getNode(i);
		darray.copyValues(i,rec->data,rec->metaData,rec->flag);
		rec = NULL;
	}
}

template<class Key, class Value>
void OpenMap<Key,Value>::put(const Key& key, const Value& value){
	int index = hashFunction(key);
	cout << "Index is " << index << endl;
	int result = carray.insert(index,key,value);
	cout << "Result is " << result << endl;

	if(result == 1){
		return ;
	}
	while(result!=0){
		index = index +1;
		result = carray.insert(index,key,value);
		if(index>17){
			cout << "Index is greater than 17" << endl;
			break;
		}
		// break;
	}

	if(result==-1){
		cout << "Inside OpenMap: Cannot insert key : array is full" << endl;
		rehash();
		put(key,value);
		return;
	}
}

template<class Key, class Value>
Value OpenMap<Key,Value>::get(const Key& key){
	int index = hashFunction(key);
	Value result = carray.linearSearch(index,key);
	if( result != -1){
		return result;
	}else{
		cout << "OpenMap get fn: No key found" << endl;
		return -1;
	}
}

template<class Key, class Value>
void OpenMap<Key,Value>::remove(const Key& key){
	int index = hashFunction(key);
	int result = carray.findIndexLinearSearch(index,key);
	if(result != -1){
		int status = carray.deleteNode(result);
		if(status != 1){
			cout << "OpenMap remove fn: Unable to delete Node" << endl;
		}
	}else{
		cout << "OpenMap remove fn: No key found to delete" << endl;
	}

}

template<class Key, class Value>
bool OpenMap<Key,Value>::has(const Key& key){
	int index = hashFunction(key);
	int result = carray.findIndexLinearSearch(index,key);
	if(result != -1){
		return true;
	}else{
		return false;
	}

}



};