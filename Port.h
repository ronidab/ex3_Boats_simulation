#ifndef Port_H_
#define Port_H_
#include <memory>
#include <queue>


class Boat;
/**************************/
class Port	{

private:
	Location loc;
	double fuel_capacity;
	queue< unique_ptr<Boat> > ready_to_fuel;
	/*
	 *
	 * other data members ?
	 *
	 */

public:
	/*c'tors & d'tors*/
	Port();
	Port(const Location& loc);
	void addToQueue(unique_ptr<Boat>& boat){ready_to_fuel.push(boat);}
	~Port();

	/*operators*/



	/*setters & getters*/
	Location get_Location() const;


	/*class functions*/
	void unload(int cap);
	void load(int cap);
	void fuel(int cap);
};
/**************************/
#endif
