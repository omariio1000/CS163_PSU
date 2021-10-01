#include "cs163_list.h"
using namespace std;

int main()
{
    
  //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();

    //PLACE YOUR FUNCTION CALL HERE!
	//my_list.display_all();

	//cout << "The total sum of the data is: " << my_list.sum_total() << endl;
	//if (my_list.remove_last() == true) cout << "The last node has been removed." << endl;
	//else cout << "The list was empty." << endl;

	//if (my_list.remove_all() == true) cout << "The list has been deleted." << endl;
	//else cout << "The list was empty." << endl;

	//int item = 0;
	//cout << endl << "Enter the number you would like to find in the list: ";
	//cin >> item;
	//if (my_list.find_item(item)) cout << "The number " << item << " exists in the list." << endl;
	//else cout << "The number " << item << " does not exist in this list." << endl;

	my_list.copy(my_list);
	
	my_list.display_all();
	
    return 0;    
}
