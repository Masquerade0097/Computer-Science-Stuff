#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"

using namespace std;
/*
 * 	Class AdjacencyList
 *	Can be used to represent a Graph using adjacency-list.
 */
class AdjacencyList : public GraphAdjacencyBase {

	int size;
	LinearList<int>** arr;

	public:
	 AdjacencyList(const int vertices);
	 ~AdjacencyList();

	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  virtual bool edgeExists(int i, int j);
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  virtual int vertices();
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  virtual int edges();
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  virtual void add(int i, int j);
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  virtual void remove(int i, int j);
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  virtual int degree(int i);
		  	
};  	
#include "AdjacencyList.cpp"
#endif /* ifndef ADJACENCY_LIST */
