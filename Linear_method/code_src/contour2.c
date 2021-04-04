#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "stdio.h"
#include "gaussien.c"



double **extraction_contour_laplacien(double **image, double **origin, int nl, int nc) {
    double **contour;
    contour = alloue_image_double(nl, nc);
    for (int i = 0; i < nl-1; i++) {
        for (int j = 0; j < nc - 1; j++) {
            if (image[i][j] * image[i][j + 1] < 0 || image[i][j] * image[i + 1][j] < 0) {
                contour[i][j] = 255;
            }
            else {
                contour[i+1][j] = 0;
                contour[i][j+1] = 0;
            }
        }
    }
    for (int i = 0; i < nl-1; i++) {
        if (image[i][nc-1] * image[i+1][nc-1] < 0) {
            contour[i][nc-1] = 255;
        }
        else {
            contour[i+1][nc-1] = 0;
        }
    }
    for (int j = 0; j < nc-1; j++) {
        if (image[nl-1][j] * image[nl-1][j+1] < 0) {
            contour[nl-1][j] = 255;
        }
        else {
            contour[nl-1][j+1] = 0;
        }
    }
    return contour;
}


double **laplacien(unsigned char **im, int nl, int nc){
    double ** im1=NULL;
    im1=alloue_image_double(nl,nc);
    double gx = 0;
    double ** im2=NULL;
    im2=alloue_image_double(nl+2,nc+2);
    for(int y = 1; y<nc+1; y++) {
        for (int x = 1; x<nl+1; x++){
            im2[x][y] = im[x-1][y-1];
            im2[x][0] = 0;
            im2[x][nc+1] = 0;
        }
        im2[0][y] = 0;
        im2[nl+1][y] = 0;
    }
    for (int x = 1; x<nl+1; x++){
        for(int y = 1; y<nc+1; y++){
            double valeur1 = im2[x-1][y-1],valeur2 =  im2[x][y-1], valeur3 = im2[x+1][y-1], valeur4 = im2[x-1][y+1], valeur5 = im2[x][y+1], valeur6 = im2[x+1][y+1], valeur7 = im2[x-1][y], valeur8 = im2[x+1][y];

            gx = valeur2 + valeur7 - 4 * im2[x][y] + valeur8 + valeur5;
            im1[x-1][y-1] = gx;
        }
    }
    return im1;

}

