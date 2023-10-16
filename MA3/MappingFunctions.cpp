
#include "MappingFunctions.hpp"

void print_map(map<string, TwitterData*> data)
{
        for (auto it = data.begin(); it != data.end(); ++it) {
                cout << "Key: " << it->first << ", Value: " << it->second->print() << endl;
        }
        cout << "\n";
}

void find_and_print(const map<string, TwitterData*> data, string key)
{
        int success = 0;
        cout << "Seach for key: ";
        for (auto it = data.begin(); it != data.end(); ++it) {
                if (it->first == key) {
                        success = 1;
                        cout << "key: " << it->first << ", Value: " << it->second->print() << endl;
                }
        }
        if (success == 0) {
                cout << "[Error] Not Found Print Unsuccessful" << endl;
        }
        cout << "\n";
}
