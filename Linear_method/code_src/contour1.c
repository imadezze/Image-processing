#include "pgm.h"
#include <math.h>
#define PI 3.14159
#include "stdio.h"

/*
 * commentaire
 */

unsigned char **gradient_Prewitt(unsigned char **im, int nl, int nc){
    double ** im1=NULL;
    im1=alloue_image_double(nl,nc);
    double gx = 0;
    double gy = 0;
    double p1 = 0;
    double p2 = 0;
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

            gx = -valeur1 + valeur3 - valeur7+ valeur8-valeur4 + valeur6;
            gy = -valeur1 - valeur3 - valeur2 + valeur4 + valeur6 + valeur5;

            im1[x-1][y-1] = sqrt(pow(gx, 2)+ pow(gy, 2));
        }
    }
    for (int x = 2; x<nl; x++) {
        for (int y = 2; y < nc; y++) {
            double valeur1 = im2[x-1][y-1],valeur2 =  im2[x][y-1], valeur3 = im2[x+1][y-1], valeur4 = im2[x-1][y+1], valeur5 = im2[x][y+1], valeur6 = im2[x+1][y+1], valeur7 = im2[x-1][y], valeur8 = im2[x+1][y];
            gx = -valeur1 + valeur3 - valeur7+ valeur8-valeur4 + valeur6;
            gy = -valeur1 - valeur3 - valeur2 + valeur4 + valeur6 + valeur5;
            if ((gx>0 && gy>0)||(gx<0 && gy<0)){
                p1 = (gy/gx)*im1[x-1][y-2] + ((gx-gy)/gx)*im1[x][y-1];
                p2 = (gy/gx)*im1[x-1][y]+((gx-gy)/gx)*im1[x-2][y-1];
                if ((im1[x-1][y-1]< p1) || (im1[x-1][y-1]< p2)){
                    im1[x-1][y-1] = 0;
                }
            }
        }
    }
    return imdouble2uchar(im1,nl,nc);

}
unsigned char **contour(unsigned char **im, int nl, int nc){
    double ** im1=NULL;
    im1=alloue_image_double(nl,nc);
}


