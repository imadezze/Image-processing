#include "pgm.h"
#include <math.h>
#define PI 3.14159

/*
 * commentaire
 */

double G(int i,double sigma){
    return exp(-((float) (i*i))/((2*sigma*sigma)));
}
double sommeG(double sigma, int n){
    double resultat = 0;
    for (int i = -n; i <= n; i++){
        resultat += G(i,sigma);
    }
    return 1/((float) resultat);
}
double R(int x, int y, double ** im,double sigma, int n, int m, int nl, int nc){
    double resultati = 0;
    for (int i = -n; i <= n; i++){
        double resultatj = 0;
        for (int j = -m; j <= m; j++){
            if(((x+i)>=nl)|| ((x+i)<0) || ((y+j)>=nc)|| ((y+j)<0)){
                resultatj += G(j, sigma)*im[(x+i+nl)%nl][(y+j+nc)%nc];
            }else{
                resultatj += G(j, sigma)*im[x+i][y+j];
            }
        }
        resultati += resultatj * G(i, sigma);
    }

    return resultati*sommeG(sigma, n)*sommeG(sigma, m);
}


double **gaussien_spatial(double **im3, int nl, int nc, double sigma, int n, int m) {
    double** im4,** im5;
    long double module = 0.0;
    double max = 0;
    im4=alloue_image_double(nl,nc); im5=alloue_image_double(nl,nc);
    for (int x = 0; x<nl; x++){
        for(int y = 0; y<nc; y++){
            im4[x][y] = R(x, y, im3, sigma, n, m, nl, nc);
        }
    }
    return im4;
}


