#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CarModel {
    char name[50];
    float price;
    char manufacturer[50];
    float engineCapacity;
    struct CarModel* next;
    struct CarModel* prev;
};

void insertCarModel(struct CarModel** head, char name[], float price, char manufacturer[], float engineCapacity);
void deleteCarModel(struct CarModel** head, char name[]);
void updateCarModelPrice(struct CarModel* head, char name[], float newPrice);
void listCarModelsInRange(struct CarModel* head, float minPrice, float maxPrice);
void listAllCarModels(struct CarModel* head);
void freeCarModelList(struct CarModel* head);

int main() {
    struct CarModel* head = NULL;
    int choice;
    char name[50];
    float price, minPrice, maxPrice;
    char manufacturer[50];
    float engineCapacity;

    do {
        printf("\nCar Model Management System\n");
        printf("1. Insert new car model\n");
        printf("2. Delete car model\n");
        printf("3. Update car model price\n");
        printf("4. List car models in price range\n");
        printf("5. List all car models\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter car model details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Price: ");
                scanf("%f", &price);
                printf("Manufacturer: ");
                scanf("%s", manufacturer);
                printf("Engine Capacity: ");
                scanf("%f", &engineCapacity);
                insertCarModel(&head, name, price, manufacturer, engineCapacity);
                printf("Car model added successfully.\n");
                break;
            case 2:
                printf("Enter the name of the car model to delete: ");
                scanf("%s", name);
                deleteCarModel(&head, name);
                printf("Car model deleted successfully.\n");
                break;
            case 3:
                printf("Enter the name of the car model to update price: ");
                scanf("%s", name);
                printf("Enter the new price: ");
                scanf("%f", &price);
                updateCarModelPrice(head, name, price);
                printf("Car model price updated successfully.\n");
                break;
            case 4:
                printf("Enter the minimum and maximum prices separated by space: ");
                scanf("%f %f", &minPrice, &maxPrice);
                listCarModelsInRange(head, minPrice, maxPrice);
                break;
            case 5:
                listAllCarModels(head);
                break;
            case 6:
                freeCarModelList(head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void insertCarModel(struct CarModel** head, char name[], float price, char manufacturer[], float engineCapacity) {
    struct CarModel* newModel = (struct CarModel*)malloc(sizeof(struct CarModel));
    strcpy(newModel->name, name);
    newModel->price = price;
    strcpy(newModel->manufacturer, manufacturer);
    newModel->engineCapacity = engineCapacity;
    newModel->next = NULL;

    if (*head == NULL) {

        newModel->prev = NULL;
        *head = newModel;
    } else {
        struct CarModel* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

    
        temp->next = newModel;
        newModel->prev = temp;
    }
}

// Function to delete a car model with a given name
void deleteCarModel(struct CarModel** head, char name[]) {
    struct CarModel* current = *head;
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Car model not found.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
     
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void updateCarModelPrice(struct CarModel* head, char name[], float newPrice) {
    struct CarModel* current = head;
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Car model not found.\n");
        return;
    }

    current->price = newPrice;
}
void listCarModelsInRange(struct CarModel* head, float minPrice, float maxPrice) {
    struct CarModel* current = head;
    int found = 0;

    printf("\nCar models in the price range %.2f - %.2f:\n", minPrice, maxPrice);

    while (current != NULL) {
        if (current->price >= minPrice && current->price <= maxPrice) {
            printf("Name: %s, Price: %.2f, Manufacturer: %s, Engine Capacity: %.2f\n",
                   current->name, current->price, current->manufacturer, current->engineCapacity);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No car models found in the specified price range.\n");
    }
}
void listAllCarModels(struct CarModel* head) {
    struct CarModel* current = head;

    printf("\nAll car models:\n");

    while (current != NULL) {
        printf("Name: %s, Price: %.2f, Manufacturer: %s, Engine Capacity: %.2f\n",
               current->name, current->price, current->manufacturer,

 current->engineCapacity);
        current = current->next;
    }

    if (head == NULL) {
        printf("No car models available.\n");
    }
}


void freeCarModelList(struct CarModel* head) {
    struct CarModel* current = head;
    struct CarModel* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}