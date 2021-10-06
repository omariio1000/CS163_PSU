#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	/*
	int counter = remove_last_recursive(head);
	cout << "The first version gave us this count: " << counter << endl;

	counter = remove_last_refined(head);
	cout << "Now the counter will be one less: " << counter;
	*/
	
	//int counter = remove_largest(head);
	//cout << "We removed " << counter << " nodes" << endl;

	int count_match = append_end(head);
	cout << "We found " << count_match << " number of matches to the first." << endl;
	
    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}
