#include "my_lib.h"

#include <stdlib.h>

void read_data(struct berkly_head *head, FILE *stream)
{
    weather_data_t *new_rec;
    struct berkly_head *new_node;
    int i = 0;
    while (!feof(stream))
    {
        new_rec = malloc(sizeof(weather_data_t));
        new_node = malloc(sizeof(struct berkly_head));
        
        fscanf(stream, 
               "%d%d%d%d%d",
               &(new_rec->year), &(new_rec->month),
               &(new_rec->day), &(new_rec->maxt),
               &(new_rec->mint));
        
        new_rec->node = new_node;
        i++;
    }
}

void free_data(struct berkly_head *head)
{
    weather_data_t *actual_data;
    struct berkly_head *it;
    struct berkly_head *temp;
    
    list_for_each_safe(it, temp, head)
    {
        actual_data = list_entry(it, weather_data_t, node);
        free(actual_data);
    }
}

void free_nodes(struct berkly_head *head)
{
    struct berkly_head *it;
    struct berkly_head *temp;
    
    list_for_each_safe(it, temp, head)
    {
        free(it);
    }
}

int find_max_tempreture(struct berkly_head *head)
{
    int maxt;
    int actual_maxt;
    int actual_mint;
    struct berkly_head *it;
    struct berkly_head *temp;
    
    maxt = list_entry(head->next, weather_data_t, node)->mint;
    
    list_for_each_safe(it, temp, head)
    {
        actual_maxt = list_entry(it, weather_data_t, node)->maxt;
        actual_mint = list_entry(it, weather_data_t, node)->mint;
        
        if (maxt < actual_maxt)
        {
            maxt = actual_maxt;
        }
        
        if (maxt < actual_mint)
        {
            maxt = actual_mint;
        }
    }
    
    return maxt;
}

int find_min_tempreture(struct berkly_head *head)
{
    int mint;
    int actual_maxt;
    int actual_mint;
    struct berkly_head *it;
    struct berkly_head *temp;
    
    mint = list_entry(head->next, weather_data_t, node)->mint;
    
    list_for_each_safe(it, temp, head)
    {
        actual_maxt = list_entry(it, weather_data_t, node)->maxt;
        actual_mint = list_entry(it, weather_data_t, node)->mint;
        
        if (mint > actual_maxt)
        {
            mint = actual_maxt;
        }
        
        if (mint > actual_mint)
        {
            mint = actual_mint;
        }
    }
    
    return mint;
}
