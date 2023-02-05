#include <iostream>
#include <cstdlib>

#include "a4_list.h"

using namespace std;

A_list::A_list(int initialSize = 16) {  //both sides must be the same name
   list_itself = new int[initialSize];
   for (int i = 0; i < initialSize; i++) {
        list_itself[i] = 0;
    }
   endOfList = initialSize;
}

bool A_list::add(int position, int value){
    if (position < 0){
        position = 0;
    }else if (position >= endOfList){
        position = endOfList;
    }

    for (int i = endOfList-1; i >= position; --i){
        list_itself[i] = list_itself[i-1];
        //cout<< i<<endl;
    }

    list_itself[position-1] = value;

    //cout<<"end of list"<<list_itself[endOfList]<<endl;
    
    endOfList++;    //Find out why if list[0] != 0 statement doesnt work*************************
    list_itself[endOfList] = 0;
    return true;
}

int A_list::remove(int position){
    int value_removed = list_itself[position];

    for(int i = position; i < endOfList; ++i) {
        list_itself[i-1] = list_itself[i];
    }

    endOfList--;

    return value_removed;
}

//from Joseph Jess
int A_list::peek(int position) {
    if (position < 0 || position >= endOfList) {
        return INT_MIN;
    }

    return list_itself[position-1];
}



main(){

A_list my_list(16);

//cout<<my_list.endOfList<<endl;

// for(int i=0; i > my_list.endOfList; i++){   //WHY DOESNT THIS WORK*******************
//     my_list.add(i,i);
//     cout<<i<<endl;
// }

//Adding and removing some numbers to test out functions.
my_list.add(1, 1);
my_list.add(2, 2);
my_list.add(3, 3);
my_list.add(4, 4);
my_list.add(5, 5);
my_list.add(6, 6);

cout <<"Initial List"<<endl;
for(int i = 0; i< my_list.endOfList; i++){
    cout << my_list.list_itself[i] <<"  ";
}

my_list.add(2, 88);
my_list.add(16, 77);
my_list.add(16, 70);

//Print out the list after functions have worked their magic.
cout <<endl<<"List after adding a value to 2nd position"<<endl;
for(int i = 0; i< my_list.endOfList; i++){
    cout << my_list.list_itself[i] <<"  ";
}

//Print out list after remove has run to make sure it works correctly.
my_list.remove(2);
cout << endl << "New list after removing value at position 2" <<endl;
for(int i = 0; i< my_list.endOfList; i++){
    cout << my_list.list_itself[i] <<"  ";
}

cout <<endl<< "Peek at position #2 value: " << my_list.peek(2) <<endl;
cout <<endl<< "Peek at position #16 value: " << my_list.peek(16) <<endl;


return 0;
}
