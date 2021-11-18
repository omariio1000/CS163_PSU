#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
    //Allocate the adjacency list and set each
    //head pointer to NULL
    adjacency_list = new vertex[size];
    for (int i = 0; i < size; i++) {
        adjacency_list[i].head = nullptr;
        adjacency_list[i].entry = nullptr;
    }
    list_size = size;
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
    int index;
    //return the location of this particular key value 
    for (int i = 0; i < list_size; i++) {
        if (adjacency_list[i].entry) {
            if(adjacency_list[i].entry -> compare(key_value)) {
                index = i;
            }
        }
    }
    return index;

}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{
    //Place your code here
    /*int counter = 0;
    while (adjacency_list[counter].entry) counter++;
    if (counter >= list_size) return 0;
    adjacency_list[counter].entry -> copy_entry(to_add);
    return 1;
    */

    journal_entry * temp = new journal_entry;
    temp -> copy_entry(to_add);
    for (int i = 0; i < list_size; i++) {
        if (!adjacency_list[i].entry) {
            adjacency_list[i].entry = temp;
            break;
        }
    }
    return 1;
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
    //Attach this vertices edge to the specified vertex
    int idx = find_location(current_vertex);
    int attachIdx = find_location(to_attach);

    node * adding = new node;
    adding -> adjacent = &adjacency_list[attachIdx];
    adding -> next = adjacency_list[idx].head;
    adjacency_list[idx].head = adding;
    
    /*node * adding = adjacency_list[idx].head;
    while (adding) adding = adding -> next;
    adding = new node;
    adding -> adjacent = &adjacency_list[attachIdx];
    */
    return 1;
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{
    int idx = find_location(key_value);
    node * displaying = adjacency_list[idx].head;
    while (displaying) {
        displaying -> adjacent -> entry -> display();
        displaying = displaying -> next;
    }
    return 1;
}
