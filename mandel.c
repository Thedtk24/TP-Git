/*
Les blocs de code (ligne 23 - 35):
   les fonctions cx et cy convertissent les coordonnées en les mettant dans le plan complexe

ligne 39: structure qui va contenir l'image finale de 1500 * 1500 pixels, défini dans les lignes 18 et 19
 lignes (45 - 68):
  calcul de mandelbrot et des couleur de pixels
*/


#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "ppm.h"
 
 
#define TRSH 2.0
#define ITER 1024ull
 
#define SIZEX 1500
#define SIZEY 1500
 
double cx( int x )
{
    /* -2 ---> 1 */
    static const double qx = 3.0 / (double)SIZEX;
    return -2.0 +  x * qx;
}
 
double cy( int y )
{
    /* -1 ---> 1 */
    static const double qy = 2.0 / (double)SIZEY;
    return -1.0 + y * qy;
}
 
int main(int argc, char *argv[])
{
    struct ppm_image im;
    ppm_image_init( &im , SIZEX , SIZEY );
 
    int i,j;
    double colref = 255.0/log(ITER);
 
    for (i = 0; i < SIZEX; ++i) {
        for (j = 0; j < SIZEY; ++j) {
 
            unsigned long int iter = 0;
 
            double complex c =  cx(i) + cy(j) * I;
            double complex z = 0;
 
            while(iter < ITER)
            {
                double mod = cabs(z);
 
                if( TRSH < mod )
                {
                    break;
                }
 
                z = z*z + c;
 
                iter++;
            }
 
            int grey = colref*log(iter);
            ppm_image_setpixel(&im, i,j, grey, grey , grey );
        }
    }
 
    ppm_image_dump( &im, "m.ppm");
    ppm_image_release( &im );
 
 
    return 0;
}