#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "stdio.h"
#include "contour2.c"


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
    int nl, nc, oldnl, oldnc;
    unsigned char **im1 = NULL;
    double **im2 = NULL;
    double **im3 = NULL, **im4 = NULL;
    if (ac < 3) {
        printf("Usage : %s entree sortie \n", av[0]);
        exit(1);
    }
    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1 = lectureimagepgm(av[1], &nl, &nc);
    oldnl = nl;
    oldnc = nc;

    if (im1 == NULL) {
        puts("Lecture image impossible");
        exit(1);
    }
    /* Lissage gaussienne */
    double sigma = 1;
    im2 = gauss(imuchar2double(im1, nl, nc), nl, nc, sigma);
    im3 = laplacien(imdouble2uchar(im2, nl, nc), nl, nc);
    im4 = extraction_contour_laplacien(im3, imuchar2double(im1, nl, nc), nl, nc);
    ecritureimagepgm(av[2], crop(imdouble2uchar(im4, nl, nc), 0, 0, oldnl, oldnc), oldnl, oldnc);
    return EXIT_SUCCESS;
}