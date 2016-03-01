/****************************************************************************/
/// @file    SniffBluetoothLEAdv.h
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @author  second author name
/// @date    Feb 2016
///
/****************************************************************************/
// VENTOS, Vehicular Network Open Simulator; see http:?
// Copyright (C) 2013-2015
/****************************************************************************/
//
// This file is part of VENTOS.
// VENTOS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef ADVERTISEBEACON
#define ADVERTISEBEACON

#include "04_SniffBluetoothLE.h"

namespace VENTOS {

class AdvertiseBeacon : public SniffBluetoothLE
{
public:
    virtual ~AdvertiseBeacon();
    virtual void finish();
    virtual void initialize(int);
    virtual void handleMessage(cMessage *);

protected:
    void executeFirstTimeStep();
    void executeEachTimestep();

private:
    void advertiseBeacon();
    void no_le_adv(int hdev);
    void le_adv(int hdev, uint8_t type);
    std::string generateBeacon();

private:
    // NED variables
    bool advertisement;
    int beaconType;

    // iBeacon parameters
    std::string iBeacon_UUID;
    std::string iBeacon_major;
    std::string iBeacon_minor;
    std::string iBeacon_TXpower;

    // AltBeacon parameters
    std::string AltBeacon_MFGID;
    std::string AltBeacon_beaconID;
    std::string AltBeacon_refRSSI;
    std::string AltBeacon_MFGRSVD;
};

}

#endif