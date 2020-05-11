#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){
    ip_mat * n1_ip_mat = ip_mat_create(5,5,3,0.0);
    ip_mat * n2_ip_mat = ip_mat_create(5,5,3,254.0);
    ip_mat * new_ip_m = ip_mat_blend(n1_ip_mat,n2_ip_mat,0.5);
    Bitmap * new  = ip_mat_to_bitmap(new_ip_m);
    bm_save(new,"new.bmp");
    return 0;
}
