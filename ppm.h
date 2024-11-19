/*
struct ppm_pixel, représente un pixel de l'image en utilisant les composantes de couleur rouge, verte et bleue.
struct ppm_image, représente une image au format PPM.
int ppm_image_init(struct ppm_image *im, int w, int h), initialise une structure ppm_image avec les dimensions spécifiées.
int ppm_image_release(struct ppm_image *im), libère les ressources de la structure ppm_image
void ppm_setpixel(struct ppm_pixel *px, unsigned char r, unsigned char g, unsigned char b), fonction pour définir la couleur d'un pixel.
int ppm_image_dump(struct ppm_image *im, char *path), sauvegarde une image PPM dans un fichier.
*/






#ifndef PPM_H
#define PPM_H

struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

int ppm_image_init(struct ppm_image *im, int w, int h);
int ppm_image_release(struct ppm_image *im);

static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */