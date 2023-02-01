#ifndef NOR_H
#define NOR_H

#include <Logic.h>

class Nor : public Logic
{
    public:
        Nor();
        virtual ~Nor();

        int calculate();
    protected:

    private:
};

#endif // NOR_H
