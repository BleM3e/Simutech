#ifndef __LOGIC_HPP__
#define __LOGIC_HPP__

#include <iostream>
#include <string>
#include <vector>

/* Primary class of Logic Behaviour */

class Logic
{
private:
    /* data */
    std::string name;

public:
    Logic(std::string _name);
    ~Logic();

    std::string get_name();
    int get_sourcesNumber();
    int get_exit();

protected:
    /* data */
    int sourcesNumber;
    int exit;
};

/* Child class for specific Logic Behaviour */

/* Logical Input */

class Input : public Logic
{
private:
    /* data */
public:
    Input(std::string _name);
    ~Input();
};

/* Logical Output */

class Output : public Logic
{
private:
    /* data */
public:
    Output(std::string _name);
    ~Output();
};

/* Logical Gate */

class Gate : public Logic
{
private:
    std::vector<Logic> src_array;
public:
    Gate(std::string _name);
    ~Gate();

    void add_source(Logic src);
    int get_src_exit(int i);
    int get_size_src();
};

#endif