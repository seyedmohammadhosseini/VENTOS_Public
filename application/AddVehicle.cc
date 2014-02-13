
#include "AddVehicle.h"

#include <sstream>
#include <iostream>
#include <fstream>

Define_Module(AddVehicle);


AddVehicle::~AddVehicle()
{

}


void AddVehicle::initialize(int stage)
{
    if(stage ==0)
    {
        // get the ptr of the current module
        nodePtr = FindModule<>::findHost(this);
        if(nodePtr == NULL)
            error("can not get a pointer to the module.");

        // get a pointer to the manager module
        cModule *module = simulation.getSystemModule()->getSubmodule("manager");
        manager = static_cast<TraCI_Extend *>(module);

        on = par("on").boolValue();
        mode = par("mode").longValue();
        platoonSize = par("platoonSize").longValue();
        platoonNumber = par("platoonNumber").longValue();
        totalVehicles = par("totalVehicles").longValue();
    }
}


void AddVehicle::handleMessage(cMessage *msg)
{

}


void AddVehicle::Add()
{
    // if dynamic adding is not on, return
    if (!on)
        return;

    if(mode == 1)
    {
        Scenario1();
    }
    else if(mode == 2)
    {
        Scenario2();
    }
}


void AddVehicle::Scenario1()
{


}


void AddVehicle::Scenario2()
{
    for(int i=1; i<=totalVehicles; i++)
    {
        char vehicleName[10];
        sprintf(vehicleName, "CACC%d", i);
        int depart = 1000 * i;

        if( (i-1) % platoonSize == 0 )
        {
            // platoon leader
          //  manager->commandAddVehicleN(vehicleName,"TypeCACC1","route1",depart);
            manager->commandAddVehicleN(vehicleName,"TypeACC1","route1",depart);
        }
        else
        {
            // following vehicle
         //   manager->commandAddVehicleN(vehicleName,"TypeCACC2","route1",depart);
            manager->commandAddVehicleN(vehicleName,"TypeACC1","route1",depart);
        }
    }
}


void AddVehicle::finish()
{


}
