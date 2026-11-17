#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void add_item(Item **list, int *count, int *capacity) {
    if (*count == *capacity) {
        int new_capacity = *capacity * 2;
        Item *temp = realloc(*list, (size_t)new_capacity * sizeof(Item));
        if (temp == NULL) {
            printf("Error: Memory allocation failed during realloc!\n");
            return;
        }
        *list = temp;
        *capacity = new_capacity;
    }

    while (getchar() != '\n');

    printf("Enter item name: ");
    if (fgets((*list)[*count].name, sizeof((*list)[*count].name), stdin) != NULL) {
        size_t len = strlen((*list)[*count].name);
        if (len > 0 && (*list)[*count].name[len - 1] == '\n') {
            (*list)[*count].name[len - 1] = '\0';
        }
    }

    printf("Enter unit price: ");
    scanf("%f", &(*list)[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &(*list)[*count].quantity);

    (*count)++;
    printf("Item added successfully! Current Count: %d, Current Capacity: %d\n", *count, *capacity);
}

float compute_total(Item *list, int count) {
    float grand_total = 0.0f;
    for (int i = 0; i < count; i++) {
        grand_total += list[i].price * (float)list[i].quantity;
    }
    return grand_total;
}

void display_list(Item *list, int count) {
    if (count == 0) {
        printf("\nThe shopping list is currently empty.\n");
        return;
    }

    printf("\n===== Shopping List =====\n");
    printf("%-3s  %-15s  %-5s  %-8s  %-8s\n", "No", "Item", "Qty", "Price", "Total");
    for (int i = 0; i < count; i++) {
        float line_total = list[i].price * (float)list[i].quantity;
        printf("%-3d  %-15s  %-5d  ₹%-7.2f  ₹%-8.2f\n", 
               i + 1, list[i].name, list[i].quantity, list[i].price, line_total);
    }
    printf("--------------------------------------------------\n");
    printf("Grand Total            ₹%.2f\n", compute_total(list, count));
    printf("==================================================\n");
}

void remove_item(Item *list, int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("Error: Invalid index!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        list[i] = list[i + 1];
    }
    (*count)--;
    printf("Item removed successfully.\n");
}

void clear_list(Item **list, int *count, int *capacity) {
    free(*list);
    *capacity = 2;
    *list = malloc((size_t)*capacity * sizeof(Item));
    if (*list == NULL) {
        printf("Error: Memory allocation failed in clear_list!\n");
        exit(1);
    }
    *count = 0;
    printf("Shopping list cleared.\n");
}

int main(void) {
    int capacity = 2;
    int count = 0;
    float total_spent_session = 0.0f;

    Item *list = malloc((size_t)capacity * sizeof(Item));
    if (list == NULL) {
        printf("Error: Initial memory allocation failed!\n");
        return 1;
    }

    int choice;
    do {
        printf("\n===== Shopping List Menu =====\n");
        printf("1. Add Item\n");
        printf("2. View List\n");
        printf("3. Remove Item\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                add_item(&list, &count, &capacity);
                break;
            case 2:
                display_list(list, count);
                break;
            case 3:
                if (count == 0) {
                    printf("List is empty. Nothing to remove.\n");
                } else {
                    display_list(list, count);
                    int item_no;
                    printf("Enter item number to remove (1 to %d): ", count);
                    scanf("%d", &item_no);
                    remove_item(list, &count, item_no - 1);
                }
                break;
            case 4:
                clear_list(&list, &count, &capacity);
                break;
            case 5:
                total_spent_session = compute_total(list, count);
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    free(list);
    printf("Total amount spent in this session: ₹%.2f\n", total_spent_session);
    printf("Goodbye!\n");

    return 0;
}