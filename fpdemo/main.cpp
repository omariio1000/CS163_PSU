#include "table.h"

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

    //int count = display_inorder(root);
    //cout << endl <<"Our count value was: " << count << endl;

    int to_add = 0;
    cout << "What value would you like to add: ";
    cin >> to_add;
    cin.ignore(100, '\n');
    insert_BST(root, to_add);

    display(root);

    destroy_all(root);

    return 0;
}
