#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string name;
    int quantity;
    float price;
};

std::vector<Item> inventory;

void addItem() {
    Item newItem;
    std::cout << "Enter item name: ";
    std::cin >> newItem.name;
    std::cout << "Enter quantity: ";
    std::cin >> newItem.quantity;
    std::cout << "Enter price: ";
    std::cin >> newItem.price;
    inventory.push_back(newItem);
}

void deleteItem() {
    std::string itemName;
    std::cout << "Enter item name to delete: ";
    std::cin >> itemName;
    for(auto it = inventory.begin(); it != inventory.end(); ++it) {
        if(it->name == itemName) {
            inventory.erase(it);
            std::cout << "Item deleted successfully.\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

void displayInventory() {
    std::cout << "Inventory:\n";
    for(const auto& item : inventory) {
        std::cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << "\n";
    }
}

int main() {
    int choice;
    while(true) {
        std::cout << "\n1. Add Item\n2. Delete Item\n3. Display Inventory\n4. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1: addItem(); break;
            case 2: deleteItem(); break;
            case 3: displayInventory(); break;
            case 4: return 0;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
