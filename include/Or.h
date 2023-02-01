#ifndef OR_H
#define OR_H

#include <Logic.h>

class Or : public Logic
{
    public:
        Or();
        virtual ~Or();

        int calculate();
    protected:

    private:
};

#endif // OR_H
