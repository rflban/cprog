#include <stdio.h>
#include <stdlib.h>

#include "my_lib.h"


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    FILE *inputf;
    struct berkly_head *head_data;
    
    inputf = fopen(argv[2], "r");
    if (inputf == NULL)
    {
        printf("Open error.\n");
        return EXIT_FAILURE;
    }
    
    head_data = malloc(sizeof(struct berkly_head));
    INIT_LIST_HEAD(head_data);
    
    read_data(head_data, inputf);
    
    printf("%d\n",list_entry(head_data->next, weather_data_t, year)->mint);
    
    printf("%d\n", find_max_tempreture(head_data) - find_min_tempreture(head_data));
    
    free_data(head_data);
    free_nodes(head_data);
    
    free(head_data);
    
    return EXIT_SUCCESS;
}
