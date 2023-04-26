#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct People {
    const char *name;
    int age;
};


int compareFloat(const void *a, const void *b)
{
    return ((*(float *)a) - (*(float *)b));
}

int compareInt(const void *a, const void *b)
{
    return ((*(int *)a) - (*(int *)b));
}

int compareString(const void *a, const void *b)
{
    const char *p1, *p2;
    p1 = (char *)a;
    p2 = (char *)b;
    return strcmp(p1,p2);
}

int comparePString(const void *a, const void *b)
{
    const char *p1, *p2;
    p1 = ((struct People *)a)->name;
    p2 = ((struct People *)b)->name;
    return strcmp(p1,p2);
}

int compareIntString(const void *a, const void *b)
{
    int a1, a2;
    const char *s1, *s2;
    s1 = ((struct People *)a)->name;
    s2 = ((struct People *)b)->name;
    a1 = ((struct People *)a)->age;
    a2 = ((struct People *)b)->age;
    if (a1>a2)
        return 1;
    if (a1<a2)
        return 0;
    return strcmp(s1,s2);
}

void printPeople(const struct People peoples[], int n){
    int i;
    for(i=0;i<n; i++){
        printf("%s, %d\n", peoples[i].name, peoples[i].age);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int i, n;
    float numbers[]={645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    
    struct People peoples[]={{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    
    
    n=sizeof(numbers)/sizeof(float);
    qsort(numbers, n, sizeof(float), compareFloat);
    printf("Numeric Value: \n");
    for(i=0;i<n; i++){
        printf("%0.2f ", numbers[i] );
    }
    printf("\n");
    
    
    n=sizeof(peoples)/sizeof(struct People);
    qsort(peoples, n, sizeof(struct People), comparePString);
    printf("\nBy name: \n");
    printPeople(peoples,n);
    
    
   
    qsort(peoples, n, sizeof(struct People), compareIntString);
    printf("\nAge in descending, if age is same then name in ascending: \n");
    printPeople(peoples,n);
    
    return 0;
}

