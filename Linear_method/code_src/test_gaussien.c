#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "divers.c"
#include "gaussien.c"


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
    int nb,nl,nc, oldnl,oldnc;
    unsigned char **im2=NULL,** im1=NULL;
    double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10, **im11, **im12, **im13, **im14, **im15;

    if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    double**im3=imuchar2double(im1,nl,nc);
    oldnl=nl; oldnc=nc;
    /*  la fft demande des puissances de 2. On padde avec des 0, mais les dimensions nl et nc changent */
    im7=padimdforfft(im3,&nl,&nc);
    /*
      On peut aussi directement utiliser
      im7=padimucforfft(im1,&nl,&nc);
      sans convertir im1 en image de réels
    */
    double sigma = 1;
    im14 = gauss(im7, nl, nc, sigma);
    /* Conversion en entier8bits de la partie reelle de la fftinverse,
    Suppresion des 0 qui ont servi a completer en utilisant la fonction crop
    Sauvegarde au format pgm de cette image */
    ecritureimagepgm(av[2],crop(imdouble2uchar(im14,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
    double valeur = psnr(im1, imdouble2uchar(im14,nl,nc), nl, nc);
    printf("psnr = %f, ", valeur);

    return EXIT_SUCCESS;
}