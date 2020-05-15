#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    // Immagine vera
    //Bitmap * picb = bm_load("flower.bmp");
    //ip_mat * pic = bitmap_to_ip_mat(picb);

    //ip_mat * filt = create_emboss_filter();
    //ip_mat_show(filt);
    ip_mat * A = ip_mat_create(5,5,3,1.0);
    ip_mat * B = ip_mat_create(5,5,5,2.0);
    ip_mat * out = ip_mat_concat(A,B,2);
    //ip_mat * out = ip_mat_convolve(pic, filt);
    ip_mat_show(out);
    //Bitmap * new = ip_mat_to_bitmap(out);
   // bm_save(new,"new.bmp");

    return 0;
}