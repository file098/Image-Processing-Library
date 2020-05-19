#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    Bitmap * new;
    // Immagine vera
    Bitmap * picb = bm_load("mongolfiere.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);

    ip_mat * filt = create_gaussian_filter(9,9,3,0.5);

    ip_mat * out = ip_mat_convolve(pic, filt);
    rescale(out,255.0);
    clamp(out,0.0,255.0);

    new = ip_mat_to_bitmap(out);
    bm_save(new,"new.bmp");

    return 0;
}
