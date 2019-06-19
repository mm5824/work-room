#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TWN{
    float data;
    struct TWN *prev;
    struct TWN *next;
}TWN;

typedef struct{
    TWN *cur;
}CTWL;


CTWL *ctwl_create_empty(void);
CTWL *ctwl_create_random(unsigned int size);

float ctwl_sum_values(CTWL * list);

int main(int argc, const char * argv[]) {
    
    CTWL *list = ctwl_create_random(5);
    
    printf("sum = %f\n", ctwl_sum_values(list));
    
    return 0;
}


CTWL *ctwl_create_empty(void){
    CTWL *ctwl = malloc(sizeof(CTWL));
    ctwl->cur = NULL;
    return ctwl;
}

CTWL *ctwl_create_random(unsigned int size){
    
    srand((unsigned int)time(NULL));
    
    CTWL *ctwl = ctwl_create_empty();
    
    TWN *first = NULL;
    TWN *prev = NULL;
    TWN *page = NULL;
    
    for(unsigned int i=0; i<size; i++){
        page = malloc(sizeof(TWN));
        page->data = rand();
        
        if(i==0){
            first = page;
            prev = page;
        }else {
            prev->next = page;
            page->prev = prev;
            prev = page;
        }
    }
    page->next = first;
    first->prev = page;
    
    ctwl->cur = first;
    
    return ctwl;
}

float ctwl_sum_values(CTWL * list){
    
    float sum = 0;
    
    TWN *page = list->cur;
    
    do{
        if(page == NULL)
            return 0;
        sum += page->data;
        page = page->next;
    }while(page != list->cur);
    
    return sum;
}
