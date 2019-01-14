#ifndef __MYLIB_H
#define __MYLIB_H

#include <stddef.h>
#include <bits/types/FILE.h>

#include "list.h"

typedef struct weather_data_t
{
    int year;
    int month;
    int day;
    int maxt;
    int mint;

    struct list_head list;
}
weather_data_t;

int find_max_temperature(struct list_head *head, int year);
int find_min_temperature(struct list_head *head, int year);

void read_data(FILE *inputs, struct list_head *head);
void free_data(struct list_head *head);
void log_temperature_dif(struct list_head *head);

#endif /*__MYLIB_H*/
