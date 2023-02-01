#ifndef AND_H
#define AND_H

#include <Logic.h>

class And : public Logic
{
    public:
        And();
        virtual ~And();

        int calculate();
    protected:

    private:
};

#endif // AND_H
