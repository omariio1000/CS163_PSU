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
    
    

    int duped = duplicateWrapper(root);
    cout << endl << "You duplicated the maximum value, which was: " << duped << endl;

    display(root);

    if (checkDuplicate(root)) cout << endl << "Your root's value is duplicated in the tree." << endl;
    else cout << endl << "Root has unique value." << endl;

    //destroy_all(root);
    int removedLeaves = removeLeaf(root);
    cout << endl << removedLeaves << " leaves were removed." << endl;
    
    display(root);

    int removed = removeWrapper(root);
    if (removed == 0) cout << endl << "Your tree is empty!" << endl;
    else cout << endl << removed << " items were removed." << endl;

    display(root);

    return 0;
}
