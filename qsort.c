#include <assert.h>

#include <stdbool.h>

#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>


//定義節點
typedef struct node{

        struct node *left,*right;

        struct node *next;

        long value;

}node_t;

//在list的頭新增一個節點
void list_add(node_t **list,node_t * node){

        node->next=*list;

        *list=node;

}
//獲取list的最後一個節點
node_t *list_tail(node_t **left){

        while((*left)&&(*left)->next){

                left=&((*left)->next);//get next pointer to pointer left 

        }
        return *left;
}
//list的長度
int list_length(node_t **left){

        int n=0;

        while(*left){

                ++n;

                left=&((*left)->next);

        }

        return n;

}

node_t *list_construct(node_t *list,int n){

        node_t *node=malloc(sizeof(node_t));

        node->next=list;

        node->value=n;

        return node;


}

//釋放list空間
void list_free(node_t **list){

        node_t *node=(*list)->next;

        while(*list){

                free(*list);

                *list=node;

                if(node){

                    node=node->next;

                }

        }

}
//確認list中的節點數值是否有按照由小到大的順序
static bool list_is_ordered(node_t *list){

        bool first=true;

        int value;

        while(list){

                if(first){

                    value=list->value;

                    first=false;

                }
                else{

                    if(list->value<value){

                        return false;

                    }

                    value=list->value;

                }

                list=list->next;

        }

        return true;

}

//隨機賦值
void shuffle(int *arr,size_t n){
        if(n<=0){

            return;

        }
    
        for(size_t i=0;i<n-1;i++){
            
                size_t j=i+rand()/(RAND_MAX/(n-i)+1);

                int t=arr[j];

                arr[j]=arr[i];

                arr[i]=t;

        }

}
//非遞迴quick_sort
void quick_sort(node_t **list)
{
    int n = list_length(list);
    int value;
    int i = 0;
    int max_level = 2 * n;
    node_t *begin[max_level], *end[max_level];
    node_t *result = NULL, *left = NULL, *right = NULL;

    begin[0] = *list;
    end[0] = list_tail(list);

    while (i >= 0) {
        node_t *L = begin[i], *R = end[i];
        if (L != R) {
            node_t *pivot = L;
            value = pivot->value;
            node_t *p = pivot->next;
            pivot->next = NULL;

            while (p) {
                node_t *n = p;
                p = p->next;
                list_add(n->value > value ? &right : &left, n);
            }

            begin[i] = left;
            end[i] = list_tail(&left); // Update end for left sub-list
            begin[i + 1] = pivot->next;
            end[i + 1] = pivot->next ? list_tail(&pivot->next) : NULL; // Update end for pivot
            begin[i + 2] = right;
            end[i + 2] = list_tail(&right); // Update end for right sub-list

            left = right = NULL;
            i += 2;
        } else {
            if (L)
                list_add(&result, L);
            i--;
        }
    }

    *list = result;
}


void print_list(node_t *list){
    node_t *temp=list;
    while(temp!=NULL){
        printf("%ld ",temp->value);
        temp=temp->next;
    }
    printf("\n");
    
}

int main(){

        node_t *list=NULL;

        size_t count=20;

        int *test_arr=malloc(sizeof(int)*count);

        for(int i=0;i<count;++i){

                test_arr[i]=i;

        }
    
        shuffle(test_arr,count);
        

        while(count--){

                list=list_construct(list,test_arr[count]);
        }
        print_list(list);
    

        quick_sort(&list);
        assert(list_is_ordered(list));

        print_list(list);

      


        list_free(&list);

        free(test_arr);


        return 0;

}



