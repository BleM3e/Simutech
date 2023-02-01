#ifndef NAND_H
#define NAND_H

#include <Logic.h>

class NAnd : public Logic
{
    public:
        NAnd();
        virtual ~NAnd();

        int calculate();
    protected:

    private:
};

#endif // NAND_H
