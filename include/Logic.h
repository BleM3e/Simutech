#ifndef LOGIC_H
#define LOGIC_H

#define DEBUG 1 //modify the value for debug mode

#if DEBUG
#include <iostream>
#endif // DEBUG

#include <vector>
#include <string>

class Logic
{
    public:
        Logic();
        virtual ~Logic();

        int get_logic_type();
        std::string get_logic_type_name();

        int get_component_id();
        std::string get_component_name();
        void add_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL);

        void set_exit(int _exit);
        int get_exit();

        // Update function for output component
        void update_output();
        // Update function for gate component
        void update_exit();

        // Virtual function used for update the exit of the led
        virtual void update_led();
        // Calculate the exit of a component
        virtual int calculate();

        // Prevent for recursiv event
        void reset_ttl();
        void update_ttl();
        int get_ttl();

        int get_size_src();
        int get_size_out();

        std::vector<Logic*> sources_t;
        std::vector<Logic*> output_t;

    protected:
        int ttl = 0;    //Time to live

        int valSortie = 0;

        void set_logic_type(int _type);
        void set_logic_type_name(std::string _name);

        void set_component_id(int _component_id);
        void set_component_name(std::string _name);

    private:
        // Input = 0, Gate = 1, Output = 2
        int logic_type;
        std::string logic_type_name;

        int component_id;
        std::string component_name;

        // Exit value
        int exit;
};

#endif // LOGIC_H
