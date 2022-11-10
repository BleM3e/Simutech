#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include "Logic.hpp"

//
// Input's child classes
//

class True : public Input
{
private:
    /* data */
public:
    True(std::string _name);
    ~True();
};

class False : public Input
{
private:
    /* data */
public:
    False(std::string _name);
    ~False();
};

//
// Output's child classes
//

class Led : public Output
{
private:
    /* data*/
public:
    Led(std::string _name);
    ~Led();
};

//
// Gate's child classes
//

class Not : public Gate
{
private:
    /* data */
public:
    Not(std::string _name);
    ~Not();

    int calculate();
};

class And : public Gate
{
private:
    /* data */
public:
    And(std::string _name);
    ~And();

    int calculate();
};

class Or : public Gate
{
private:
    /* data */
public:
    Or(std::string _name);
    ~Or();

    int calculate();
};


#endif