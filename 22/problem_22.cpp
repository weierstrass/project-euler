#include "problem_22.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <numeric>

using std::vector;
using std::string;

vector<string> read_names(const string file) {
    vector<string> names;

    std::ifstream file_stream(file);
    
    string name, foo;
    while (true){
        std::getline(std::getline(file_stream, foo, '"'), name, '"');
        if (!file_stream.good()) break;

        names.push_back(name);
    }

    return names;
}

struct name_add {
    name_add() : m_position(1) {}
    
    int64_t operator()(int64_t total, const string& name) {
        int64_t name_sum = std::accumulate(std::begin(name), std::end(name), 0);
        
        name_sum -= name.size() * ('A' - 1);

        return  total +  (name_sum * m_position++);
    }
    
private:
    int64_t m_position;
} name_adder;


TEST(protblem_22, read_file) {
    vector<string> names = read_names("p022_names.txt");

    EXPECT_EQ("MARY", names.at(0));
    EXPECT_EQ("LINDA", names.at(2));
}

TEST(problem_22, sort) {
    vector<string> names = {"COLIN", "HILTON", "AARON", "EMMITT"};
    std::sort(names.begin(), names.end());

    EXPECT_EQ("AARON", names.at(0));
}

TEST(problem_22, name_score) {
    name_add test_adder;

    EXPECT_EQ(53, test_adder(0, "COLIN"));
}

TEST(problem_22, full) {
    // Read names from file.
    vector<string> names = read_names("p022_names.txt");

    // Sort names.
    std::sort(names.begin(), names.end());

    // Compute name score.
    int64_t total = std::accumulate(names.begin(), names.end(), 0, name_adder);

    EXPECT_EQ(871198282, total);
}
