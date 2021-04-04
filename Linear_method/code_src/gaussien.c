#include "pgm.h"
#include <math.h>
#define PI 3.14159

/*
 * commentaire
 */

double fourierGaussien(int u,int v, int nb, int nc, double sigma){
    float valeur1 = (((float) (u - nb / 2)) / (float) nb);
    float valeur2 = (((float) (v - nc / 2)) / (float) nc);
    double resultat = exp(-2*M_PI*M_PI*(sigma)*(sigma)*((valeur1)*(valeur1)+(valeur2)*(valeur2)));
    return resultat;
}

double **gauss(double **im7, int nl, int nc, double sigma) {
    double** im4,** im5, ** im6, **im8, **im9,**im10, **im11, **im12, **im13, **im14, **im15;
    /* Creation des images pour les parties reelles et imagianires des fft  */
    im4=alloue_image_double(nl,nc); im5=alloue_image_double(nl,nc); im6=alloue_image_double(nl,nc);
    /* Clacul de la fft de im7,im4 */
    fft(im7,im4,im5,im6,nl,nc);
    im8=alloue_image_double(nl,nc); im9=alloue_image_double(nl,nc);
    fftshift(im5, im6, im8, im9, nl, nc);
    im10=alloue_image_double(nl,nc); im11=alloue_image_double(nl,nc);
    for (int i=0; i<nl; i++){
        for (int j=0; j<nc; j++){
            im10[i][j] = im8[i][j]*(fourierGaussien(i, j, nl, nc, sigma));
            im11[i][j] = im9[i][j]*(fourierGaussien(i, j, nl, nc, sigma));
        }
    }
    im12=alloue_image_double(nl,nc); im13=alloue_image_double(nl,nc);
    fftshift(im10, im11, im12, im13, nl, nc);
    im14=alloue_image_double(nl,nc); im15=alloue_image_double(nl,nc);
    /* Clacul de la fft inverse de im12,im13 */
    ifft(im12,im13,im14,im15,nl,nc);
    return im14;
}

