////////////////////////////////////////////////////////////////////////
// $Id: RawDrawingOption.h,v 1.15 2010/08/30 21:33:24 spitz7 Exp $
//
// Display parameters for the raw data
//
// \author brebel@fnal.gov
////////////////////////////////////////////////////////////////////////
#ifndef RAWDRAWINGOPTIONS_H
#define RAWDRAWINGOPTIONS_H
#ifndef __CINT__
#include <string>
#include <vector>

#include "fhiclcpp/ParameterSet.h"
#include "art/Framework/Services/Registry/ActivityRegistry.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Services/Registry/ServiceMacros.h"
#include "art/Utilities/InputTag.h"

namespace evd {
  class RawDrawingOptions 
  {
  public:
    RawDrawingOptions(fhicl::ParameterSet const& pset, art::ActivityRegistry& reg);
    ~RawDrawingOptions();

    void reconfigure(fhicl::ParameterSet const& pset);
    
    int          fDrawRawDataOrCalibWires;                 ///< 0 for raw							  
    int    	     fTicksPerPoint;                           ///< number of ticks to include in one point
    int    	     fScaleDigitsByCharge;                     ///< scale the size of the digit by the charge
    double 	     fMinSignal;                               ///< minimum ADC count to display a time bin
    double       fStartTick;                               ///< Starting tick for the display
    double 	     fTicks;                                   ///< number of TDC ticks to display, ie # fTicks past fStartTick
    int    	     fAxisOrientation;                         ///< 0 = TDC values on y-axis, wire number on x-axis, 1 = swapped
    unsigned int fTPC;                                     ///< TPC number to draw, typically set by TWQProjectionView
    unsigned int fCryostat;                                ///< Cryostat number to draw, typically set by TWQProjectionView
    unsigned int fMinChannelStatus;                        ///< Display channels with this status and above
    unsigned int fMaxChannelStatus;                        ///< Display channels with this status and below
    bool         fUncompressWithPed;                       ///< Option to uncompress with pedestal. Turned off by default
    art::InputTag fRawDataLabel;                            ///< module label that made the raw digits, default is daq
  };
}//namespace
#endif // __CINT__
DECLARE_ART_SERVICE(evd::RawDrawingOptions, LEGACY)
#endif

