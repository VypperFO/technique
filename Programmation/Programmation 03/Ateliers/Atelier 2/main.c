#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int nbMoves = 0;

void moveDiskSocles(struct ArrayStack *socleSrc, struct ArrayStack *socleDest) {
    int socle1Top = pop(socleSrc);
    int socle2Top = pop(socleDest);
 
    if (socle1Top == -1) {
        push(socleSrc, socle2Top);
    } else if (socle2Top == -1) {
        push(socleDest, socle1Top);
    } else if (socle1Top > socle2Top) {
        push(socleSrc, socle1Top);
        push(socleSrc, socle2Top);
    } else {
        push(socleDest, socle2Top);
        push(socleDest, socle1Top);
    }
}
 
void tourHanoi(int nbDisque, struct ArrayStack *socle0, struct ArrayStack *socle1, struct ArrayStack *socle2) {
    int i;
    int nbMoveTotal;
 
    nbMoveTotal = (nbDisque * nbDisque) - 1;
 
    for (i = nbDisque; i >= 1; i--) {
        push(socle0, i);
    }
 
    for (i = 1; i <= nbMoveTotal; i++) {
        if (i % 3 == 1) {
            moveDiskSocles(socle0, socle2);
            nbMoves++;
        } else if (i % 3 == 2) {
            moveDiskSocles(socle0, socle1);
            nbMoves++;
        } else if (i % 3 == 0) {
            moveDiskSocles(socle1, socle2);
            nbMoves++;
        }
    }
}
 

void main() {
    printf("Saissisez le nombre d'etages: ");
    int nbEtages = 0;
    scanf("%i", &nbEtages);

    struct ArrayStack *socles[3];

    socles[0] = init(nbEtages);
    socles[1] = init(nbEtages);
    socles[2] = init(nbEtages);

    tourHanoi(nbEtages, socles[0], socles[1], socles[2]);

    printf("%d", nbMoves);

    uninit(socles[0]);
    uninit(socles[1]);
    uninit(socles[2]);
}
