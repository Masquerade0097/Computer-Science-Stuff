#include <iostream>
#include "AdjacencyList.hpp"
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"

using namespace std;

AdjacencyList::AdjacencyList(const int vertices){
	size = vertices;
	//new added
	arr = new LinearList<int>*[vertices];
	for(int i=0;i<vertices;i++){
		arr[i] = new LinearList<int>();
		//arr[i] is not the linearlist object, instead it is a pointer to linear list object
	}
}

AdjacencyList::~AdjacencyList(){
	for(int i=0;i<size;i++){
		delete arr[i];
	}

	delete arr;
}

int AdjacencyList::vertices(){
	return size;
}

void AdjacencyList::add(int i, int j){
	arr[i]->appendFront(j);
}

int AdjacencyList::degree(int i){
	int outdegree = arr[i]->length();
	cout << "Outdegree of " << i << " - " << outdegree << endl;
	int indegree =0;
	for(int k=0;k<size;k++){
		if(k==i) continue;
		if(edgeExists(k,i)){
			indegree++;
		}
	}
	return indegree+outdegree;
}

bool AdjacencyList::edgeExists(int i, int j){
	if(arr[i]->find(j))
		return true;
	else
		return false;
}

int AdjacencyList::edges(){
	int edge=0;
	for(int i=0;i<size;i++){
		edge+=arr[i]->length();
	}
	return edge;
}

void AdjacencyList::remove(int i, int j){
	arr[i]->deleteKey(j);
}