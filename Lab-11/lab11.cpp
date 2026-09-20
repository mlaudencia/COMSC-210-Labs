#include <iostream>
#include <vector>
using namespace std;

struct Fighter{
    string name;
    string style;
    double height;
    int weight;
};

int main(){

    vector<Fighter>* fighters = new vector<Fighter>;

    fighters->push_back({"Yasmine", "Eskrima", 5.4, 130});
    fighters->push_back({"Akuma", "Ansatsuken", 5.10, 198});
    fighters->push_back({"Ryu", "Ansatsuken", 5.9, 187});
    fighters->push_back({"Juri", "Taekwondo", 5.5, 126});
    fighters->push_back({"Zangief", "Wrestling", 7.0, 399});

    int temp = 1;
    for(const Fighter &f : *fighters){
    cout << "Fighter " << temp << ": " << f.name << endl;
    cout << "    Style: " << f.style << endl;
    cout << "    Height: " << f.height << endl;
    cout << "    Weight: " << f.weight << endl;
    temp++;
    }
};