#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[20];
    int strength;
    int agility;
    int health;
} Fighter;

void initializeFighter(Fighter *fighter, const char *name) {
    strcpy(fighter->name, name);
    fighter->strength = rand() % 101;
    fighter->agility = rand() % 101;
    fighter->health = rand() % 101;
}

void printFighter(Fighter fighter) {
    printf("Tên: %s, Sức mạnh: %d, Nhanh nhẹn: %d, Máu: %d\n", 
           fighter.name, fighter.strength, fighter.agility, fighter.health);
}

Fighter battle(Fighter *fighter1, Fighter *fighter2) {
    int score1 = fighter1->strength + fighter1->agility + fighter1->health;
    int score2 = fighter2->strength + fighter2->agility + fighter2->health;

    if (score1 > score2) {
        fighter1->strength *= 1.02;
        fighter1->agility *= 1.02;
        fighter1->health *= 1.02;
        fighter2->strength *= 1.01;
        fighter2->agility *= 1.01;
        fighter2->health *= 1.01;
        return *fighter1;
    } else {
        fighter1->strength *= 1.01;
        fighter1->agility *= 1.01;
        fighter1->health *= 1.01;
        fighter2->strength *= 1.02;
        fighter2->agility *= 1.02;
        fighter2->health *= 1.02;
        return *fighter2;
    }
}

int main() {
    srand(time(NULL));
    Fighter fighters[3];

    initializeFighter(&fighters[0], "Đấu thủ 1");
    initializeFighter(&fighters[1], "Đấu thủ 2");
    initializeFighter(&fighters[2], "Đấu thủ 3");

    for (int i = 0; i < 3; i++) {
        printf("Trận đấu giữa %s và %s:\n", fighters[i].name, fighters[(i + 1) % 3].name);
        Fighter winner = battle(&fighters[i], &fighters[(i + 1) % 3]);
        printf("Người thắng: %s\n\n", winner.name);
    }

    printf("Chỉ số cuối cùng của các đấu thủ:\n");
    for (int i = 0; i < 3; i++) {
        printFighter(fighters[i]);
    }

    return 0;
}