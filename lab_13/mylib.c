#include "mylib.h"
#include "exit.h"

#include <stdio.h>
#include <stdlib.h>

void read_data(FILE *inputs, struct list_head *head)
{
    exit_code = __EXIT_SUCCESS;

    if ((inputs == NULL) || (head == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    int read_counter;
    weather_data_t *new_record;

    while (!feof(inputs))
    {
        int temp_year;
        int temp_month;
        int temp_day;
        int temp_maxt;
        int temp_mint;

        read_counter = fscanf(inputs, "%d%d%d%d%d", &temp_year, &temp_month, &temp_day,
                                                    &temp_maxt, &temp_mint);

        if (read_counter != 5)
        {
            if (read_counter == EOF)
            {
                break;
            }

            exit_code = __EXIT_READERR;
            return;
        }

        new_record = (weather_data_t*)malloc(sizeof(weather_data_t));

        if (new_record == NULL)
        {
            exit_code = __EXIT_MEMFAIL;
            return;
        }

        new_record->year = temp_year;
        new_record->month = temp_month;
        new_record->day = temp_day;
        new_record->maxt = temp_maxt;
        new_record->mint = temp_mint;

        list_add_tail(&new_record->list, head);
    }
}

void free_data(struct list_head *head)
{
    exit_code = __EXIT_SUCCESS;

    if (head == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    struct list_head *it;
    struct list_head *temp;

    list_for_each_safe(it, temp, head)
    {
        free(list_entry(it, weather_data_t, list));
    }
}

int find_max_temperature(struct list_head *head, int year)
{
    exit_code = __EXIT_SUCCESS;

    if (head == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    int maxt;
    int actual_year;
    int actual_maxt;
    int actual_mint;
    struct list_head *it;
    struct list_head *temp;
    
    maxt = list_entry(head->next, weather_data_t, list)->maxt;
    
    list_for_each_safe(it, temp, head)
    {
        actual_year = list_entry(it, weather_data_t, list)->year;

        if (year <= 0 || year == actual_year)
        {
            actual_maxt = list_entry(it, weather_data_t, list)->maxt;
            actual_mint = list_entry(it, weather_data_t, list)->mint;
            
            if (maxt < actual_maxt)
            {
                maxt = actual_maxt;
            }
            
            if (maxt < actual_mint)
            {
                maxt = actual_mint;
            }
        }
    }
    
    return maxt;
}

int find_min_temperature(struct list_head *head, int year)
{
    exit_code = __EXIT_SUCCESS;

    if (head == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    int mint;
    int actual_year;
    int actual_maxt;
    int actual_mint;
    struct list_head *it;
    struct list_head *temp;
    
    mint = list_entry(head->next, weather_data_t, list)->mint;
    
    list_for_each_safe(it, temp, head)
    {
        actual_year = list_entry(it, weather_data_t, list)->year;

        if (year <= 0 || year == actual_year)
        {
            actual_maxt = list_entry(it, weather_data_t, list)->maxt;
            actual_mint = list_entry(it, weather_data_t, list)->mint;
            
            if (mint > actual_maxt)
            {
                mint = actual_maxt;
            }
            
            if (mint > actual_mint)
            {
                mint = actual_mint;
            }
        }
    }
    
    return mint;
}

void log_temperature_dif(struct list_head *head)
{
    exit_code = __EXIT_SUCCESS;

    if (head == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    int present_year;
    int previos_year;
    int temperature_dif;
    struct list_head *it;

    previos_year = -1;

    list_for_each(it, head)
    {
        present_year = list_entry(it, weather_data_t, list)->year;

        if (present_year != previos_year)
        {
            temperature_dif = find_max_temperature(head, present_year) - find_min_temperature(head, present_year);
            fprintf(stdout, "%d %d\n", present_year, temperature_dif);
        }

        previos_year = present_year;
    }
}
