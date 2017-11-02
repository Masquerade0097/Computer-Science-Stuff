#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"

/*
* A class to represent a directed graph.
*/
struct nd{
	int visited;
	int parent;
};

class DirectedGraph : AbstractGraph {
	
	GraphAdjacencyBase *base;
	struct nd* vert;

	public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, char rep);
	/*
	 * Destructor
	 */
	~DirectedGraph();

   /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExists(int i, int j);
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges();
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  virtual int vertices();
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
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  virtual void dfs(void (*work)(int&));
  
   // * Function bfs:
   // * Does a breadth first traversal of the entire graph.
   // * Runs the given function work, with the value of each vertex.
   
  virtual void bfs(void (*work)(int&));

  void dfsR(int vertex);

  void dfstrees();
		
};
#include "DirectedGraph.cpp"
#endif /* ifndef DIRECTED_GRAPH */
