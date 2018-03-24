#include<stdio.h>
#include<math.h>
#define PI 3.14159265
int N ;

struct complex{
    float real;
    float img;
} ;

int main()
{
    int  n , i , j , a , g , z , k;
    struct complex input_matrix[N][1];

    /*to read the input*/
    printf("\n Enter the number samples in the sequence X(n) (N)= ");
    scanf("%d",&N);

    printf("\n Enter the number samples in the sequence X(n) (n)= ");
    scanf("%d",&n);

    if (N >= n)
    {
        printf("\n Enter the number samples of sequence X(n)\n");
        for( i = 0 ; i < n ; i++)
        {
            struct complex w;
            printf("\n X(%d)= ",i);
            scanf("%f",&w.real);
            w.img = 0;
            input_matrix[i][0] = w;
        }

        for( j=i ; j<N ; j++)
        {
            struct complex w;
            w.real = 0;
            w.img = 0;
            input_matrix[i][0] = w;
        }
    }
    else
    {
        printf("N must be greater than n");
    }


    /*to generate twiddle matrix*/

    double pi = acos(-1);
    struct complex twiddle_matrix[N][N];

    for( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N ; j++)
        {
            struct complex w ;
            a = i*j;
            w.real = cos((2*a*pi)/N);
            w.img = sin((2*a*pi)/N);
            twiddle_matrix[i][j] = w;
        }
    }

    /*printf("\n\t The Twiddle Matrix \t\n");
    for( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < N ; j++)
        {
            printf("\n W[%i][%i] = %f + j %f \n" , i ,j ,twiddle_matrix[i][j].real , twiddle_matrix[i][j].img);
        }

    }*/

    /*to multiply the matrix*/

    struct complex product_matrix[N][1];

     for(i = 0 ; i < N ; i++)
     {
        for (j = 0 ; j < 1 ; j++)
        {
            product_matrix[i][j].real = product_matrix[i][j].img = 0;

        for(k = 0 ; k < N ; k++)
        {
            product_matrix [i][j].real+=(twiddle_matrix[i][k].real * input_matrix[k][j].real)-(twiddle_matrix[i][k].img * input_matrix[k][j].img);
            product_matrix [i][j].img+=(twiddle_matrix[i][k].real * input_matrix[k][j].img)+(twiddle_matrix[i][k].img * input_matrix[k][j].real);

        }
        }
     }

    /*printf("\n\t The Product Matrix \t\n");
    for( i = 0 ; i < N ; i++)
    {
        for ( j = 0 ; j < 1 ; j++)
        {
            printf("\n product[%i][%i] = %f + j %f \n" , i ,j ,product_matrix [i][j].real , product_matrix [i][j].img);
        }

    }*/

   /*to calculate magnitude and phase*/

    double magnitude_matrix[N][1];
    double phase_matrix[N][1];
    float val = 180.0 / PI;

    printf("\n\t The Magnitude & Phase Matrix \t\n");
    for (g = 0 ; g < N ; g++)
    {
        for ( z = 0 ; z < 1 ; z++)
        {

            magnitude_matrix[g][z] = sqrt ( product_matrix[g][z].real * product_matrix[g][z].real + product_matrix[g][z].img * product_matrix[g][z].img);
            printf("\n magnitude[%i][%i] = %f \n" , g , z,magnitude_matrix[g][z]);
            phase_matrix[g][z] = atan(product_matrix[g][z].img / product_matrix[g][z].real) * val;
            printf("\n phase[%i][%i] = %f \n", g , z,phase_matrix[g][z]);
        }
    }
    return 0;
}
