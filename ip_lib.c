/*
 Created by Sebastiano Vascon on 23/03/20.
*/

#include <stdio.h>
#include "ip_lib.h"
#include "bmp.h"

void ip_mat_show(ip_mat * t){
    unsigned int i,l,j;
    printf("Matrix of size %d x %d x %d (hxwxk)\n",t->h,t->w,t->k);
    for (l = 0; l < t->k; l++) {
        printf("Slice %d\n", l);
        for(i=0;i<t->h;i++) {
            for (j = 0; j < t->w; j++) {
                printf("%f ", get_val(t,i,j,l));
            }
            printf("\n");
        }
        printf("\n");
    }
}

void ip_mat_show_stats(ip_mat * t){
    unsigned int k;

    compute_stats(t);

    for(k=0;k<t->k;k++){
        printf("Channel %d:\n", k);
        printf("\t Min: %f\n", t->stat[k].min);
        printf("\t Max: %f\n", t->stat[k].max);
        printf("\t Mean: %f\n", t->stat[k].mean);
    }
}

ip_mat * bitmap_to_ip_mat(Bitmap * img){
    unsigned int i=0,j=0;

    unsigned char R,G,B;

    unsigned int h = img->h;
    unsigned int w = img->w;

    ip_mat * out = ip_mat_create(h, w,3,0);

    for (i = 0; i < h; i++)              /* rows */
    {
        for (j = 0; j < w; j++)          /* columns */
        {
            bm_get_pixel(img, j,i,&R, &G, &B);
            set_val(out,i,j,0,(float) R);
            set_val(out,i,j,1,(float) G);
            set_val(out,i,j,2,(float) B);
        }
    }

    return out;
}

Bitmap * ip_mat_to_bitmap(ip_mat * t){

    Bitmap *b = bm_create(t->w,t->h);

    unsigned int i, j;
    for (i = 0; i < t->h; i++)              /* rows */
    {
        for (j = 0; j < t->w; j++)          /* columns */
        {
            bm_set_pixel(b, j,i, (unsigned char) get_val(t,i,j,0),
                    (unsigned char) get_val(t,i,j,1),
                    (unsigned char) get_val(t,i,j,2));
        }
    }
    return b;
}

float get_val(ip_mat * a, unsigned int i,unsigned int j,unsigned int k){
    if(i<a->h && j<a->w &&k<a->k){  /* j>=0 and k>=0 and i>=0 is non sense*/
        return a->data[i][j][k];
    }else{
        printf("Errore get_val!!!");
        exit(1);
    }
}

void set_val(ip_mat * a, unsigned int i,unsigned int j,unsigned int k, float v){
    if(i<a->h && j<a->w &&k<a->k){
        a->data[i][j][k]=v;
    }else{
        printf("Errore set_val!!!");
        exit(1);
    }
}

float get_normal_random(){
    float y1 = ( (float)(rand()) + 1. )/( (float)(RAND_MAX) + 1. );
    float y2 = ( (float)(rand()) + 1. )/( (float)(RAND_MAX) + 1. );
    return cos(2*PI*y2)*sqrt(-2.*log(y1));

}

ip_mat * ip_mat_create(unsigned int h, unsigned int w,unsigned  int k, float v) {
    ip_mat *new_ip_mat;
    int i,j,p;

    new_ip_mat=(ip_mat *)malloc(sizeof(ip_mat));

    new_ip_mat->h=h;
    new_ip_mat->w=w;
    new_ip_mat->k=k;

    new_ip_mat->stat=(stats *)malloc(sizeof(stats)*k);
    for (i=0;i<k;i++) {
        new_ip_mat->stat[i].max=v;
        new_ip_mat->stat[i].min=v;
        new_ip_mat->stat[i].mean=v;
    }


    new_ip_mat->data=(float ***)malloc(sizeof(float **)*h);
    for (i=0;i<h;i++) {
        (new_ip_mat->data)[i]=(float **)malloc(sizeof(float*)*w);
        for (j=0;j<w;j++) {
            (new_ip_mat->data)[i][j]=(float *)malloc(sizeof(float)*k);
            for (p=0;p<k;p++) {
                (new_ip_mat->data)[i][j][p]=v;
            }
        }
    }
    return new_ip_mat;
}

void ip_mat_free(ip_mat *a){
    int i;
    int j;
    
    for(i=0;i<a->h;i++) {
        for(j=0;j<a->w;j++) {
            free(a->data[i][j]);
        }
        free(a->data[i]);
    }
    free(a->data);
    free(a->stat);
    free(a);
}

/* Calcola il valore minimo, il massimo e la media per ogni canale
 * e li salva dentro la struttura ip_mat stats
 * */
void compute_stats(ip_mat * t) {
    int i,j,m;
    float count = 0.0;
    float max, min;
    float tot = 0;

    max = t->data[0][0][0];
    min = t->data[0][0][0];

    for (m=0;m<t->k;m++) {
        for (i=0;i<t->h;i++) {
            for (j=0;j<t->w;j++) {
                if (t->data[j][i][m] > max) 
                    max = t->data[j][i][m];

                if (t->data[j][i][m] < max) 
                    min = t->data[j][i][m];

                count++;

                tot += t->data[j][i][m];
            }
        }
    }

    tot = tot/(1.0 * count);

    t->stat->max = max;
    t->stat->min = min;
    t->stat->mean = tot;
}

/* Inizializza una ip_mat con dimensioni w h e k.
 * Ogni elemento è generato da una gaussiana con media mean e varianza var */

/*rimpiazzo ogni elemento della matrice con valori genreati da una funzione gaussiana*/
void ip_mat_init_random(ip_mat * t, float mean, float var){

}

/**** PARTE 1: OPERAZIONI MATEMATICHE FRA IP_MAT ****/
/* Esegue la somma di due ip_mat (tutte le dimensioni devono essere identiche)
 * e la restituisce in output. */
ip_mat * ip_mat_sum(ip_mat * a, ip_mat * b){
    ip_mat *new_ip_mat;
    int i,j,z;
    new_ip_mat = ip_mat_create(a->w,a->h,a->k,0.0);

    if(a->h != b->h || a->w != b->w || a->k != b->k){
        printf("Error, ip_mat a and b are not the same size");
    }
    else{
        for(i=0;i<a->w;i++){
            for(j=0;j<a->h;j++){
                for(z=0;z<a->k;z++){
                    new_ip_mat->data[i][j][z] = a->data[i][j][z] + b->data[i][j][z];
                }
            }
        }
        compute_stats(new_ip_mat);
    }
    return new_ip_mat;
}

/* Esegue la sottrazione di due ip_mat (tutte le dimensioni devono essere identiche)
 * e la restituisce in output.
 * */
ip_mat * ip_mat_sub(ip_mat * a, ip_mat * b){
    ip_mat *new_ip_mat;
    int i,j,z;
    new_ip_mat = ip_mat_create(a->w,a->h,a->k,0.0);

    if(a->h != b->h || a->w != b->w || a->k != b->k){
        printf("Error, ip_mat a and b are not the same size");
    }
    else{
        for(i=0;i<a->w;i++){
            for(j=0;j<a->h;j++){
                for(z=0;z<a->k;z++){
                    new_ip_mat->data[i][j][z] = a->data[i][j][z] - b->data[i][j][z];
                }
            }
        }
        compute_stats(new_ip_mat);
    }
    return new_ip_mat;
}

/* Moltiplica un ip_mat per uno scalare c. Si moltiplica c per tutti gli elementi di "a"
 * e si salva il risultato in un nuovo tensore in output. */
ip_mat * ip_mat_mul_scalar(ip_mat *a, float c){
        ip_mat *new_ip_mat;
    int i,j,z;
    new_ip_mat = ip_mat_create(a->w,a->h,a->k,0.0);

    for(i=0;i<a->w;i++){
        for(j=0;j<a->h;j++){
            for(z=0;z<a->k;z++){
                new_ip_mat->data[i][j][z] *= c;
            }
        }
    }
    compute_stats(new_ip_mat);
    return new_ip_mat;
}

/* Aggiunge ad un ip_mat uno scalare c e lo restituisce in un nuovo tensore in output. */
ip_mat *  ip_mat_add_scalar(ip_mat *a, float c){
    ip_mat *new_ip_mat;
    int i,j,z;
    new_ip_mat = ip_mat_create(a->w,a->h,a->k,0.0);

    for(i=0;i<a->w;i++){
        for(j=0;j<a->h;j++){
            for(z=0;z<a->k;z++){
                new_ip_mat->data[i][j][z] += c;
            }
        }
    }
    compute_stats(new_ip_mat);
    return new_ip_mat;
}

/* Calcola la media di due ip_mat a e b e la restituisce in output.*/
ip_mat * ip_mat_mean(ip_mat * a, ip_mat * b){
    ip_mat *new_ip_mat;
    int i,j,z;
    new_ip_mat = ip_mat_create(a->w,a->h,a->k,0.0);

    if(a->h != b->h || a->w != b->w || a->k != b->k){
        printf("Error, ip_mat a and b are not the same size");
    }
    else{
        for(i=0;i<a->w;i++){
            for(j=0;j<a->h;j++){
                for(z=0;z<a->k;z++){
                    new_ip_mat->data[i][j][z] = (a->data[i][j][z] + b->data[i][j][z])/2.0;
                }
            }
        }
        compute_stats(new_ip_mat);
    }
    return new_ip_mat;
}