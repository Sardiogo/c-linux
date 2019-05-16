#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_structure.h"

/*Implements a dynamic list of names with id's (positive numbers) in which the odd numbers id's are all together at the top of the list and the pairs numbers id's are all together at the bottom of the list.*/

void Init(List **ptr)
{
    *ptr = NULL;
}

void Insert(List **ptr, List *tmp)
{
    List *tmp_aux;
    if (tmp->N % 2 == 1 || *ptr == NULL)
    {
        tmp_aux = (List *)malloc(sizeof(List));
        tmp_aux->N = tmp->N;
        strcpy(tmp_aux->Name, tmp->Name);
        tmp_aux->next = *ptr;
        *ptr = tmp_aux;
    }
    else
        Insert(&(**ptr).next, tmp);
}

int Load(List **L)
{
    List *tmp;
    FILE *fp = fopen("./files/test-in.bin", "rb");
    if (fp == NULL)
    {
        fclose(fp);
        return 0;
    }
    tmp = (List *)malloc(sizeof(List));
    if (tmp == NULL)
    {
        fclose(fp);
        return 0;
    }
    while (fscanf(fp, "%u %[^\n]", &tmp->N, tmp->Name) != EOF)
        Insert(L, tmp);
    free(tmp);
    fclose(fp);
    return 0;
}

int Load_bin(List **L)
{
    List *tmp;
    FILE *fp = fopen("./files/test-out.bin", "rb");
    if (fp == NULL)
    {
        fclose(fp);
        return 0;
    }
    tmp = (List *)malloc(sizeof(List));
    if (tmp == NULL)
    {
        fclose(fp);
        return 0;
    }
    while (!feof(fp))
    {
        fread(&tmp->N, sizeof(tmp->N), 1, fp);
        fread(tmp->Name, sizeof(tmp->Name), 1, fp);
        Insert(L, tmp);
    } 
    free(tmp);
    fclose(fp);
    return 0;
}

int Remove(List **ptr, unsigned int Num)
{
    List *tmp;
    if (*ptr == NULL)
        return 0;
    if ((**ptr).N != Num)
        Remove(&(**ptr).next, Num);
    else
    {
        tmp = *ptr;
        *ptr = (*ptr)->next;
        free(tmp);
    }
    return 0;
}

int Save(List **L)
{
    List *aux =  *L;
    FILE *fp = fopen("./files/test-out.bin", "wb");
    if (fp == NULL)
        return 0;
    do{
        fwrite(&aux->N, sizeof(aux->N), 1, fp);
        fwrite(aux->Name, sizeof(aux->Name), 1, fp);
        aux = aux->next;
    } while(aux != NULL);
    fclose(fp);
    return 0;
}

void List_display(List *list)
{
    if (list == NULL)
        return;
    printf("\t list = %p \n", (void *)list);
    printf("\t %d %s \n", list->N, list->Name);
    printf("\t\t(*list).next\t    %10p\n", (void *)list->next);
    if (list->next != NULL)
    {
        printf("\t\t&(list->next)->next %5p\n", (void *)&(list->next)->next);
        printf("\t\t(list->next)->next  %5p\n\n", (void *)(list->next)->next);
    }
    List_display(list->next);
}
