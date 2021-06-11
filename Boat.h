#ifndef EX3_BoatS_SIMULATION_Boat_H
#define EX3_BoatS_SIMULATION_Boat_H

#include <String>
#include "Location.h"
#include "Direction.h"
#include "gameObj.h"
#include "Port.h"

using namespace std;

enum Status {
    Stopped, Docked, Dead, Move
};

class Boat : public gameObj {
protected:
    int curr_speed;
    string name;
    Status status;
    Location curr_Location;
    Location dest_Location;
    Direction direction;
    int new_speed;
    Status new_status;
    Location new_curr_Location;
    Location new_dest_Location;
    Direction new_Direction;
public:
    Boat() : status(Stopped) {};

    virtual int getCurrSpeed() const { return curr_speed; }

    virtual void setCurrSpeed(int currSpeed) { curr_speed = currSpeed; }

    virtual const string &getName() const { return name; }

    virtual void setName(const string &name) { Boat::name = name; }

    virtual Status getStatus() const { return status; }

    virtual void setStatus(Status new_status) {
        switch (new_status) {
            case Stopped:
                curr_speed = 0;
                dest_Location = curr_Location;
                status = Stopped;
                stop();
                break;
            case Docked:
                status = Docked;
                dock();
                break;
            case Dead:
                status = Dead;
                dead();
                break;
            case Move:
                status = Move;
                move();
                break;
        }
    }

    virtual const Location &getCurrLocation() const { return curr_Location; }

    virtual void setCurrLocation(const Location &currLocation) { curr_Location = currLocation; }

    virtual const Location &getDestLocation() const { return dest_Location; }

    virtual void setDestLocation(const Location &destLocation) = 0;

    virtual const Direction &getDirection() const { return Direction; }

    virtual void setDirection(const Direction &Direction)=0;

    virtual void stop() = 0;
    virtual void dock() = 0;
    virtual void dead() = 0;
    virtual void move() = 0;

    virtual string toString() const = 0;
    virtual void update() override;

    virtual ~Boat() = 0;

};

Boat::~Boat() {}


#endif
