#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// ==================== LOCATION CLASS ====================
class Location
{
private:
    pair<int, int> coord;  // (x, y) using pair!
public:
    Location(int x = 0, int y = 0)
    {
        coord.first = x;
        coord.second = y;
    }

    int distanceFrom(const Location &other) const
    {
        return abs(coord.first - other.coord.first) +
               abs(coord.second - other.coord.second);  // Manhattan Distance
    }

    // Optional: accessors
    int getX() const
    {
        return coord.first;
    }
    int getY() const
    {
        return coord.second;
    }
};

// ==================== DRIVER CLASS ====================
class Driver
{
private:
    string name;
    Location loc;
    bool isAvailable;
public:
    Driver(string n, Location l, bool available = true)
        : name(n), loc(l), isAvailable(available) {}

    string getName() const
    {
        return name;
    }
    Location getLocation() const
    {
        return loc;
    }
    bool getAvailability() const
    {
        return isAvailable;
    }
    void setAvailability(bool status)
    {
        isAvailable = status;
    }
};

// ==================== PASSENGER CLASS ====================
class Passenger
{
private:
    string name;
    Location loc;
public:
    Passenger(string n, Location l) : name(n), loc(l) {}

    string getName() const
    {
        return name;
    }
    Location getLocation() const
    {
        return loc;
    }
};

// ==================== RIDE SERVICE (Aggregation) ====================
class RideService
{
private:
    vector<Driver*> drivers;  // Aggregation: stores pointers, does NOT own
public:
    void registerDriver(Driver* d)
    {
        drivers.push_back(d);
    }

    // Find nearest available driver
    Driver* findNearestAvailableDriver(const Passenger& p) const
    {
        Driver* nearest = nullptr;
        int minDist = INT_MAX;

        for (Driver* d : drivers)
        {
            if (d->getAvailability())
            {
                int dist = d->getLocation().distanceFrom(p.getLocation());
                if (dist < minDist)
                {
                    minDist = dist;
                    nearest = d;
                }
            }
        }
        return nearest;
    }

    // Assign ride and mark driver unavailable
    void assignRide(Passenger& p)
    {
        Driver* driver = findNearestAvailableDriver(p);
        if (driver != nullptr)
        {
            driver->setAvailability(false);
            int dist = driver->getLocation().distanceFrom(p.getLocation());
            cout << "Driver " << driver->getName()
                 << " assigned to Passenger " << p.getName()
                 << " (distance: " << dist << ")" << endl;
        }
        else
        {
            cout << "No available driver for Passenger " << p.getName() << endl;
        }
    }
};

// ============================= MAIN =============================
int main()
{
    // Create driver objects
    Driver d1("Ali", Location(5, 3));
    Driver d2("Hasan", Location(10, 1));
    Driver d3("Zara", Location(2, 8));

    // Create a passenger
    Passenger p("Sara", Location(6, 2));

    // Create RideService object
    RideService service;

    // Register drivers (Aggregation: storing pointers)
    service.registerDriver(&d1);
    service.registerDriver(&d2);
    service.registerDriver(&d3);

    // Assign nearest driver to the passenger
    service.assignRide(p);

    return 0;
}
