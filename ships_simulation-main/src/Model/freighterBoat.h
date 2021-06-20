#ifndef EX3_BOATS_SIMULATION_FREIGHTERBOAT_H
#define EX3_BOATS_SIMULATION_FREIGHTERBOAT_H
#include "Boat.h"

class freighterBoat : public Boat  {
private:
	/*constants*/
    const int MAX_CONTAINERS_CAPACITY;
    static const int MAX_FRI_FUEL = 500000;
    const int MAX_SPEED = 40;
    const double FUEL_PER_NM = 1000;

    /*data members*/
    string destPortName;
    bool load_status;
    bool warning;

    /*data members update*/
    string new_destPortName;
    bool new_load_status;


public:
    /*c'tors & d'tors*/
    freighterBoat(int cont_cap, int res):Boat(MAX_FRI_FUEL, res, MAX_CONTAINERS_CAPACITY),MAX_CONTAINERS_CAPACITY(cont_cap),load_status(0),
								warning(0), new_load_status(load_status) {};
    ~freighterBoat()	{}

    /*getters & setters*/
    void setDirection();
    void setToLoad(bool b);
    void setDestLocation(const Location &destLocation);
    void setPort(string destPortName, int speed, bool b, const Location& dest_loc);

    /*class functions*/
    void unload(int cont, unique_ptr<Port>& port);
    void load(unique_ptr<Port>& port);
    void fuel(unique_ptr<Port>& port);
    void stop();
    void dock();
    void dead();
    void move();
    void update();

    /*print operator*/
    friend ostream& operator<<(ostream& out, const freighterBoat& ship);
};


#endif
