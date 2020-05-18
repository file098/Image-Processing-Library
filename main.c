#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    // Immagine vera
    Bitmap * picb = bm_load("mongolfiere.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);

    ip_mat * filt = create_gaussian_filter(3,3,3,3);
    ip_mat_show(filt);
    //ip_mat * test = ip_mat_create(5,5,3,1.0);
    //ip_mat_show(test);
    ip_mat * out = ip_mat_convolve(pic,filt);
    rescale(out,255);
    clamp(out,0,255);

    Bitmap * new = ip_mat_to_bitmap(out);
    bm_save(new,"new.bmp");

    return 0;
}