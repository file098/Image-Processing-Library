#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat1 = ip_mat_create(2,2,3,0);
    ip_mat * mat2 = ip_mat_create(2,2,3,1);
    ip_mat * sum = ip_mat_sum(mat1,mat2);
    ip_mat_show(sum);
    return 0;
}
