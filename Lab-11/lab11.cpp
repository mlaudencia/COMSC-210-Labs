#include <iostream>
#include <vector>
using namespace std;

struct Fighter{
    string name;
    string style;
    double height;
    int weight;
    vector<string> specialMoves;
};

int main(){

    vector<Fighter>* fighters = new vector<Fighter>;

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

    int temp = 1;
    for(const Fighter &f : *fighters){
    cout << "Fighter " << temp << ": " << f.name << endl;
    cout << "    Style: " << f.style << endl;
    cout << "    Height: " << f.height << endl;
    cout << "    Weight: " << f.weight << endl;
    cout << "    Moves:" << endl;
    for(const string &move : f.specialMoves)
        cout << "      [" << move << "]" << endl;
    temp++;
    }

    fighters->at(2).style = "Karate";
    cout <<  fighters->at(2).style << endl;

    fighters->erase(fighters->begin() + 4);
    fighters->insert(fighters->begin() + 4, {"Cammy", "CQC", 5.5, 134});
    fighters->insert(fighters->begin(), {"Ken", "Ansatsuken", 5.9, 183});

    temp = 1;
    for(const Fighter &f : *fighters){
    cout << "Fighter " << temp << ": " << f.name << endl;
    cout << "    Style: " << f.style << endl;
    cout << "    Height: " << f.height << endl;
    cout << "    Weight: " << f.weight << endl;
    for(const string &move : f.specialMoves)
        cout << "      [" << move << "]" << endl;
    temp++;
    }

    delete[] fighters;
};