#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Item {
public:
    string name;
    double price;
    int quantity;
    Item(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }
    void display() const {
        cout << name << " - $" << price << " - Qty: " << quantity << endl;
    }
};
class Inventory {
private:
    vector<Item> items;
public:
    void add_item(const Item& item) {
        items.push_back(item);
        cout << item.name << " added to the inventory" << endl;
    }
    void remove_item(string item_name) {
        vector<Item> updated_items;
        for (const Item& item : items) {
            if (item.name != item_name) {
                updated_items.push_back(item);
            }
        }
        items = updated_items;
        cout << item_name << " is removed from the inventory" << endl;
    }
    void update_item(string item_name, int new_quantity) {
        for (Item& item : items) {
            if (item.name == item_name) {
                item.quantity = new_quantity;
                cout << item.name << " updated to quantity " << new_quantity << endl;
                return;
            }
        }
    }
    void display_items() const {
        if (items.empty()) {
            cout << "Inventory is empty" << endl;
        } else {
            for (const Item& item : items) {
                item.display();
            }
        }
    }
};
int main() {
    Inventory inventory;
    Item item1("Laptop", 1200, 10);
    Item item2("Headphones", 150, 30);
    inventory.add_item(item1);
    inventory.add_item(item2);
    inventory.display_items();
    return 0;
}