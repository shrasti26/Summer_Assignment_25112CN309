#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILENAME "inventory.dat"

// Structure to define an inventory item
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Global array to hold items and current item count
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function declarations
void loadInventory();
void saveInventory();
void addItem();
void viewInventory();
void updateItem();
void deleteItem();
void searchItem();
void clearInputBuffer();

int main() {
    int choice;

    // Load existing items from the data file at startup
    loadInventory();

    do {
        printf("\n===================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM    \n");
        printf("===================================\n");
        printf("1. Add New Item\n");
        printf("2. View All Items\n");
        printf("3. Update Stock/Price\n");
        printf("4. Delete Item\n");
        printf("5. Search Item\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: searchItem(); break;
            case 6: 
                saveInventory(); 
                printf("Inventory saved successfully. Goodbye!\n"); 
                break;
            default: printf("Invalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Loads the binary file data into the system memory array
void loadInventory() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        // File doesn't exist yet, which is expected on the first run
        itemCount = 0;
        return;
    }
    
    // Read elements sequentially into the inventory array
    itemCount = fread(inventory, sizeof(Item), MAX_ITEMS, file);
    fclose(file);
}

// Saves all items in the array back down into the file
void saveInventory() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    
    fwrite(inventory, sizeof(Item), itemCount, file);
    fclose(file);
}

// Clears the buffer to fix newline skips with scanf/fgets combinations
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a brand new unique item to the inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("\nEnter Item ID (Integer): ");
    scanf("%d", &newItem.id);

    // Verify if Item ID already exists
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: An item with ID %d already exists!\n", newItem.id);
            return;
        }
    }

    clearInputBuffer();
    printf("Enter Item Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

// Displays all stored items in a scannable grid format
void viewInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n", "Item ID", "Item Name", "Quantity", "Price ($)");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-10d %-10.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Updates an existing item's quantity or price
void updateItem() {
    int id, found = 0;
    printf("\nEnter the Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Current Details - Name: %s | Qty: %d | Price: %.2f\n", 
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            
            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

// Deletes an item from memory and shifts subsequent items backward
void deleteItem() {
    int id, found = 0;
    printf("\nEnter the Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            // Shift elements left to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

// Searches an item via ID or Name string pattern match
void searchItem() {
    int choice;
    printf("\nSearch by:\n1. Item ID\n2. Item Name\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id, found = 0;
        printf("Enter Item ID: ");
        scanf("%d", &id);
        
        for (int i = 0; i < itemCount; i++) {
            if (inventory[i].id == id) {
                printf("\nFound: ID: %d | Name: %s | Qty: %d | Price: $%.2f\n", 
                       inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                found = 1;
                break;
            }
        }
        if (!found) printf("Item not found.\n");

    } else if (choice == 2) {
        char name[50];
        int found = 0;
        clearInputBuffer();
        printf("Enter Item Name (or part of it): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        for (int i = 0; i < itemCount; i++) {
            if (strstr(inventory[i].name, name) != NULL) { // Case-sensitive partial match
                printf("\nFound: ID: %d | Name: %s | Qty: %d | Price: $%.2f\n", 
                       inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                found = 1;
            }
        }
        if (!found) printf("No items matching that name were found.\n");
    } else {
        printf("Invalid selection.\n");
    }
}
