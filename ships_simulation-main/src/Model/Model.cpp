#include "Model.h"
/*************************************/
Model& Model::getInstance()	{

    if( inst.get() ) { return *inst.get(); }

    // singleton will be first initialized here
    inst = unique_ptr<Model>(new Model());
    return *inst.get();
}
/*************************************/
vector<shared_ptr<Port>>& Model::getAllPorts()	{ return all_ports;	}
/////*************************************/
//vector<shared_ptr<Port>>& Model::getAllBoats()	{ return all_boats; }
///*************************************/
int Model::findPortByLocation(const Location &loc)	{

    for(int i = 0; i < all_ports.size(); ++i)	{
        if(all_ports[i].get()->
        if( all_ports[i].get()->get_Location() == loc )	{
            all_ports[i].get();
            return i;
        }
    }

    return -1;
}
/*************************************/
/*************************************/
void Model::status()	{ //print status of all objects in the simulation

    for( auto& boat : all_boats )	{
        cout << boat << endl;
    }

    for( auto& port : all_ports )	{
        cout << port << endl;
    }
}
/*************************************/
void Model::go()	{ // loop of "update" for all objects

    for( auto& boat : all_boats )	{ boat.get()->update(); }
    for( auto& port : all_ports )	{ port.get()->update(); }

}
/*************************************/
void Model::create(const string& boat_name, const string& boat_type, double x, double y, int res_atckPower, int cap_range )	{//add boat to data

    if( boat_type == "Freighter" )	{ all_boats.push_back(make_shared<Boat>(new freighterBoat() )); }

    else if( boat_type == "Cruiser" )	{ all_boats.push_back(make_shared<Boat>(new Cruiser())); }

    else	{ all_boats.push_back(make_shared<Boat>(new patrolBoat()); }



}
