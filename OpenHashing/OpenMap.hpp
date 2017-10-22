/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear Probing
 */

#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_
#include "Dictionary.hpp"
#include "ArrayList.hpp"

using namespace std;

namespace cs202
{
template<class Key, class Value>
class OpenMap  : public Dictionary<Key,Value>
{
private:
    /*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
    bool full;
    int m ;
    ArrayList<Key,Value> carray,darray;
    int hashFunction(const Key& x);
    int getSize();
    bool isPrime(int number);
    int nextPrime(int a);


public:
    /*
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	OpenMap();
    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	OpenMap(const int& num);
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	OpenMap(OpenMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~OpenMap(){};
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	// Value& operator[](const Key& key);

    virtual void put(const Key& key, const Value& value) ;

    virtual Value get(const Key& key) ;

    virtual void remove(const Key& key) ;

    virtual bool has(const Key& key) ;
    void printAll();
};
}

#include "OpenMap.cpp"
#endif 