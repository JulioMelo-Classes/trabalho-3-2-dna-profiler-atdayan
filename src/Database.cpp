#include <algorithm>
#include <fstream>
#include <numeric>
#include <sstream>
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
        m_rows.push_back(pair<string, vector<int>>(name, nums));
        items.clear();
    }

    return true;
}

std::string Database::check_match(std::vector<int> str_count) {
    vector<int> scores;
    vector<int> score_final;
    scores.resize(str_count.size());

    for (auto &r : m_rows) {
        for (int i = 0; i < r.second.size(); i++) {
            scores[i] = std::max(r.second[i], str_count[i]) - std::min(r.second[i], str_count[i]);
        }
        score_final.push_back(std::accumulate(scores.begin(), scores.end(), 0));
    }

    int pos = std::distance(score_final.begin(), std::min_element(score_final.begin(),
                score_final.end()));

    string name = m_rows[pos].first;

    return m_rows[pos].first;
}

vector<string>& Database::get_strs() {
    return m_strs;
}
