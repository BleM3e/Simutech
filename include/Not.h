#ifndef NOT_H
#define NOT_H

#include <Logic.h>

class Not : public Logic
{
    public:
        Not();
        virtual ~Not();

        int calculate();
    protected:

    private:
};

#endif // Not_H
