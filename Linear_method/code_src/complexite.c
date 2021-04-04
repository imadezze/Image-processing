#include <time.h>
#include "pgm.h"
#include "stdio.h"
#include "gaussien.c"
#include "gaussienspatial.c"

int main (int ac, char **av) {
    int nb,nl,nc, oldnl,oldnc;
    unsigned char **im2=NULL,** im1=NULL;
    double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10, **im11, **im12, **im13, **im14, **im15;

    if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    double**im3=imuchar2double(im1,nl,nc);
    oldnl=nl; oldnc=nc;
    /*  la fft demande des puissances de 2. On padde avec des 0, mais les dimensions nl et nc changent */
    double sigma = 0.5;
    clock_t debut, fin;
    debut = clock();
    //gaussien_spatial(im3, nl, nc, sigma, 4 * sigma, 4 * sigma);
    im7=padimdforfft(im3,&nl,&nc);
    gauss(im7, nl, nc, sigma);
    fin = clock();
    printf(" duree = %f \n ", ((double) fin - debut) / CLOCKS_PER_SEC);
    return EXIT_SUCCESS;

}