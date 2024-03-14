#include <stdio.h>
int main() {
    // FILE OPEN
    FILE *file = fopen("input.txt", "r");
    if(file) {
        printf("File is opened!");
        int balance, amount;
        fscanf(file, "%d", &balance);
        fclose(file);
        FILE *file = fopen("input.txt", "a");
        printf("Enter what amount you withdraw: ");
        scanf("%d", &amount);
        if(amount <= balance) {
            balance = balance - amount;
            fprintf(file, "\n%d %d", balance, amount);
            fclose(file);
        } else {
            printf("Amount must be less than balance.");
        }
    } else {
        printf("File is not opened!");
    }

    return 0;
}