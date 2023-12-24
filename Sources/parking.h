#ifndef PARKING_H
#define PARKING_H

typedef struct {
    int type;
    const char* description;
} CarTypeInfo;
extern int coin[];
extern int park[4][10];
extern CarTypeInfo carTypesList[];

void CarTypes();
int calcurater(int a);
int Parkspace();
int parkspace2(int a);


#endif