// COMSC-210 | Lab 11 | Jeremy Laudencia

// Here, I include <iostream> to handle couts,
// and <vector> for the required dynamic array usage.
#include <iostream>
#include <vector>
using namespace std;

// I make a struct definition for fighter including four attributes,
// name, fight style, height, and weight, and a dynamic array that 
// holds a fighter's specialMoves.
struct Fighter{
    string name;
    string style;
    double height;
    int weight;
    vector<string> specialMoves;
};

int main(){

    // I make a new dynamic array of type fighter 
    // to hold all the fighters and their data.
    vector<Fighter>* fighters = new vector<Fighter>;

    // Here, I make 5 new fighters with each their own attributes
    // that were in the struct definition.
    fighters->push_back({"Yasmine", "Eskrima", 5.4, 130,
        {"Daloy ng Tubig", "Talim ng Hangin", "Mukha ng Langit"}});
    fighters->push_back({"Akuma", "Ansatsuken", 5.10, 198,
        {"Gou Hadoken", "Zanku Hadoken", "Gou Shoryuken"}});
    fighters->push_back({"Ryu", "Ansatsuken", 5.9, 187,
        {"Hadoken", "Shoryuken", "Tatsumaki Senpu-kyaku"}});
    fighters->push_back({"Juri", "Taekwondo", 5.5, 126,
        {"Fuhajin", "Saihasho", "Ankensatsu"}});
    fighters->push_back({"Zangief", "Wrestling", 7.0, 399,
        {"Double Lariat", "Screw Piledriver", "Borscht Dynamite"}});

    // To print them all out, I make a new variable, fighterNum, just
    // to keep count of what number fighter we're on when printing them
    // all out.
    int fighterNum = 1;
    for(const Fighter &f : *fighters){
    cout << "Fighter " << fighterNum << ": " << f.name << endl;
    cout << "    Style: " << f.style << endl;
    cout << "    Height: " << f.height << endl;
    cout << "    Weight: " << f.weight << endl;
    cout << "    Moves:" << endl;
    for(const string &move : f.specialMoves)
        cout << "      [" << move << "]" << endl;
    fighterNum++;
    }

    fighters->at(2).style = "Karate";
    cout <<  fighters->at(2).style << endl;

    fighters->erase(fighters->begin() + 4);
    fighters->insert(fighters->begin() + 4, {"Cammy", "CQC", 5.5, 134,
    {"Spiral Arrow", "Cannon Spike", "Quick Spin Knuckle"}});
    fighters->insert(fighters->begin(), {"Ken", "Ansatsuken", 5.9, 183,
    {"Hadoken", "Shoryuken", "Tatsumaki Senpu-kyaku"}});

    fighterNum = 1;
    for(const Fighter &f : *fighters){
    cout << "Fighter " << fighterNum << ": " << f.name << endl;
    cout << "    Style: " << f.style << endl;
    cout << "    Height: " << f.height << endl;
    cout << "    Weight: " << f.weight << endl;
    for(const string &move : f.specialMoves)
        cout << "      [" << move << "]" << endl;
    fighterNum++;
    }

    delete fighters;
};