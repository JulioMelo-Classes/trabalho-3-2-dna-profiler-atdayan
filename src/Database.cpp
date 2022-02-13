#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include "Database.hpp"

using namespace std;

bool Database::read_database(std::string filename) {

    std::ifstream file {filename};
    int dot_pos = filename.find_last_of(".");
    if (filename.substr(dot_pos + 1) != "csv")
        return false;

    if (!file.is_open())
        return false;

    string line;
    if (std::getline(file, line)) {
        line.erase(0, 5);
        std::stringstream ss(line);
        string str;
        while(std::getline(ss, str, ','))
            m_strs.push_back(str);
    }

    vector<string> items;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        while (std::getline(ss, line, ',')) {
            items.push_back(line);
        }
        string name = items.front();
        vector<int> nums;
        nums.resize(items.size() - 1);
        std::transform(items.begin() + 1, items.end(), nums.begin(), [](string &s){
                    return std::stoi(s);
                });
        m_rows.insert(pair<string, vector<int>>(name, nums));
        items.clear();
    }

    return true;
}
