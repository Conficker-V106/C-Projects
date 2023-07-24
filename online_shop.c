#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CART_ITEMS 100

struct Product {
    int productId;
    char name[MAX_NAME_LENGTH];
    double price;
};

struct CartItem {
    int productId;
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
};

void displayProducts(struct Product* products, int numProducts) {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product ID: %d, Name: %s, Price: %.2lf\n", products[i].productId, products[i].name, products[i].price);
    }
}

int findProductById(struct Product* products, int numProducts, int productId) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].productId == productId) {
            return i;
        }
    }
    return -1;
}

int findCartItemById(struct CartItem* cart, int numItems, int productId) {
    for (int i = 0; i < numItems; i++) {
        if (cart[i].productId == productId) {
            return i;
        }
    }
    return -1;
}

void addToCart(struct Product* products, int numProducts, struct CartItem* cart, int* numItems, int productId, int quantity) {
    int productIndex = findProductById(products, numProducts, productId);
    if (productIndex == -1) {
        printf("Product with ID %d not found.\n", productId);
        return;
    }

    if (*numItems >= MAX_CART_ITEMS) {
        printf("Your cart is full. Remove some items to add more.\n");
        return;
    }

    int cartIndex = findCartItemById(cart, *numItems, productId);
    if (cartIndex != -1) {
        cart[cartIndex].quantity += quantity;
    } else {
        struct CartItem newItem;
        newItem.productId = products[productIndex].productId;
        strncpy(newItem.name, products[productIndex].name, MAX_NAME_LENGTH);
        newItem.price = products[productIndex].price;
        newItem.quantity = quantity;
        cart[*numItems] = newItem;
        (*numItems)++;
    }

    printf("Product added to cart.\n");
}

// Rest of the code remains the same


void displayCart(struct CartItem* cart, int numItems) {
    printf("\nYour Cart:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Product ID: %d, Name: %s, Price: %.2lf, Quantity: %d\n", cart[i].productId, cart[i].name, cart[i].price, cart[i].quantity);
    }
}

double calculateTotal(struct CartItem* cart, int numItems) {
    double total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

void generateReceipt(struct CartItem* cart, int numItems) {
    printf("\n--- Receipt ---\n");
    displayCart(cart, numItems);
    double total = calculateTotal(cart, numItems);
    printf("Total Amount: %.2lf\n", total);
    printf("----------------\n");
}

void loadProductsFromFile(struct Product** products, int* numProducts) {
    FILE* file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("No data found.\n");
        return;
    }

    while (!feof(file)) {
        struct Product newProduct;
        if (fscanf(file, "%d %s %lf\n", &newProduct.productId, newProduct.name, &newProduct.price) == 3) {
            (*numProducts)++;
            *products = (struct Product*)realloc(*products, (*numProducts) * sizeof(struct Product));
            (*products)[(*numProducts) - 1] = newProduct;
        }
    }

    fclose(file);
}

void freeMemory(struct Product* products, struct CartItem* cart) {
    free(products);
    free(cart);
}

int main() {
    struct Product* products = NULL;
    struct CartItem* cart = NULL;
    int numProducts = 0;
    int numItems = 0;
    int choice;
    int productId, quantity;

    loadProductsFromFile(&products, &numProducts);
    cart = (struct CartItem*)malloc(MAX_CART_ITEMS * sizeof(struct CartItem));

    while (1) {
        printf("\nOnline Shopping System\n");
        printf("1. Display Products\n");
        printf("2. Add to Cart\n");
        printf("3. Display Cart\n");
        printf("4. Calculate Total\n");
        printf("5. Generate Receipt\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayProducts(products, numProducts);
                break;
            case 2:
                printf("Enter Product ID and Quantity to add to cart (separated by space): ");
                scanf("%d %d", &productId, &quantity);
                addToCart(products, numProducts, cart, &numItems, productId, quantity);
                break;
            case 3:
                displayCart(cart, numItems);
                break;
            case 4: {
                double total = calculateTotal(cart, numItems);
                printf("Total Amount: %.2lf\n", total);
                break;
            }
            case 5:
                generateReceipt(cart, numItems);
                break;
            case 6:
                freeMemory(products, cart);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
