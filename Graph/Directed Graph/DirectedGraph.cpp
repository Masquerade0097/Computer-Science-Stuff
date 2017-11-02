#include <iostream>
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"
#include "AbstractGraph.hpp"
#include "DirectedGraph.hpp"

using namespace std;

DirectedGraph::DirectedGraph(int numVertices, char rep){
	vert = new struct nd[numVertices];

	if(rep == 'm'){
		base = new AdjacencyMatrix(numVertices);

	}
	else if(rep == 'l'){
		base = new AdjacencyList(numVertices);
	}else{
		cout << "Input valid character" << endl;
	}
}

DirectedGraph::~DirectedGraph(){
	base = NULL;
	delete vert;
	vert = NULL;
}

bool DirectedGraph::edgeExists(int i, int j){
	if(base->edgeExists(i,j))
		return true;
	else
		return false;
}

int DirectedGraph::edges(){
	return base->edges();
}

int DirectedGraph::vertices(){
	return base->vertices();
}

void DirectedGraph::add(int i, int j){
	// cout << "Directed add func " << endl;
	base->add(i,j);
}

void DirectedGraph::remove(int i, int j){
	base->remove(i,j);
}


void DirectedGraph::dfs(void (*work)(int&)){
	for(int i=0;i<base->vertices();i++){
		vert[i].visited = 0;
		vert[i].parent = -1;
	}

	int num = 0;
	for(int i=0;i<base->vertices();i++){
		if(vert[i].visited!=1){
			// num++;
			// cout << endl << i+1;
			cout << endl;
			int k = i+1;
			(*work)(k);
			dfsT(i);
		}
	}
	// cout << "No of shapes are - " << num << endl;
}

void DirectedGraph::dfstrees(){
	for(int i=0;i<base->vertices();i++){
		vert[i].visited = 0;
		vert[i].parent = -1;
	}

	int num = 0;
	for(int i=0;i<base->vertices();i++){
		if(vert[i].visited!=1){
			num++;
			cout << endl << i+1;
			dfsT(i);
		}
	}
	cout << endl << "No of shapes are - " << num << endl;
}

void DirectedGraph::dfsR(int vertex){
	vert[vertex].visited = 1;
	for(int j=0;j<base->vertices();j++){
		if(edgeExists(vertex,j) && vert[j].visited==0){
			cout << "->" << j+1 ;
			// cout << "->" ;
			// int k = j+1;
			// (*work)(k);
			dfsT(j);
		}
	}
} 

void DirectedGraph::bfs(void (*work)(int&)){
	for(int i=0;i<base->vertices();i++){
		vert[i].visited = 0;
		vert[i].parent = -1;
	}
	LinearList<int>* queue;
	queue = new LinearList<int>(base->vertices());

	for(int l=0;l<base->vertices();l++){
		if(vert[l].visited!=0)
			continue;

		queue->append(l);
		vert[l].visited = 2;

		while(queue->length()){
			int vertex = queue->pop();
			// queue->printList();
			// cout << endl;
			// cout << vertex << endl;
			(*work)(vertex);
			cout << endl;

			for(int j=0;j<base->vertices();j++){
				if(edgeExists(vertex,j) && vert[j].visited==0){
					// cout << "->" << j ;
					vert[j].visited = 2;
					queue->append(j);
					// queue->printList();
					// cout << endl;
				}
			}
			vert[vertex].visited = 1;
		}
	}
}
