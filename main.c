#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    Bitmap * picb = bm_load("flower2.bmp");
    ip_mat * pic = bitmap_to_ip_mat(picb);
    ip_mat * filt = ip_mat_create(3,3,1,1);
    ip_mat * out = ip_mat_convolve(pic,filt);

    Bitmap * new = ip_mat_to_bitmap(out);
    bm_save(new,"new.bmp");
    return 0;
}