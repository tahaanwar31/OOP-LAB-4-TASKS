#include <iostream>
#include <string>
using namespace std;

class Novel {
    private:
        string bookName;
        float cost;
        int* availableStock;
    
    public:
        Novel() {
            bookName = "Unknown";
            cost = 0.0;
            availableStock = new int(30);
        }
        Novel(string bookName, float cost, int availableStock) {
            this->bookName = bookName;
            this->cost = cost;
            this->availableStock = new int(availableStock);
        }
        Novel(const Novel& source) {
            bookName = source.bookName;
            cost = source.cost;
            availableStock = new int(*source.availableStock);
        }
        void modifyDetails() {
            cout << "Enter new title for Novel " << bookName << ": ";
            getline(cin, bookName);
            cout << "Enter new price: $";
            cin >> cost;
            cin.ignore();
            cout << "Enter new stock quantity: ";
            cin >> *availableStock;
            cin.ignore();
        }
        void buyNovel() {
            if (*availableStock == 0) {
                cout << "Out of stock... Purchase not possible." << endl;
                return;
            }
            int amount;
            cout << "Enter quantity to buy: ";
            cin >> amount;
            if (*availableStock < amount) {
                cout << "Requested quantity exceeds available stock (" << *availableStock << "), cannot purchase Novel " << bookName << endl;
                return;
            }
            int rebate = getDiscount(amount);
            float finalCost = cost * amount * (100 - rebate) / 100.0;
            cout << "Purchasing Novel " << bookName << "..." << endl;
            cout << "Total: $" << finalCost << endl;
            cout << "Discount applied: " << rebate << "%" << endl;
            cout << "Novel " << bookName << " bought." << endl;
            *availableStock -= amount;
            if (*availableStock < 5) {
                cout << "WARNING: LOW STOCK!" << endl;
            }
        }
        int getDiscount(int amount) {
            if(amount > 10) {
                return 10;
            } else if (amount > 5) {
                return 5;
            }
            return 0;
        }
        ~Novel() {
            delete availableStock;
        }
};

int main() {
    
    Novel novel1;
    Novel novel2("C++ Guide", 39.99, 20);
    Novel novel3 = novel2;
    cout << "Updating details for novel1 (default constructor):" << endl;
    novel1.modifyDetails();

    cout << "\nPurchasing novel2 (parameterized constructor):" << endl;
    novel2.buyNovel();

    cout << "\nPurchasing novel3 (copy constructor):" << endl;
    novel3.buyNovel();

    return 0;
}
