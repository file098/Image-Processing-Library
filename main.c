#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bmp.h"
#include "ip_lib.h"

int main(){

    ip_mat * mat = ip_mat_create(2,2,2,2);
    get_val(mat,2,2,2);
    set_val(mat,2,2,2,1);
    printf("%f",mat->data[2][2][2]);
    return 0;
}
