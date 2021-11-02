#include "table.h"

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

    int count = display_inorder(root);
    cout << endl <<"Our count value was: " << count << endl;

    display(root);

    destroy_all(root);

    return 0;
}
