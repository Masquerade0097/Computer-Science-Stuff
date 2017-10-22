#include "Dictionary.hpp"
#include "ArrayList.hpp"
#include "DoubleHashMap.hpp"

#include <iostream>


namespace cs202{

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap(){
	m = 17;
	carray = ArrayList<Key,Value>(17);
	maxIteration = 0;

}

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap(const int& num){
	m = num;
	carray = ArrayList<Key,Value>(m);
	maxIteration = 0;
}

// template<class Key, class Value>
// DoubleHashMap<Key,Value>::~DoubleHashMap(){
// 	m = 0;
// }

template<class Key, class Value>
int DoubleHashMap<Key,Value>::hashFunction1(const Key& x){
	return x%m;
}

template<class Key, class Value>
int DoubleHashMap<Key,Value>::hashFunction2(const Key& x){
	return x%prevPrime(m) + 1;
}

template<class Key, class Value>
int DoubleHashMap<Key,Value>::getSize(){
	return m;
}


template<class Key, class Value>
void DoubleHashMap<Key,Value>::rehash(){
	
	darray = ArrayList<Key,Value>(nextPrime(m));
	for(int i=0;i<m;i++){
		node<Key,Value> rec = carray.getNode(i);
		darray.copyValues(i,rec.data,rec.metaData,rec.flag);
	}
	carray = ArrayList<Key,Value>(darray);
	return ;
}

template<class Key, class Value>
bool DoubleHashMap<Key,Value>::isPrime(int number){
    
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
int DoubleHashMap<Key,Value>::nextPrime(int a){
    while (!isPrime(++a)){}
    return a;
}

template<class Key, class Value>
int DoubleHashMap<Key,Value>::prevPrime(int a){
    while (!isPrime(--a)){}
    return a;
}

template<class Key, class Value>
void DoubleHashMap<Key,Value>::printAll(){
   carray.printFuck();
}

template<class Key, class Value>
DoubleHashMap<Key,Value>::DoubleHashMap(DoubleHashMap<Key, Value>& ht){

	darray = new ArrayList<Key,Value>(ht.getSize());
	for(int i=0;i<ht.getSize();i++){
		node<Key,Value> *rec = ht.getNode(i);
		darray.copyValues(i,rec->data,rec->metaData,rec->flag);
		rec = NULL;
	}
}

template<class Key, class Value>
void DoubleHashMap<Key,Value>::put(const Key& key, const Value& value){

	int index = hashFunction1(key);
	int count = 0;
	cout << "Index is " << index << endl;
	int result = carray.insert(index,key,value);
	cout << "Result is " << result << endl;

	if(result == 1){
		return ;
	}

	int addIndex = hashFunction2(key);
	index = (index + addIndex)% carray.maxSize();
	result = carray.insert(index,key,value);
	cout << "Second Result is " << result << endl;

	if(result == 1){
		return ;
	}
	while(result!=0){
		count++;
		if(count > maxIteration){
			maxIteration = count;
		}
		index = (index + addIndex)% carray.maxSize();		
		result = carray.insert(index,key,value);
		cout << "While loop : Result is " << result << endl;
	}
	if(result == 1){
		return ;
	}
	if(result==-1){
		cout << "Inside DoubleHashMap: Cannot insert key : array is full" << endl;
		rehash();
		put(key,value);
		return;
	}
}

template<class Key, class Value>
Value DoubleHashMap<Key,Value>::get(const Key& key){
	int index = hashFunction1(key);
	int count =0;
	Value result = carray.getValue(index,key);

	if(result != -1){
		return result;
	}
	
	int addIndex = hashFunction2(key);
	index = (index + addIndex)% carray.maxSize();
	result = carray.getValue(index,key);
	cout << "Second Result is " << result << endl;
	if(result != -1){
		return result;
	}

	while(result == -1){
		if(count > maxIteration){
			break;
		}
		index = (index + addIndex)% carray.maxSize();		
		result = carray.getValue(index,key);
		cout << "While loop : Result is " << result << endl;
		count++;
	}
	if(result == 1){
		return result;
	}
	if(result == -1){
		cout << "DoubleHashMap get fn: This key not found" << endl;		
		return -1;
	}
}

template<class Key, class Value>
void DoubleHashMap<Key,Value>::remove(const Key& key){
	int index = hashFunction1(key);
	int count = 0;
	Value result = carray.getValue(index,key);

	if(result != -1){
		int status = carray.deleteNode(index);
		if(status != 1){
			cout << "DoubleHashMap remove fn: Unable to delete Node" << endl;
		}
	}
	
	int addIndex = hashFunction2(key);
	index = (index + addIndex)% carray.maxSize();
	result = carray.getValue(index,key);
	cout << "Second Result is " << result << endl;
	if(result != -1){
		int status = carray.deleteNode(index);
		if(status != 1){
			cout << "DoubleHashMap remove fn: Unable to delete Node" << endl;
		}
	}

	while(result == -1){
		if(count > maxIteration){
			break;
		}
		index = (index + addIndex)% carray.maxSize();		
		result = carray.getValue(index,key);
		cout << "While loop : Result is " << result << endl;
		count++;
	}
	if(result == 1){
		int status = carray.deleteNode(index);
		if(status != 1){
			cout << "DoubleHashMap remove fn: Unable to delete Node" << endl;
		}
	}
	if(result == -1){
		cout << "DoubleHashMap get fn: This key not found: Cannot delete therefore 7" << endl;		
		return ;
	}
	

}


// if(result != -1){
// 		int status = carray.deleteNode(result);
// 		if(status != 1){
// 			cout << "DoubleHashMap remove fn: Unable to delete Node" << endl;
// 		}
// }
// }else{
// 		cout << "DoubleHashMap remove fn: No key found to delete" << endl;
// 	}


template<class Key, class Value>
bool DoubleHashMap<Key,Value>::has(const Key& key){
	int index = hashFunction1(key);
	int count =0;
	Value result = carray.getValue(index,key);

	if(result != -1){
		return true;
	}
	
	int addIndex = hashFunction2(key);
	index = (index + addIndex)% carray.maxSize();
	result = carray.getValue(index,key);
	cout << "Second Result is " << result << endl;
	if(result != -1){
		return true;
	}

	while(result == -1){
		if(count > maxIteration){
			break;
		}
		index = (index + addIndex)% carray.maxSize();		
		result = carray.getValue(index,key);
		cout << "While loop : Result is " << result << endl;
		count++;
	}
	if(result == 1){
		return true;
	}
	if(result == -1){
		cout << "DoubleHashMap get fn: This key not found" << endl;		
		return false;
	}

}


};