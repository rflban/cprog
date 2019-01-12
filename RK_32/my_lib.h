#ifndef _MY_LIB_H
#define _MY_LIB_H

#include <stdio.h>
#include "list.h"

typedef struct __weather_data_t weather_data_t;

struct __weather_data_t
{
    int year;
    int month;
    int day;
    int maxt;
    int mint;
    
    struct berkly_head *node;
};

void read_data(struct berkly_head *head, FILE *stream);
void free_data(struct berkly_head *head);
void free_nodes(struct berkly_head *head);

int find_max_tempreture(struct berkly_head *head);
int find_min_tempreture(struct berkly_head *head);

#endif /*_MY_LIB_H*/