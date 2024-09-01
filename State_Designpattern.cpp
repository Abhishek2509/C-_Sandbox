#include <iostream>

using namespace std;

// State Interface
class TrafficLightState {
public:
    virtual void handle() = 0;
};

// Concrete States
class RedState : public TrafficLightState {
public:
    void handle() override
    {
        std::cout<<"\nTraffic Light is Red";
    }
};

class YellowState : public TrafficLightState {
public:
    void handle() override
    {
        std::cout<<"\nTraffic Light is Yellow";
    }
};

class GreenState : public TrafficLightState {
public:
    void handle() override
    {
        std::cout<<"\nTraffic Light is Grren";
    }
};

// Context
class TrafficLight {
private:
    TrafficLightState* state;

public:
    TrafficLight()
        : state(new RedState())
    {
    }

    void setState(TrafficLightState* newState)
    {
        delete state;
        state = newState;
    }

    void change() { 
        state->handle(); 
        
    }
};

int main()
{
    TrafficLightState *obj = new RedState();
    TrafficLight trafficLight;

    trafficLight.change(); // Initial state: Red
    trafficLight.setState(new GreenState());
    trafficLight.change(); // State changed to Green

    return 0;
}
