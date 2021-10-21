#include "dlist.h"

//Now let's test doubly linked lists

int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int data = 999;
    int out = object.insert_before(data);
   cout << endl << "Total nodes: "
       << out << endl;

    object.display();
    
    return 0;
}
