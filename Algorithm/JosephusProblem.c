#include <stdlib.h>
#include <stdio.h>

#include "linknode.h"


int main(int argc, char *argv[]) {
    // read argument variable
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    // create head node
    link head = malloc(sizeof(*head));
    head->item = 1;
    // circulate
    head->next = head;
    // create other nodes
    link curr = head;
    int i;
    for (i = 2; i <= N; i++) {
        link nt = malloc(sizeof(*nt));
        nt->item = i;
        // circulate
        nt->next = head;
        // modify curr node
        curr->next = nt;
        curr = nt;
    }
    // selection
    while (curr != curr->next) {
        // skip nodes
        for (i = 1; i < M; i++) {
            curr = curr->next;
        }
        // delete node
        link temp = curr->next;
        curr->next = temp->next;
        free(temp);
        // delete without free
        //curr->next = curr->next->next;
    }
    // print last left node
    printf("%d\n", curr->item);

    // Test Case:
    // input: N=9, M=5
    // output: 8
}

