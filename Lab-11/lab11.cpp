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

// Here, I initialize two constants for the index of Ryu and Cammy.
// I wasn't sure if I should include them since the index of a fighter
// can change, but I just put them just in case.
const int INDEX_RYU = 2;
const int INDEX_CAMMY = 4;

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
    // all out. We use the & operator so that the fighter being accessed
    // is the original, not a copy. The const makes it so that I cannot 
    // change the attributes of any fighter.
    int fighterNum = 1;
    for(const Fighter &f : *fighters){
        cout << "Fighter " << fighterNum << ": " << f.name << endl;
        cout << "    Style: " << f.style << endl;
        cout << "    Height: " << f.height << endl;
        cout << "    Weight: " << f.weight << endl;
        cout << "    Moves:" << endl;
        // We use the same & operator when accessing specialMoves, printing
        // the moves themselves and not copies.
        for(const string &move : f.specialMoves){
            cout << "      [" << move << "]" << endl;
        }
    fighterNum++;
    }

    // Here, I demonstrate how to change an attribute of any fighter
    // by dereferencing the vector pointer, and then accessing the
    // third item of the fighters array and changing whatever attribute
    // I want, it being style in this case.
    fighters->at(INDEX_RYU).style = "Karate";
    cout <<  fighters->at(INDEX_RYU).style << endl;

    // Here, I show that I can get rid of a fighter using erase(), 
    // erasing the fifth fighter in the vector, and then replacing them
    // with a new fighter. After that, I insert a new fighter at the
    // start of the array, which moves every fighter up one in the array.
    fighters->erase(fighters->begin() + INDEX_CAMMY);
    fighters->insert(fighters->begin() + INDEX_CAMMY, {"Cammy", "CQC", 5.5, 134,
    {"Spiral Arrow", "Cannon Spike", "Quick Spin Knuckle"}});
    fighters->insert(fighters->begin(), {"Ken", "Ansatsuken", 5.9, 183,
    {"Hadoken", "Shoryuken", "Tatsumaki Senpu-kyaku"}});

    // Here, I just do the same thing as before, making fighterNum = 1 again,
    // and printing everything out just so that the user can see the change
    // in the vector.
    fighterNum = 1;
    for(const Fighter &f : *fighters){
        cout << "Fighter " << fighterNum << ": " << f.name << endl;
        cout << "    Style: " << f.style << endl;
        cout << "    Height: " << f.height << endl;
        cout << "    Weight: " << f.weight << endl;
        cout << "    Moves:" << endl;
        for(const string &move : f.specialMoves){
            cout << "      [" << move << "]" << endl;
        }
    fighterNum++;
    }

    // After everything, we delete the fighters vector so that there aren't
    // any memory leaks. I wondered why it was "delete fighters" and not
    // "delete[] fighters", and learned that it is because fighters is just
    // a pointer to a single vector object, so I can just delete it since it's
    // just on the heap, while "delete[] fighters" are for arrays that would've
    // been allocated using "new Fighter[size]".
    delete fighters;
}