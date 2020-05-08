#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat = ip_mat_create(2,2,3,0);
    get_val(mat,1,1,1);
    set_val(mat,1,1,2,5);
    compute_stats(mat);
    ip_mat_show(mat);
    ip_mat_show_stats(mat);
    return 0;
}
