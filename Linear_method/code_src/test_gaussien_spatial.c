#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "divers.c"
#include "gaussienspatial.c"




int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
    int nl,nc, oldnl,oldnc;
    unsigned char **im2=NULL,** im1=NULL;
    double **im5;
    if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    double**im3=imuchar2double(im1,nl,nc);
    double sigma = 2;
    oldnl=nl; oldnc=nc;
    im5 = gaussien_spatial(im3, nl, nc, sigma, 11, 12);
    /* Conversion en entier8bits de la partie reelle de la fftinverse,
          Suppresion des 0 qui ont servi a completer en utilisant la fonction crop
          Sauvegarde au format pgm de cette image */
    ecritureimagepgm(av[2],crop(imdouble2uchar(im5,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);

    return EXIT_SUCCESS;
}