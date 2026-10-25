// COMSC-210 | Lab 27 | Jeremy Laudencia

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

const int FRIENDSHIP = 0;
const int SPECIES = 1;
const int CATCHPHRASE = 2;
const int IGNORE_SIZE = 10000;

int displayMenu();
void searchVillager(map<string, tuple<int, string, string>>& villagerData);
void addVillager(map<string, tuple<int, string, string>>& villagerData);
void deleteVillager(map<string, tuple<int, string, string>>& villagerData);
void increaseFriendship(map<string, tuple<int, string, string>>& villagerData);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerData);
void displayVillagers(map<string, tuple<int, string, string>>& villagerData);

int main() {
    // declarations
    int input;
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = {5, "Orc", "Me not cyclops, me orc!"};
    villagerData["Raymond"] = {3, "Wolf", "I did not eat those sheep!"};
    villagerData["Marshal"] = {7, "Reptile", "I'm totally a normal human!"};

    displayVillagers(villagerData);

    int choice = 0;
    while(choice != 6){
        choice = displayMenu();
        if(choice == 1)
            addVillager(villagerData);
        else if(choice == 2)
            deleteVillager(villagerData);
        else if(choice == 3)
            increaseFriendship(villagerData);
        else if(choice == 4)
            decreaseFriendship(villagerData);
        else if(choice == 5)
            searchVillager(villagerData);
        else if(choice == 6)
            cout << "Exitting Villager Simulator... " << endl;
        else
            cout << "Invalid choice. Pick from the displayed choices." << endl;

        if(choice >= 1 && choice <= 5)
            displayVillagers(villagerData);
    }

    // BELOW IS FROM DEMO CODE

    // access the map using a range-based for loop
    // cout << "Villagers details:" << endl;
    // for (auto pair : villagerData) {
    //     cout << pair.first << " [";
    //         cout << get<FRIENDSHIP>(pair.second) << ", ";
    //         cout << get<SPECIES>(pair.second) << ", ";
    //         cout << get<CATCHPHRASE>(pair.second) << "] " << endl;
    // }

    // // access the map using iterators
    // cout << "\nVillagers details (iterators):" << endl;
    // for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
    //                                            it != villagerData.end(); ++it) {
    //     cout << it->first << " [";
    //         cout << get<FRIENDSHIP>(it->second) << ", ";
    //         cout << get<SPECIES>(it->second) << ", ";
    //         cout << get<CATCHPHRASE>(it->second) << "] " << endl;
    // }

    // delete an element
    // villagerData.erase("Raymond");

    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerData.size() << endl;
    // villagerData.clear();
    // cout << "Size after clear: " << villagerData.size() << endl;

    // END OF DEMO CODE



    return 0;
}

void searchVillager(map<string, tuple<int, string, string>>& villagerData){
    // search for an element using .find() to avoid errors
    string searchKey;
    cout << "What villager to search for?: ";
    cin >> searchKey;
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s Data: " << endl;
            cout << "    Friendship Level: " << get<FRIENDSHIP>(it->second) <<  endl;
            cout << "    Species: " << get<SPECIES>(it->second) <<  endl;
            cout << "    Catchphrase: " << get<CATCHPHRASE>(it->second) << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

}

void deleteVillager(map<string, tuple<int, string, string>>& villagerData){
    string deleteKey;
    cout << "What villager to remove from village?: ";
    cin >> deleteKey;
    auto it = villagerData.find(deleteKey);
    if(it != villagerData.end()){
        villagerData.erase(deleteKey);
        cout << deleteKey << " removed from village. Sorry to see you go, " << deleteKey << endl;
    }
    else
        cout << deleteKey << " cannot be found." << endl;
}

void increaseFriendship(map<string, tuple<int, string, string>>& villagerData){
    string increaseKey;
    cout << "Which villager to increase friendship of?: ";
    cin >> increaseKey;
    auto it = villagerData.find(increaseKey);
    if(it != villagerData.end()){
        if(get<FRIENDSHIP>(it->second) == 10)
            cout << "    " << increaseKey << " is already at max level friendship." << endl;
        else{
        get<FRIENDSHIP>(it->second) += 1;
        cout << "    " << "Friendship increased with " << increaseKey << endl;
        }
    }
    else
        cout << "    " << increaseKey << " cannot be found." << endl;
}

void decreaseFriendship(map<string, tuple<int, string, string>>& villagerData){
    string decreaseKey;
    cout << "Which villager to decrease friendship of?: ";
    cin >> decreaseKey;
    auto it = villagerData.find(decreaseKey);
    if(it != villagerData.end()){
        if(get<FRIENDSHIP>(it->second) == 0)
            cout << "    " << decreaseKey << " is already at lowest level friendship." << endl;
        else{
        get<FRIENDSHIP>(it->second) -= 1;
        cout << "    " << "Friendship decreased with " << decreaseKey << endl;
        }
    }
    else
        cout << "    " << decreaseKey << " cannot be found." << endl;
}

void addVillager(map<string, tuple<int, string, string>>& villagerData){
    int friendLevel;
    string name, phrase, spec;
    cout << "What is this villager's name?: ";
    cin >> name;
    cout << "What is "<< name << "'s friendship level? (0-10): ";
    while(true){
        cin >> friendLevel;
        if(cin.fail() || friendLevel < 0 || friendLevel > 10){
            cout << "   Invalid friendship level, please choose a number from 0-10." << endl;
            cout << "   Friendship level: ";
            cin.clear();
            cin.ignore(IGNORE_SIZE, '\n');
        }
        else
            break;
    }
    cout << "What is "<< name << "'s species?: ";
    cin >> spec;
    cin.ignore(IGNORE_SIZE, '\n');
    cout << "What is "<< name << "'s catchphrase: ";
    getline(cin, phrase);
    villagerData[name] = {friendLevel, spec, phrase};
    cout << name << " added. Welcome to the village, " << name << "!" << endl;
} 

void displayVillagers(map<string, tuple<int, string, string>>& villagerData){
    cout << endl;
    cout << "Current villagers and their details: " << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << " [";
            cout << get<FRIENDSHIP>(it->second) << ", ";
            cout << get<SPECIES>(it->second) << ", ";
            cout << get<CATCHPHRASE>(it->second) << "] " << endl;
    }
}

int displayMenu(){
    cout << endl;
    int input;
    cout << "=== Villager Simulator ===" << endl;
    cout << " 1) Add Villager" << endl;
    cout << " 2) Delete Villager" << endl;
    cout << " 3) Increase Friendship" << endl;
    cout << " 4) Decrease Friendship" << endl;
    cout << " 5) Search for Villager" << endl;
    cout << " 6) Exit" << endl;
    cout << " Enter choice: ";
    cin >> input;
    return input;
    

}
