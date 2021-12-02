#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    trees.display_largest();
    cout << endl << "The root's value is repeated " << trees.count_root() << " times in the BST" << endl;

    /*table copyTree;
    copyTree.copy(trees);
    cout << endl << "THIS IS THE NEW TREE" << endl;
    copyTree.display();*/

    cout << endl << "The number of nodes with 3 data members in the 2-3-4 tree is " << trees.count_3_data() << endl;
    cout << endl << "The height of the 2-3-4 tree is " << trees.height() << endl;

    table copyTree;
    copyTree.copy(trees);
    copyTree.copy_234(trees);
    cout << endl << "NEW TREE" << endl;
    copyTree.display();

    return 0;
}
