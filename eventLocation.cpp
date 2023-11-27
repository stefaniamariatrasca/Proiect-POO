#include <iostream>

using namespace std;

class EventLocation {
private:
    string locationName;
    int maxSeats;
    int numRows;
    int numZones;
    int seatsPerRow;

public:
    // Default constructor
    EventLocation() : locationName(null), maxSeats(0), numRows(0), numZones(0), seatsPerRow(0) {}

    // Parameterized constructor
    Student(string locationName, int maxSeats, int numRows, int numZones, int seatsPerRow)
	{
		this->locationName = locationName;
		this->maxSeats = maxSeats;
        this->numRows = numRows;
        this->numZones = numZones;
        this->seatsPerRow = seatsPerRow;
	}

    // Accessors
    int getLocationName() const { return locationName; }
    int getMaxSeats() const { return maxSeats; }
    int getNumRows() const { return numRows; }
    int getNumZones() const { return numZones; }
    int getSeatsPerRow() const { return seatsPerRow; }

    // Setters with validation

     void setLocationName(int name) {
        if (name != NULL) {
            locationName = name;
        } else {
            cout << "Error: Name must contain a value." << endl;
        }
    }

    void setMaxSeats(int seats) {
        if (seats > 0) {
            maxSeats = seats;
        } else {
            cout << "Error: Maximum seats must be greater than 0." << endl;
        }
    }

    void setNumRows(int rows) {
        if (rows > 0) {
            numRows = rows;
        } else {
            cout << "Error: Number of rows must be greater than 0." << endl;
        }
    }

    void setNumZones(int zones) {
        if (zones > 0) {
            numZones = zones;
        } else {
            std::cerr << "Error: Number of zones must be greater than 0." << std::endl;
        }
    }

    void setSeatsPerRow(int seats) {
        if (seats > 0) {
            seatsPerRow = seats;
        } else {
            cout << "Error: Seats per row must be greater than 0." << endl;
        }
    }

    //Overload << operator for output
    friend istream& operator>>(istream& in, EventLocation& e)
    {
        cout << "Location name: ";
        in >> e.locationName;
        cout << "Maximum number of seats: ";
        in >> e.maxSeats;
        cout << "Number of rows: ";
        in >> e.numRows;
        cout << "Number of zones: ";
        in >> e.numZones;
        cout << "Number of seats per row: ";
        in >> e.seatsPerRow;
    }

    //Overload >> operator for input
    friend ostream& operator<<(ostream& out, EventLocation e)
    {
        out << "Location name: " << e.locationName << endl;
        out << "Maximum number of seats: " << e.maxSeats << endl;
        out << "Number of rows: " << e.numRows << endl;
        out << "Number of zones: " << e.numZones << endl;
        out << "Number of seats per row: " << e.seatsPerRow << endl;
    }

    // ++ operator
    EventLocation operator++()
	{
		this->numZones ++;
		return *this;
	}

    // + operator
	EventLocation operator+(int valoare)
	{
		EventLocation copie = *this;
		copie.maxSeats += valoare;
		return copie;
	}


    // Method to check if a seat is valid
    bool isSeatValid(int row, int seat) const {
        return row > 0 && row <= numRows && seat > 0 && seat <= seatsPerRow;
    }

    // Method to check if the event location is suitable for large events
    bool isSuitableForLargeEvents(int guests) const {
        return maxSeats >= guests;
    }
};