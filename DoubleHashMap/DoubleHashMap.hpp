/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */

#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_
#include "Dictionary.hpp"
#include "ArrayList.hpp"

using namespace std;

namespace cs202{

template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>{

private:
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
    bool full;
    int m ;
    int maxIteration;
    ArrayList<Key,Value> carray,darray;
    int hashFunction1(const Key& x);
    int hashFunction2(const Key& x);
    int getSize();
    bool isPrime(int number);
    int prevPrime(int a);
    int nextPrime(int a);


public:
    /*
     * Constructor: DoubleHashMap
     * Creates a Double Hash Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap();
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num);
    /*
     * Constructor: Double Hash Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~DoubleHashMap(){};
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);

    virtual void put(const Key& key, const Value& value) ;

    virtual Value get(const Key& key) ;

    virtual void remove(const Key& key) ;

    virtual bool has(const Key& key) ;
    void printAll();
};
}
#include "DoubleHashMap.cpp"
#endif 