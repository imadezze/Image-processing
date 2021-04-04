#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "divers.c"
#include "gaussien.c"
#include "gaussienspatial.c"
#include "stdio.h"

int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
    int nl,nc, oldnl,oldnc;
    unsigned char **im2=NULL,** im1=NULL;
    double **im5;
    double **im6;

    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    double**im3=imuchar2double(im1,nl,nc);
    int sigma = 5;
    oldnl=nl; oldnc=nc;
    im6 = gauss(imuchar2double(im1,nl,nc), nl, nc, sigma);
    int indice = 1;
    while (indice < (6*sigma)){
        im5 = gaussien_spatial(im3, nl, nc, sigma, indice, indice);
        printf("%f, ", eqm_double(im6, im5, nl, nc));
          printf("%i, ", indice);
        indice += 3;
    }
}
