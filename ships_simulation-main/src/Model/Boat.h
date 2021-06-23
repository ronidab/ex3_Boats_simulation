#ifndef EX3_BoatS_SIMULATION_Boat_H
#define EX3_BoatS_SIMULATION_Boat_H

#include "Direction.h"
#include "gameObj.h"
#include "Port.h"
#include <queue>

using namespace std;

enum order {
    Course, Position, Destination, Dock_at, Attack, Refuel, Stop
};

enum Status {
    Stopped, Docked, Dead, Move
};

struct Order {
    order ord;
    int deg;
    double speed;
    double x;
    double y;
    weak_ptr<Port> port;
    weak_ptr<Boat> boat;
    int num_of_containers;

    Order(order arg_ord, int arg_deg , double arg_speed , weak_ptr<Port> p, weak_ptr<Boat> b,
          double arg_x , double arg_y , int containers ) :
            ord(arg_ord), deg(arg_deg), speed(arg_speed), x(arg_x), y(arg_y),
            num_of_containers(containers) {
        port = std::move(p);
        boat = std::move(b);
    };

};

struct unload_Port {
    Port port;
    int capacity;
};

/*****************************************/
class freighterBoat;

class cruiserBoat;

class patrolBoat;

/*****************************************/

class Boat : public gameObj {
protected:
    /*data members*/

    const double MAX_BOAT_FUEL;
    const string name;
    int resistance;
    double curr_fuel;
    Status status;
    double curr_speed;
    Direction direction;
    Location curr_Location;
    Location dest_Location;
    int num_of_containers;
    bool finish_order;

    queue<Order> orders_queue;

    vector<Port> ports_to_load;
    vector<unload_Port> ports_to_unload;


public:
    Boat(string &boat_name, double max_fuel = 0, int res = 0, int num = 0) : name(boat_name), MAX_BOAT_FUEL(max_fuel),
                                                                         resistance(res), curr_fuel(max_fuel),
                                                                         status(Stopped), curr_speed(0),
                                                                         direction(Direction()),
                                                                         curr_Location(Location()),
                                                                         dest_Location(Location()),finish_order(true) {};

    virtual ~Boat() {};

    Boat(const Boat &) = delete;

    Boat(Boat &&) = delete;

    Boat &operator=(const Boat &) = delete;

    Boat &operator=(Boat &&) = delete;

    virtual void
    addOrder(const string &ord_str, int deg, double speed, double x, double y, weak_ptr<Port> port, weak_ptr<Boat>boat,
             int cont_capacity) {
        order curr_ord;
        if (ord_str == "course") curr_ord = Course;
        else if (ord_str == "position") curr_ord = Position;
        else if (ord_str == "destination") curr_ord = Destination;
        else if (ord_str == "dock_at") curr_ord = Dock_at;
        else if (ord_str == "attack") curr_ord = Attack;
        else if (ord_str == "refuel") curr_ord = Refuel;
        else if (ord_str == "stop") curr_ord = Stop;

        Order new_order = Order(curr_ord, deg, speed, port, boat, x, y, cont_capacity);
        orders_queue.push(new_order);   //adding order to queue
    }




//    virtual int getSpeed() const { return curr_speed; }
//
//    virtual const string &getBoatName() const { return name; }
//
//    virtual Status getStatus() const { return status; }
//
//    virtual const string &getName() const { return name; }
//
//    virtual double getMaxFuel() const { return MAX_BOAT_FUEL; }
//
//    virtual double getCurrFuel() const { return curr_fuel; }
//
//    virtual int getResistance() { return resistance; }
//
//    virtual void setResistance(int res) { resistance = res; }
//
//    virtual int getNumOfContainers() const { return num_of_containers; }
//
//    virtual void executeByStatus(Status new_status) {
//
//    virtual const Location &getCurrLocation() const { return curr_Location; }
//
//    virtual void setCurrLocation(const Location &currLocation) { curr_Location = currLocation; }
//
//    virtual const Location &getDestLocation() const { return dest_Location; }
//
//    virtual void setDestLocation(const Location &destLocation) { new_dest_Location = destLocation; }
//
//    virtual const Direction &getDirection() const { return direction; }
//
//    virtual void setDirection(const Direction &direction) { direction = direction; }
//
//    virtual void setCourse(const double &deg) { new_Direction = Direction(deg); }


    virtual Boat &operator++() {
        resistance++;
        return *this;
    }

    virtual Boat &operator--() {
        resistance--;
        return *this;
    }

    virtual void course(int deg, double speed) = 0;

    virtual void position(double x, double y, double speed) = 0;

    virtual void destination(weak_ptr<Port> port, double speed) = 0;

    virtual void dock(weak_ptr<Port> port) = 0;

    virtual void attack(weak_ptr<Port> port) = 0;

    virtual void refuel() = 0;

    virtual void stop() = 0;


//    virtual void dead() = 0;
//    virtual void move() = 0;


    virtual void update() {
        if(finish_order) {
            if (!orders_queue.empty()) {
                //start actions for curr order & remove from queue:
                Order curr_order = orders_queue.front();
                orders_queue.pop();

                switch (curr_order.ord) {
                    case (Course):
                        course(curr_order.deg, curr_order.speed);
                        break;
                    case (Position):
                        position(curr_order.x, curr_order.y, curr_order.speed);
                        break;
                    case (Destination):
                        destination(curr_order.port, curr_order.speed);
                        break;
                    case (Dock_at):
                        dock(curr_order.port);
                        break;
                    case (Attack):
                        attack(curr_order.port);
                        break;
                    case (Refuel):
                        refuel();
                        break;
                    case (Stop):
                        stop();
                        break;
                }
            }
        }
        else{
            switch(status){
                case(Stopped):
                    /*
                     *
                     * do stop actions
                     *actually maybe there is no actions for stop ??
                     */
                    break;
                case(Docked):
                    /*
                     *
                     * do dock actions
                     *dock()
                     */
                    break;
                case(Dead):
                    /*
                     *
                     * do dead actions
                     *check if fuel is full again
                     * else: stay in same status
                     * continue
                     */
                    break;
                case(Move):
                    /*
                     *
                     * do move actions
                     *
                     *
                     */
                    break;
            }
        }
    }
};

#endif
