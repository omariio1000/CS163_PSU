#include "clist.h"

//Here is the main you will use for the circular linked list portion

int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	 	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function being tested
    cout << endl << "Sum of data: " << object.count_all() << endl;
    object.remove_entire();

    object.display(); //resulting list after your function call!
    
    return 0;
}
