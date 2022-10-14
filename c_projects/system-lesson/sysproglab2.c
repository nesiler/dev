/*#include <stdio.h>


int main(int argc, char **argv)
{
        
    struct s0 {
        char data[1]; //data
        char c2[0]; //pointer to the end of struct
    }     a;

        
   
    
    //printf("%p %p %p", &a.c2,  &a.c2, a.c2);


    printf("%d", sizeof(a));
    return 0;
}*/

/*#include <stdio.h>

int main(){
    struct s0 {
        char c1[1];
        char c2[0]; 
    } a;
    
    struct s1 {
        char c1[1];
        int c2[0]; 
    }     b;
    
    struct s2 {
        char c1[1];
        double c2[0]; 
    }     c;
    
    printf("sizeof(a):%d sizeof(b):%d sizeof(c):%d\n", sizeof(a), sizeof(b), sizeof(c));
    
}
*/
/*#include <stdio.h>

int main(){
    struct  {
        char c1;
        int  i;

    } a;
    
    struct  {
        char c1;
        int  i;
        char c2;

    }  b;
    
    struct  {
        char c1[5];
        int  i;

    } c;
    
    struct  {
        char c1;
        char c2;
        int i;

    }  d;
    
    struct {
        char c1;
        char *cp;
        char c2;

    }  e;
    
    struct  {
        char c1[5];
        char  *cp;

    } f;
    
    struct picture{
        int height; //4 byte
        double** data; //8 byte
        int width; //4 byte
        char* encoding; //8 byte
} p1;

struct picture2{
        char height; //4 byte
        int width; //4 byte
        double** data; //8 byte
        char* encoding; //8 byte
} p2;
    
    printf("a:%d b:%d c:%d d:%d e:%d f:%d\n picture1:%d picture2:%d",
            sizeof(a), sizeof(b), sizeof(c), 
            sizeof(d), sizeof(e), sizeof(f), sizeof(p1), sizeof(p2));
            

    
}*/

#include <stdio.h>


int main(){
    struct  {
        char c1[1];

    } a;
    
    struct  {
        char c1[1];

    }__attribute__((aligned))    b;
    
    struct  {
        char c1[1];

    }__attribute__((aligned(2)))    c;
    
    struct {
        char c1[1];

    }__attribute__((aligned(4)))    d;
    
    struct  {
        char c1[1];

    }__attribute__((aligned(8)))    e;
    
    struct  {
        char c1[1];

    }__attribute__((aligned(16)))    f;
    
    printf("a:%d b:%d c:%d d:%d e:%d f:%d\n",
            sizeof(a), sizeof(b), sizeof(c), 
            sizeof(d), sizeof(e), sizeof(f));
    
}
