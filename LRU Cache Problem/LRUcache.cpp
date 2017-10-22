
#include "Dictionary.hpp"
#include "ChainedMap.hpp"
#include "seqLinearList.hpp"
#include "DoubleLinkQueue.hpp"
#include <iostream>
using namespace std;
using namespace cs202;

int main(){

	DoubleLinkQueue<int,int> dq;
	Dictionary<int,int> *dict;
	ChainedMap<int,int> cmap;
	dict = &cmap;

	int capacity = 4,input,key,value,T=1,length;
	bool result;

	while(T){

		cout << "Enter the input " << endl;
		cout << "Set(x,y)    ----  Press 1" << endl;
		cout << "Get(x,y)    ----  Press 2" << endl;
		cout << "Exit        ----  Press 3" << endl;


		cin >> input;

		switch(input){
			case 1:
				length = dq.length();
				cin >> key ;
				cin >> value;
				if(length == capacity){
					dq.dequeue();
					dq.enqueue(key);
					cmap.put(key,value);
				}
				if(length < capacity){
					dq.enqueue(key);
					cmap.put(key,value);
				}
				break;

			case 2:
				length = dq.length();
				cin >> key ;
				result = dq.shiftKeyAtTail(key);
				if(result == true){
					cout << cmap.get(key) << endl;
				}else{
					cout << "-1" << endl;
				}
				break;

			case 3:
				T = 0;
				break;
		}

	}

	return 0;
}






























  //  dq.printList();
  //  dq.enqueue(1,100);
  //  dq.enqueue(2,101);
  //  dq.enqueue(5,106);
  //  dq.enqueue(22,107);
  //  dq.enqueue(36,108);
  //  dq.enqueue(7,109);
  //  dq.printList();
  //  for(int i=0;i<3;i++){
		// dq.deleteNodeAtIndex(3);
  //  		dq.printList();
  //  }
  //  dq.deleteNodeAtIndex(2);
  //  dq.printList();
  //  dq.deleteNodeAtIndex(1);
  //  dq.printList();
  //  dq.dequeue();
  //  dq.printList();
   








// Dictionary<int,int> *dict;
//     DoubleHashMap<int,int> dmap;
//     dict = &dmap;

//     // cout << dmap.getSize() << endl;
//     dmap.printAll();

//    	dmap.put(5,100);
// 	dmap.put(2,100);
// 	dmap.put(3,100);
// 	dmap.put(4,100);
// 	dmap.put(25,101);
// 	dmap.put(6,102);
// 	dmap.put(27,103);
// 	dmap.put(8,104);
// 	dmap.put(13,105);
// 	dmap.put(14,106);

// 	dmap.printAll();

// 	for(int i=1;i<17;i++){
// 		int gotIt = dmap.get(i);
// 		if(gotIt == -1){
// 			continue;
// 		}
// 		cout << "(" << i <<", " << gotIt << ")" << endl;
// 	}

// 	cout << "(" << 13 <<", " << dmap.get(13) << ")" << endl;
// 	cout << "(" << 14 <<", " << dmap.get(14) << ")" << endl;

// 	cout<< dmap.has(7) << endl;
// 	cout<< dmap.has(27) << endl << endl  << endl << endl;

// 	dmap.remove(6);
// 	cout << "(" << 6 <<", " << dmap.get(6) << ")" << endl << endl << endl ;
// 	dmap.remove(27);
// 	cout << "(" << 27 <<", " << dmap.get(27) << ")" << endl;

// 	dmap.printAll();