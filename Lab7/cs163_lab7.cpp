#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */

    cout << endl << "Count: " << BST.count() << endl;
    cout << endl << "Sum: " << BST.sum() << endl;
    cout << endl << "Height: " << BST.height() << endl;
    table newBST;
    newBST.copy(BST);
    cout << endl << "NEW BST" << endl;
    newBST.display();
    cout << endl << "displayed" << endl;
    cout << endl << "Deleted: " << BST.remove_all() << endl;



    BST.display();

    return 0;
}
