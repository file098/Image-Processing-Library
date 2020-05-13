#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    // Immagine vera
    Bitmap * picb = bm_load("flower2.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);

    //ip_mat * picc = ip_mat_create(5,5,3,1.0);
    ip_mat * filt = ip_mat_create(3,3,1,-1.0);
    set_val(filt,1,1,0,-8.0);
    ip_mat_show(filt);
    ip_mat * out = ip_mat_convolve(pic, filt);
    
    Bitmap * new = ip_mat_to_bitmap(out);
    bm_save(new,"new.bmp");
    
    return 0;
}