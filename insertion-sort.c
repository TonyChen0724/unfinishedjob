/* todo: finish the binsearch method */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000
/* going from left to right of array, and keep the left array sorted and insert
 * item from right array to the proper position of left array */
void insertion_sort(int *a, int n) {
    int p;
    int key;
    int i;
    for (p = 1; p < n; p++) {
        key = a[p];
        /*for (i = p-1; i >= 0; i--) {
            if (a[i] > key) {
                a[i+1] = a[i];
            }
            
        }*/
        i = p - 1;
        while (i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i --;
        }
        a[i+1] = key;
    }

}

void print_array(int *a, int n) {
    if (n > 0) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

void binsearch(int *a, int len, int var) {
    

}

int main(int argc, char **argv) {
    FILE *infile;
    int my_array[ARRAY_MAX];
    int count = 0;
    int i;

    if (NULL == (infile = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    while (count < ARRAY_MAX && 1 == fscanf(infile, "%d", &my_array[count])) {
        count ++;
    }

    insertion_sort(my_array, count);
    int query;

    /*whileloop:while (1 == scanf("%d", &query)) {
        for (i = 0; i < count; i++) {
            if (query == my_array[i]) {
                printf("%s\n", "+");
                goto whileloop;
            }
        }
        printf("%s\n", "-");
    }*/

    while (1 == scanf("%d", &query)) {
        binsearch(my_array, count, query);
    }
        
    

    return EXIT_SUCCESS;
}
