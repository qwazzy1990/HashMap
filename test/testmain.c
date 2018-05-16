#include <stdio.h>
#include <stdlib.h>
#include "../../../String/include/String.h"
#include "..//include/HashMap.h"
#include "../../../utilities/include/utilities.h"
#include <stdbool.h>
#include <assert.h>

bool debug1 = false;
bool debug2 = true;
bool debug3 = false;
bool debug4 = false;
bool debug5 = false;
bool debug6 = false;
bool debug7 = false;

struct pair{
    char* key;
    int value;
};typedef struct pair Pair;

char* print_pair(AnyData a)
{
    Pair* p = (Pair*)a;
    char* printer = stringcopy(p->key);
    char* v = tostring(INT, &(p->value));
    printer = stringcat(printer, " ");
    printer = stringcat(printer, v);
    destroystring(v);
    return printer;
}

int compareInts(AnyData a, AnyData b)
{
    int* k = (int*)a;
    int* j = (int*)b;
    if(*k < *j)return -1;
    else if(*k > *j)return 1;
    else return 0;
}

void delete_pair(AnyData d)
{
    Pair* p = (Pair*)d;
    assert(p->key != NULL);
    assert(stringlen(p->key) > 0);
    assert(badstring(p->key)==false);
    destroystring(p->key);
    free(p);
}

int main(int argc, char* argv[])
{
    if(debug1){
        HashMap map = new_hashmap(print_pair, delete_pair, 7);
        printf("%d\n", map->tableSize);
        printf("%d\n", map->size);
        destroy_hashmap(map);

    }
    if(debug2){
        Pair** pairs = (Pair**)calloc(10, sizeof(Pair*));
        for(int i = 0; i < 10; i++){
            pairs[i] = (Pair*)calloc(1, sizeof(Pair));
            pairs[i]->key = stringcopy("Balls");
            char* f = tostring(INT, &i);
            pairs[i]->key = stringcat(pairs[i]->key, f);
            destroystring(f);
            pairs[i]->value = i;
            
        }
        HashMap map = new_hashmap(print_pair, delete_pair, 1);
        for(int i = 0; i < 7; i++){
            char* key = stringcopy(pairs[i]->key);
            ErrorCode status = put_hashmap(map, key, pairs[i]);
            print_error_code(status);
            if(status != OK){
                printf("%d\n", i);
                printf("%d\n", status);
            }
        }
        char* k = stringcopy(pairs[8]->key);
        ErrorCode status = put_hashmap(map, k, pairs[8]);
        destroystring(k);
        print_error_code(status);
        char* s = map_to_string(map);
        printf("%s\n", s);
        destroystring(s);
        printf("Please enter a password\n");
        char scan[100];
        scanf("%s", scan);
        remove_hard_return(scan);
        AnyData test = NULL;
        ErrorCode found = get_hashmap(map, scan, &test);
        print_error_code(found);
        found = remove_from_hashmap(map, scan);
        print_error_code(found);
        found = destroy_hashmap(map);
        print_error_code(found);
        free(pairs);

    }

        
    return 0;
}


