#ifndef THREESTATEDOOR_H
#define THREESTATEDOOR_H

#include <Logic.h>

class ThreeStateDoor : public Logic
{
    public:
        ThreeStateDoor();
        virtual ~ThreeStateDoor();

        int calculate();
    protected:

    private:
};

#endif // THREESTATEDOOR_H
