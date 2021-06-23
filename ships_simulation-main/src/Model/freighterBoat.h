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
    std::weak_ptr<Port> dest_port;

    bool load_status;
    bool warning;


public:
    /*c'tors & d'tors*/
    freighterBoat(string& boat_name,int cont_cap, int res);
    ~freighterBoat()	{}

    /*getters & setters*/
//    void setDirection();
//    void setToLoad(bool b);
//    void setDestLocation(const Location &destLocation);
//    void setPort(std::shared_ptr<Port>& port, int speed, bool b, const Location& dest_loc);
//    void setToUnload(int capacity);

    /*class functions*/
    void course(int deg, double speed);

    void position(double x, double y, double speed);

    void destination(weak_ptr<Port> port, double speed);

    void dock(weak_ptr<Port> port);

    void attack(weak_ptr<Port> port);

    void refuel();

    void stop();

    /*print operator*/
    friend ostream& operator<<(ostream& out, const freighterBoat& ship);
};


#endif
