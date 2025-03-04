#include <stdio.h>+
int N;
void display_forks() {
    printf("\n Philosopher   Right Fork   Left Fork");
    printf("\n-------------------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("     %d            %d               %d\n", i, i, (i + 1) % N);
    }
    printf("-------------------------------------\n");
}
void eat(int p1, int p2) {
    printf("\nRound 1\n--------------------------\n");
    printf("Philosopher %d is eating with rhf=%d and lhf=%d.\n", p1, p1, (p1 + 1) % N);
    printf("Philosopher %d is eating with rhf=%d and lhf=%d.\n", p2, p2, (p2 + 1) % N);
    int eaten[N];
    for (int i = 0; i < N; i++) eaten[i] = 0;
    eaten[p1] = 1;
    eaten[p2] = 1;
    int next_p1 = -1, next_p2 = -1;
    for (int i = 0; i < N; i++) {
        if (!eaten[i]) {
            if (next_p1 == -1) {
                next_p1 = i;
                eaten[i] = 1;
            } else {
                next_p2 = i;
                eaten[i] = 1;
                break;
            }
        }
    }
    printf("\nRound 2\n--------------------------\n");
    printf("Philosopher %d is eating with rhf=%d and lhf=%d.\n", next_p1, next_p1, (next_p1 + 1) % N);
    printf("Philosopher %d is eating with rhf=%d and lhf=%d.\n", next_p2, next_p2, (next_p2 + 1) % N);
    int last_philosopher = -1;
    for (int i = 0; i < N; i++) {
        if (!eaten[i]) {
            last_philosopher = i;
            break;
        }
    }
    if (last_philosopher != -1) {
        printf("\nRound 3\n--------------------------\n");
        printf("Philosopher %d is eating with rhf=%d and lhf=%d.\n", last_philosopher, last_philosopher, (last_philosopher + 1) % N);
    }
}
int main() {
    int p1, p2;
    printf("Enter the number of philosophers: ");
    scanf("%d", &N);
    if (N < 3) {
        printf("\nInvalid number of philosophers! Please enter 3 or more.\n");
        return 1;
    }
    display_forks();
    printf("\nEnter the Two Eating Philosophers number: ");
    scanf("%d %d", &p1, &p2);
    if (p1 == p2 || p1 < 0 || p2 < 0 || p1 >= N || p2 >= N) {
        printf("\nInvalid philosopher numbers! Please enter two different numbers between 0 and %d.\n", N - 1);
        return 1;
    }
    if (p2 == (p1 + 1) % N || p1 == (p2 + 1) % N) {
        printf("\nError: The selected philosophers are adjacent! Please choose non-adjacent philosophers.\n");
        return 1;
    }
    eat(p1, p2);
    return 0;
}

