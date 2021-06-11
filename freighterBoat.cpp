//
// Created by User on 11/06/2021.
//

#include "freighterBoat.h"


void freighterBoat::stop(){
    //cancel destinations
    curr_speed = 0;
}
void freighterBoat::dock(){
    if (curr_Location.distance_from(dest_Location) <= 0.1) {
        curr_Location = dest_Location;
        curr_speed = 0;
    }
    else{
        //EXCEPTION ????????????
    }
}
void freighterBoat::dead(){
    curr_speed = 0;
//????
}
void freighterBoat::move(){
    curr_Location = curr_Location.next_Location(direction, curr_speed);
}

void freighterBoat::setDestLocation(const Location &destLocation){
    new_dest_Location = destLocation;
}

void freighterBoat::setDirection(){
    new_Direction = Direction(new_curr_Location,new_dest_Location);
}

void freighterBoat::setPort(int speed, bool b, const Location& dest_loc){
    new_status = Move;
    new_speed = speed;
    setDestLocation(dest_loc);
    setToLoad(b);
    setDirection();

}

void freighterBoat::unload(int containers, unique_ptr<Port>& port){
    if(new_status==Docked){
        if(new_num_of_containers < containers){
            port->load(new_num_of_containers);
            new_num_of_containers = 0;
            warning = 1;
            //print warning from update***
        }
        else{
            port->load(containers);
            new_num_of_containers -= containers;
        }
    }
    else{
        //EXCEPTION!!!!! NOT IN DOCKED STATUS
    }
}

void freighterBoat::load( unique_ptr<Port>& port) {
    port->unload(MAX_CONTAINERS_CAPACITY-new_num_of_containers);
    new_num_of_containers = MAX_CONTAINERS_CAPACITY;

    port->addToQueue(unique_ptr<Boat>(this));

}