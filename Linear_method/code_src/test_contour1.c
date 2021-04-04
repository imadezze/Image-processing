#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "divers.c"
#include "stdio.h"
#include "contour1.c"


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
    int nl,nc, oldnl,oldnc;
    unsigned char **im2=NULL,** im1=NULL;
    if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1=lectureimagepgm(av[1],&nl,&nc);
    oldnl=nl; oldnc=nc;

    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    im2 = gradient_Prewitt(im1, nl, nc);
    ecritureimagepgm(av[2],crop(im2,0,0,oldnl,oldnc),oldnl,oldnc);


    return EXIT_SUCCESS;
}