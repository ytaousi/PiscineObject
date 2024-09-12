#ifndef FACADE_HPP
#define FACADE_HPP

class Subsystem1 {
 public:
  std::string cordinateTravel(Train *modelX) const {
    std::cout << "- departure houre\n
                  - departure Station\n
                  - arrival Station\n
                  - train model\n
                  - rails clearance\n";
    modelX->setHourOfDeparture("13:42");
    modelX->setDepartureStation("Kesh");
    modelX->setArrivalStation("FinLand");
    
    return "Train Ready To go Verify Rails Clearance\n"; 
  }
  // ...
  void constructRailwaynetwork(std::vector<Node *>, std::vector<Rail *>) const {
    return "cities and rail segments\n";
  }
  void railsClearancepathfinding() const {
  };
  void estimateTravelTime() {// events - rails clearance - train model
  };

};

class Subsystem2 {
 public:
  std::string Operation1() const {
    return "Subsystem2: Get ready!\n";
  }
  // ...
  std::string OperationZ() const {
    return "Subsystem2: Fire!\n";
  }
};

class Facade {
    protected:
    Subsystem1 *subsystem1_;
    // Subsystem2 *subsystem2_;
    std::vector<Node *> _nodes;
    std::vector<Rail *> _rails;
    std::vector<Event *> _events;
    std::vector<Train *> _trains;
    public:
  
  Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr) {
    this->subsystem1_ = subsystem1 ?: new Subsystem1;
    // this->subsystem2_ = subsystem2 ?: new Subsystem2;
    this->subsytem1_->railsClearancepathfinding(_rails, _nodes);
    this->subsytem1_->cordinateTravel(_trains[0]); // <--
    this->subsytem1_->estimateTravelTime(_events);
  }
  ~Facade() {
    delete subsystem1_;
    // delete subsystem2_;
  }
  void setNetworkrailscomponents(std::vector<Node *> nodes, std::vector<Rail *> rails, std::vector<Event *> events, std::vector<Train *> trains) {
    this->_nodes = nodes;
    this->_rails = rails;
    this->_events = events;
    this->_trains = trains;
  }
};

#endif