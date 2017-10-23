#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"

using namespace std;
/*
 * 	Class AdjacencyMatrix
 *	Can be used to represent a Graph using adjacency-matrix.
 */
class AdjacencyMatrix : public GraphAdjacencyBase {
	
	int size;
	int** arr;

	public:
		AdjacencyMatrix(const int vertices);
		~AdjacencyMatrix();

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

  void printFuck();
};
#include "AdjacencyMatrix.cpp"
#endif /* ifndef ADJACENCY_MATRIX */
