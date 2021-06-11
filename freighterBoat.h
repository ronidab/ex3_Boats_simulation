#ifndef EX3_BOATS_SIMULATION_FREIGHTERBOAT_H
#define EX3_BOATS_SIMULATION_FREIGHTERBOAT_H
#include "Boat.h"

class freighterBoat : public Boat  {
private:
    const int MAX_CONTAINERS_CAPACITY = 2020202;//??????
    const int MAX_FUEL = 500000;
    const int MAX_SPEED = 40;
    const int FUEL_PER_NM = 1000;
    const int resistance;
    int curr_fuel;
    int num_of_containers;
    int new_num_of_containers;
    bool load_status;
    bool new_load_status;
    bool warning;
public:
    freighterBoat(int res):resistance(res),curr_fuel(MAX_FUEL), warning(0){};
    void setToLoad(bool b){new_load_status = b;}
    void setDestLocation(const Location &destLocation);
    void setDirection();
    void setPort(int speed, bool b, const Location& dest_loc);
    void unload(int cont, unique_ptr<Port>& port);
    void load(unique_ptr<Port>& port);
    void fuel(int);
    void stop();
    void dock();
    void dead();
    void move();






};


#endif //EX3_BOATS_SIMULATION_FREIGHTERBOAT_H
