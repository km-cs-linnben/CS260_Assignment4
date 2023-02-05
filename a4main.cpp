#include <iostream>
#include <cstdlib>

#include "a4_list.h"

using namespace std;

a_list::a_list(int initialSize = 16) {
   list_itself = new int[initialSize];
   for (int i = 0; i < initialSize; i++) {
        list_itself[i] = 0;
    }
   endOfList = initialSize;
}

bool a_list::add(int position, int value){
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

int a_list::remove(int position){
    int value_removed = list_itself[position];

    for(int i = position; i < endOfList; ++i) {
        list_itself[i-1] = list_itself[i];
    }

    endOfList--;

    return value_removed;
}





main(){

a_list my_list(16);

my_list.add(1, 1);
my_list.add(2, 2);
my_list.add(3, 3);
my_list.add(4, 4);
my_list.add(5, 5);
my_list.add(6, 6);

my_list.add(2, 88);
my_list.add(16, 77);
my_list.add(16, 70);
for(int i = 0; i< my_list.endOfList; i++){
    cout << my_list.list_itself[i] <<endl;
}

my_list.remove(2);
for(int i = 0; i< my_list.endOfList; i++){
    cout << my_list.list_itself[i] <<endl;
}

return 0;
}
