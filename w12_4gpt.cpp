#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double power;
    double agility;
    double hp;
} Fighter;

// tính tổng chỉ số
double total(Fighter f) {
    return f.power + f.agility + f.hp;
}

// tăng chỉ số theo %
void increase(Fighter *f, double percent) {
    f->power += f->power * percent / 100;
    f->agility += f->agility * percent / 100;
    f->hp += f->hp * percent / 100;
}

// cộng bonus random
void bonus(Fighter *f) {
    double b = rand() % 5; // 0 -> 4 %
    increase(f, b);
}

// đấu 2 người
Fighter* arena(Fighter *a, Fighter *b) {
    if (total(*a) > total(*b)) {
        increase(a, 2);
        increase(b, 1);
        bonus(a);
        bonus(b);
        return a;
    } else {
        increase(b, 2);
        increase(a, 1);
        bonus(a);
        bonus(b);
        return b;
    }
}

// tạo random fighter
Fighter createFighter() {
    Fighter f;
    f.power = rand() % 101;
    f.agility = rand() % 101;
    f.hp = rand() % 101;
    return f;
}

// in thông tin
void printFighter(Fighter f, int id) {
    printf("Fighter %d: P=%.2lf A=%.2lf HP=%.2lf Total=%.2lf\n",
           id, f.power, f.agility, f.hp, total(f));
}

int main() {
    srand(time(NULL));

    Fighter f1 = createFighter();
    Fighter f2 = createFighter();
    Fighter f3 = createFighter();

    int n;
    printf("Nhap so vong: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Vong %d ---\n", i+1);

        arena(&f1, &f2);
        arena(&f2, &f3);
        arena(&f3, &f1);
    }

    printf("\n=== Ket qua cuoi ===\n");
    printFighter(f1, 1);
    printFighter(f2, 2);
    printFighter(f3, 3);

    return 0;
}