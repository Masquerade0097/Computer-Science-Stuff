#include <iostream>
#include "AdjacencyMatrix.hpp"
#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(const int vertices){
	size = vertices;
	arr = new int*[vertices];
	for(int i=0;i<vertices;i++){
		arr[i] = new int[vertices];
	}
	for(int i=0;i<size;i++){
		for(int k=0;k<size;k++){
			arr[i][k] = 0;
		}
	}
	for(int i=0;i<size;i++){
		for(int k=0;k<size;k++){
			cout << " " <<arr[i][k] << " ";
		}
		cout << endl;
	}
}

AdjacencyMatrix::~AdjacencyMatrix(){
	for(int i=0;i<size;i++){
		delete arr[i];
	}
	delete arr;
}


int AdjacencyMatrix::vertices(){
	return size;
}

void AdjacencyMatrix::add(int i, int j){
	arr[i][j] = 1;
}

int AdjacencyMatrix::degree(int i){
	int outdegree=0,indegree=0;

	for(int k=0;k<size;k++){
		if(arr[i][k]==1)
			outdegree++;
	}
	for(int k=0;k<size;k++){
		if(arr[k][i]==1)
			indegree++;
	}
	return indegree+outdegree;
}

bool AdjacencyMatrix::edgeExists(int i, int j){
	if(arr[i][j]==1)
		return true;
	else
		return false;
}

int AdjacencyMatrix::edges(){
	int edges = 0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(arr[i][j]==1){
				edges++;
			}
		}
	}
	return edges;
}

void AdjacencyMatrix::remove(int i, int j){
	arr[i][j] = 0;
}

void AdjacencyMatrix::printFuck(){
	cout << endl << endl ;
	for(int i=0;i<size;i++){
		for(int k=0;k<size;k++){
			cout << " " <<arr[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

}