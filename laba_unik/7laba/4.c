#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct note
{
    char id[16];
    char country[16];
    char city[16];
    char hotelName[16];
    char hotelClass[16];
    char costPerDay[16];
    char roundTripFare[16];
};

const int STRUCT_SIZE = sizeof(struct note);
const int CELL_SIZE = 16;

int check(char *id)
{
    FILE *file = fopen("binary-4", "rb");
    char buf[CELL_SIZE];
    int position = 0;
    while (fread(&buf, CELL_SIZE, 1, file) > 0)
    {
        if (strcmp(id, buf) == 0)
        {
            return position;
        }
        else
        {
            position++;
            fseek(file, STRUCT_SIZE * position, SEEK_SET);
        }
    }
    return -1;
}

void update(char *id)
{
    int position = check(id);
    if (position != -1)
    {
        FILE *file = fopen("binary-4", "r+b");
        struct note currentNote;
        fseek(file, STRUCT_SIZE * position, SEEK_SET);
        char buf[CELL_SIZE];
        printf("id: ");
        scanf("%s", &currentNote.id);
        printf("country: ");
        scanf("%s", &currentNote.country);
        printf("city: ");
        scanf("%s", &currentNote.city);
        printf("hotelName: ");
        scanf("%s", &currentNote.hotelName);
        printf("hotelCLass: ");
        scanf("%s", &currentNote.hotelClass);
        printf("costPerDay: ");
        scanf("%s", &currentNote.costPerDay);
        printf("roundTripFare: ");
        scanf("%s", &currentNote.roundTripFare);
        fwrite(&currentNote, STRUCT_SIZE, 1, file);
        fclose(file);
    }
    else
    {
        printf("no id");
    }
}

void delete(char *id)
{
    int position = check(id);
    if (position != -1)
    {
        FILE *newFile, *oldFile;
        struct note currentNote;
        oldFile = fopen("binary-4", "rb");
        newFile = fopen("binary-4_TEMP", "wb");
        while (fread(&currentNote, STRUCT_SIZE, 1, oldFile) > 0)
        {
            if (strcmp(id, currentNote.id) == 0)
            {
                printf("A record with requested id found and deleted.\n");
            }
            else
            {
                fwrite(&currentNote, STRUCT_SIZE, 1, newFile);
            }
        }
        fclose(oldFile);
        fclose(newFile);
        remove("binary-4");
        rename("binary-4_TEMP", "binary-4");
    }
    else
    {
        printf("no id");
    }
}

void insert()
{
    char buf[CELL_SIZE];
    printf("id: ");
    scanf("%s", &buf);
    int position = check(buf);
    if (position != -1)
    {
        printf("already exists");
    }
    else
    {
        FILE *file = fopen("binary-4", "a+b");
        fseek(file, 0, SEEK_END);
        struct note currentNote;
        strcpy(currentNote.id, buf);
        printf("country: ");
        scanf("%s", &currentNote.country);
        printf("city: ");
        scanf("%s", &currentNote.city);
        printf("hotelName: ");
        scanf("%s", &currentNote.hotelName);
        printf("hotelCLass: ");
        scanf("%s", &currentNote.hotelClass);
        printf("costPerDay: ");
        scanf("%s", &currentNote.costPerDay);
        printf("roundTripFare: ");
        scanf("%s", &currentNote.roundTripFare);
        fwrite(&currentNote, STRUCT_SIZE, 1, file);
        fclose(file);
    }
}

void print(char *id)
{
    int position = check(id);
    if (position != -1)
    {
        FILE *file = fopen("binary-4", "rb");
        struct note currentNote;
        char buf[CELL_SIZE];
        fseek(file, STRUCT_SIZE * position, SEEK_SET);
        fread(&currentNote, STRUCT_SIZE, 1, file);
        printf("id: %s\n", currentNote.id);
        printf("country: %s\n", currentNote.country);
        printf("city: %s\n", currentNote.city);
        printf("hotelName: %s\n", currentNote.hotelName);
        printf("hotelClass: %s\n", currentNote.hotelClass);
        printf("costPerDay: %s\n", currentNote.costPerDay);
        printf("roundTripFare: %s\n", currentNote.roundTripFare);
        fclose(file);
    }
    else
    {
        printf("no id");
    }
}

void printAverageCostOfTheTour(char *class)
{
    FILE *file = fopen("binary-4", "rb");
    struct note currentNote;
    int hotelsAmount = 0;
    int averageCostOfTheTour = 0;
    int currentCostPerDay, currentRoundTripFare;
    while (fread(&currentNote, STRUCT_SIZE, 1, file) > 0)
    {
        if (strcmp(class, currentNote.hotelClass) == 0)
        {
            sscanf(currentNote.costPerDay, "%d", &currentCostPerDay);
            sscanf(currentNote.roundTripFare, "%d", &currentRoundTripFare);
            averageCostOfTheTour += currentCostPerDay * 7 + currentRoundTripFare;
            hotelsAmount++;
        }
    }
    if (hotelsAmount == 0)
    {
        printf("no hotels of this class\n");
    }
    else
    {
        averageCostOfTheTour = averageCostOfTheTour / hotelsAmount;
        printf("average cost of the tour in %s class hotels: %d\n", class, averageCostOfTheTour);
    }
}

void printCheapestHotel(char *class)
{
    FILE *file = fopen("binary-4", "rb");
    struct note currentNote;
    int found = 0;
    int minCostOfLiving = 999999;
    char id[CELL_SIZE];
    int currentCostOfLiving = 0;
    int currentCostPerDay, currentRoundTripFare;
    while (fread(&currentNote, STRUCT_SIZE, 1, file) > 0)
    {
        if (strcmp(class, currentNote.hotelClass) == 0)
        {
            found = 1;
            sscanf(currentNote.costPerDay, "%d", &currentCostPerDay);
            sscanf(currentNote.roundTripFare, "%d", &currentRoundTripFare);
            currentCostOfLiving = currentCostPerDay * 7 + currentRoundTripFare;
            if (currentCostOfLiving < minCostOfLiving)
            {
                minCostOfLiving = currentCostOfLiving;
                strcpy(id, currentNote.id);
            }
        }
    }
    (found == 0) ? printf("no hotels of this class\n") : print(id);
}

int menu()
{
    char choose;
    printf("Select your point: \n\n1 - insert\n2 - update\n3 - delete\n4 - found\n5 - show the cheapest hotel\n6 - show average price\n7 - quite\n\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        insert();
        printf("\n");
    }
    else if (choose == 2)
    {
        char id[CELL_SIZE];
        printf("enter id: ");
        scanf("%s", &id);
        update(id);
        printf("\n");
    }
    else if (choose == 3)
    {
        char id[CELL_SIZE];
        printf("enter id: ");
        scanf("%s", &id);
        delete (id);
        printf("\n");
    }
    else if (choose == 4)
    {
        char id[CELL_SIZE];
        printf("enter id: ");
        scanf("%s", &id);
        print(id);
        printf("\n");
    }
    else if (choose == 5)
    {
        char class[CELL_SIZE];
        printf("enter class: ");
        scanf("%s", &class);
        printCheapestHotel(class);
        printf("\n");
    }
    else if (choose == 6)
    {
        char class[CELL_SIZE];
        printf("enter class: ");
        scanf("%s", &class);
        printAverageCostOfTheTour(class);
        printf("\n");
    }
    else if (choose == 7)
        return 0;
    else
    {
        printf("UNKNOWN COMMAND!\n\n");
        return 0;
    };
    return 1;
}

void main(int argc, char *argv[])
{
    while (menu() != 0)
    {
        menu();
    };
}
