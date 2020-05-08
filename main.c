#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat = ip_mat_create(2,2,2,2);
    get_val(mat,1,1,1);
    set_val(mat,1,1,1,5);
    compute_stats(mat);
    printf("max:%f\n",mat->stat->max);
    printf("min:%f\n",mat->stat->min);
    printf("mean:%f\n",mat->stat->mean);
    
    return 0;
}
