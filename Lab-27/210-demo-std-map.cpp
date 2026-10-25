#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

const int FRIENDSHIP = 0;
const int SPECIES = 1;
const int CATCHPHRASE = 2;

void searchVillager();
void deleteVillager();

int main() {
    // declarations
    int input;
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = {5, "Orc", "Me not cyclops, me orc!"};
    villagerData["Raymond"] = {3, "Wolf", "I did not eat those sheep!"};
    villagerData["Marshal"] = {7, "Reptile", "I'm totally normal human!"};

    // access the map using a range-based for loop
    cout << "Villagers details:" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << " [";
            cout << get<FRIENDSHIP>(pair.second) << ", ";
            cout << get<SPECIES>(pair.second) << ", ";
            cout << get<CATCHPHRASE>(pair.second) << "] " << endl;
    }

    // BELOW IS FROM DEMO CODE

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
    villagerData.erase("Raymond");

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
        cout << "\nFound " << searchKey << "'s Data: ";
            cout << get<FRIENDSHIP>(it->second) << ", ";
            cout << get<SPECIES>(it->second) << ", ";
            cout << get<CATCHPHRASE>(it->second) << ". ";
    } else
        cout << endl << searchKey << " not found." << endl;

}

void deleteVillager(map<string, tuple<int, string, string>>& villagerData){
    string deleteKey;
    cout << "What villager to delete?: ";
    cin >> deleteKey;
    auto it = villagerData.find(deleteKey);
    if(it != villagerData.end()){
        villagerData.erase(deleteKey);
        cout << deleteKey << " deleted." << endl;
        return;
    }
    else
        cout << deleteKey << " does not exist." << endl;
}
