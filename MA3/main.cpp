#include <map>
#include "TwitterData.hpp"
#include "MappingFunctions.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = { {"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"} };
    TwitterData* twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }
    ////////////////////////////////////////////////////////////////////////// Map Scenario 1
    map<string, TwitterData*> s1;
    for (int i = 0; i < 5; ++i) {
        s1.insert( std::pair<string, TwitterData*>(twitter_data[i].getUserName(), &twitter_data[i]));
    }
    cout << "Print searchByName map: " << endl;
    print_map(s1);
    find_and_print(s1, "savage1"); //Find and print the matching record
    s1.erase("savage1");
    cout << "Updated List: " << endl;
    print_map(s1); //Print the updated record
    //////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////// Map Scenario 2
    map<string, TwitterData*> s2;
    for (int i = 0; i < 5; ++i) {
        s2.insert(std::pair<string, TwitterData*>(twitter_data[i].getEmail(), &twitter_data[i]));
    }
    cout << "Print searchByEmail map: " << endl;
    print_map(s2);
    find_and_print(s2, "kat@gmail.com"); //Find and print the matching record
    s2.erase("kat@gmail.com");
    cout << "Updated List: " << endl;
    print_map(s2); //Print the updated record;
    //////////////////////////////////////////////////////////////////////////
    return 0;
}
