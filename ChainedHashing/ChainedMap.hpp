/*
 * ChainedMap.hpp
 *
 */
#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
#include "Dictionary.hpp"
#include "seqLinearList.hpp"

using namespace std;

namespace cs202
{
template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{

private:/*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
    int hashFunction(const Key& key);
    bool full;
    int m ;
    LinearList<Key,Value> carray[7];
    
public:
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap();
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num);
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap(){}
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);

    //dictionary functions

    virtual void put(const Key& key, const Value& value) ;

    virtual Value get(const Key& key) ;

    virtual void remove(const Key& key) ;

    virtual bool has(const Key& key) ;

};
}
#include "ChainedMap.cpp"
#endif /* CHAINEDMAP_HPP_ */