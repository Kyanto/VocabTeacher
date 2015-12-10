#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;

class Category{

private :
    string m_name;
    string m_words[2][100];
    int m_i;

public :
    Category(string name);
    void setWord(string fo, string fr);
    int getNb();
    void askWords();
    string getName();
    void printWords();
    void mix();
    void save();
    void addWords();
    void deleteWords();
};

#endif // __CATEGORY_HPP_
