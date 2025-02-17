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
            if(*availableStock <= 0) {
                cout << "Out of stock... Purchase not possible" << endl;
            }
            else {
                (*availableStock)--;
                cout << "Novel " << bookName << " bought!" << endl;
                if(*availableStock < 5) {
                    cout << "WARNING: LOW STOCK!" << endl; 
                }
            }
        }
};

int main() {
    Novel thisNovel;
    thisNovel.modifyDetails();
    thisNovel.buyNovel();
}
