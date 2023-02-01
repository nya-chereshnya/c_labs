#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

char filename[500];

int noCopy(char *new_id){
    FILE *file;
    char id[500];
    file = fopen(filename, "rb");
    fread(&id, sizeof(id), 1, file);

    int check = 0;
    while (id != new_id){
        if (strcmp(new_id, id) == 0) {
            printf("this id already exists!\n");
            check++;
            break;
            }else {break;}
    } 
    if(check == 0){
        // printf("test");
        return 1;
    }
    else{
        return 0;
    }
    fclose(file);
}

void print(){
    FILE *file;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen(filename, "rb");
    fread(&id, sizeof(id), 1, file);
    fread(&to, sizeof(to), 1, file);
    fread(&time, sizeof(time), 1, file);
    fread(&price, sizeof(price), 1, file);
    int res = fread(&seats, sizeof(seats), 1, file);
    int check = 0;
    while (res!=0){
        if (strcmp(num, id) == 0){
            check++;
            break;
        }
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        res = fread(&seats, sizeof(seats), 1, file);
    }
    if (check == 0) printf("NOT FOUND!\n\n");
    else printf("SUCCESS:\nID: %s\nTo: %s\nTime: %s\nPrice: %s\nSeats: %s\n\n", id, to, time, price, seats);
    fclose(file);
}

void insert(int check){
    FILE *file;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("Id: ");
    scanf("%s", &id);
    printf("To: ");
    scanf("%s", &to);
    printf("Time: ");
    scanf("%s", &time);
    printf("Price: ");
    scanf("%s", &price);
    printf("Seats: ");
    scanf("%s", &seats);
    if(noCopy(id) == 1){
        if(check == 0){
            file = fopen(filename, "a+b");
        } else {file = fopen("ftemp", "a+b");}
        fseek(file, 0, SEEK_END);
        fwrite(&id, sizeof(id), 1, file);
        fwrite(&to, sizeof(to), 1, file);
        fwrite(&time, sizeof(time), 1, file);
        fwrite(&price, sizeof(price), 1, file);
        fwrite(&seats, sizeof(seats), 1, file);
        fclose(file);
        printf("DONE!\n\n");
        // printf("id: %s\n", id);
        // printf("to: %s\n", to);
        // printf("time: %s\n", time);
        // printf("price: %s\n", price);
        // printf("seats: %s\n", seats);
    }else {printf("Enter the unique id!\n\n"); fclose(file); insert(check);}
    
}

void delete(){
    FILE *file, *ftemp;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen(filename, "rb");
    ftemp = fopen("ftemp", "w+b");
    fread(&id, sizeof(id), 1, file);
    fread(&to, sizeof(to), 1, file);
    fread(&time, sizeof(time), 1, file);
    fread(&price, sizeof(price), 1, file);
    int res = fread(&seats, sizeof(seats), 1, file);
    if(id != num){
        fwrite(&id, sizeof(id), 1, ftemp);
        fwrite(&to, sizeof(to), 1, ftemp);
        fwrite(&time, sizeof(time), 1, ftemp);
        fwrite(&price, sizeof(price), 1, ftemp);
        fwrite(&seats, sizeof(seats), 1, ftemp);
    }
    while (res!=0){
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        res = fread(&seats, sizeof(seats), 1, file);
        if(strcmp(num, id) == 0){continue;}
        if(res == 0){break;}
        fwrite(&id, sizeof(id), 1, ftemp);
        fwrite(&to, sizeof(to), 1, ftemp);
        fwrite(&time, sizeof(time), 1, ftemp);
        fwrite(&price, sizeof(price), 1, ftemp);
        fwrite(&seats, sizeof(seats), 1, ftemp);
    };
    res = 1;
    rewind(ftemp);
    while (res!=0){
        res = fread(&id, sizeof(id), 1, ftemp);
        if (res == 0){break;}
        printf("id: %s\n", id);
        fread(&to, sizeof(to), 1, ftemp);
        printf("to: %s\n", to);
        fread(&time, sizeof(time), 1, ftemp);
        printf("time: %s\n", time);
        fread(&price, sizeof(price), 1, ftemp);
        printf("price: %s\n", price);
        fread(&seats, sizeof(seats), 1, ftemp);
        printf("seats: %s\n", seats);
    }
    fclose(file);
    fclose(ftemp);
    remove(filename);
    rename("ftemp", filename);
}
void update(){
    FILE *file, *ftemp;
    char id[500], to[500], time[500], price[500], seats[500];
    printf("ID - ");
    char num[500];
    scanf("%s", &num);
    file = fopen(filename, "rb");
    ftemp = fopen("ftemp", "w+b");
    fread(&id, sizeof(id), 1, file);
    fread(&to, sizeof(to), 1, file);
    fread(&time, sizeof(time), 1, file);
    fread(&price, sizeof(price), 1, file);
    int res = fread(&seats, sizeof(seats), 1, file);
    if(id != num){
        fwrite(&id, sizeof(id), 1, ftemp);
        fwrite(&to, sizeof(to), 1, ftemp);
        fwrite(&time, sizeof(time), 1, ftemp);
        fwrite(&price, sizeof(price), 1, ftemp);
        fwrite(&seats, sizeof(seats), 1, ftemp);
    }else{
        fclose(ftemp);
        printf("first edit the flight: \n");
        insert(1);
        ftemp = fopen("ftemp", "a+b");
        fseek(ftemp, 0, SEEK_END);
    }
    while (res!=0){
        fread(&id, sizeof(id), 1, file);
        fread(&to, sizeof(to), 1, file);
        fread(&time, sizeof(time), 1, file);
        fread(&price, sizeof(price), 1, file);
        res = fread(&seats, sizeof(seats), 1, file);
        if(strcmp(num, id) == 0){
            fclose(ftemp);
            printf("second edit the flight: \n");
            insert(1);
            fseek(ftemp, 0, SEEK_END);
            num[0] = -1;
            continue;
        }
        if(res == 0){break;}
        fwrite(&id, sizeof(id), 1, ftemp);
        fwrite(&to, sizeof(to), 1, ftemp);
        fwrite(&time, sizeof(time), 1, ftemp);
        fwrite(&price, sizeof(price), 1, ftemp);
        fwrite(&seats, sizeof(seats), 1, ftemp);
    };
    res = 1;
    rewind(ftemp);
    while (res!=0){
        res = fread(&id, sizeof(id), 1, ftemp);
        if (res == 0){break;}
        printf("id: %s\n", id);
        fread(&to, sizeof(to), 1, ftemp);
        printf("to: %s\n", to);
        fread(&time, sizeof(time), 1, ftemp);
        printf("time: %s\n", time);
        fread(&price, sizeof(price), 1, ftemp);
        printf("price: %s\n", price);
        fread(&seats, sizeof(seats), 1, ftemp);
        printf("seats: %s\n", seats);
    }
    fclose(file);
    fclose(ftemp);
    remove(filename);
    rename("ftemp", filename);
}

int menu(){
    int choose;
    printf("Select your point: \n\n1 - insert\n2 - update\n3 - delete\n4 - found\n5 - quit\n\n");
        scanf("%d", &choose);
        if (choose == 1) insert(0);
        else if (choose == 2) update();
        else if (choose == 3) delete();
        else if (choose == 4) print();
        else if (choose == 5) return 0;
        else {
            printf("UNKNOWN COMMAND!\n\n");
            return 0;
        };
    return 1;
}

void main(int argc, char* argv[]){
    if (argc == 2) strcpy(filename, argv[1]);
    else {
        printf("Input file name! - ");
        scanf("%s", &filename);
    }
    while(menu() != 0){
        menu();
    };
    
}