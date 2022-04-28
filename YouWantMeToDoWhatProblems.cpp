// YouWantMeToDoWhatProblems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

class Assignment
{
public:
    char setName[256];
    string assign;
    vector<int> v;
    int k;
    string names;

    string getSetName()
    {
        cout << "Please enter assignment name " << endl;
        cin.getline(setName, 256);
        names = setName;
        names.erase(remove(names.begin(), names.end(), '"'), names.end());

        return names;
    }

    void getSetList()
    {
        cout << "\nPlease enter your assignment list" << endl;
        getline(cin, assign);
        //stringstream ss(assign);

        //for (int i; ss >> i;) {
           // v.push_back(i);
            //if (ss.peek() == ',' || ss.peek() == ' ')
               // ss.ignore();
        //}

    }
    void printAssign()
    {
        // I used it to see what those values look like printed.
      //cout << "\nYou entered: " << setName << " " << assign << endl;  
    }


    void display()
    {
        regex re{ R"(((\d+)-(\d+))|(\d+))" };
        smatch sm{};


        vector<int> data{};

        for (string s{ assign }; std::regex_search(s, sm, re); s = sm.suffix())
        {
            if (sm[1].str().length())
                for (int i{ std::stoi(sm[2]) }; i <= std::stoi(sm[3]); ++i) data.push_back(i);
            else
                data.push_back(std::stoi(sm[0]));
        }
        //for (const int i : data) std::cout << i << '\n';

        stringstream ss;
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (i != 0)
                ss << ",";
            ss << data[i];
        }
        string s = ss.str();
        cout << "\nDo assignments " << s << " of " << names << endl;
    }
};

int main()
{
    Assignment userInput;

    userInput.getSetName();

    userInput.getSetList();

    //userInput.printAssign();

    userInput.display();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
