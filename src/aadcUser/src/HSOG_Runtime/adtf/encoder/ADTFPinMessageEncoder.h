#pragma once

#include "action/IAction.h"
#include "action/IEffector.h"
#include "action/IManeuverStatusEffector.h"
#include "meta/ICarMetaModel.h"
#include "OutputPin.h"

#include <adtf_platform_inc.h>
#include <adtf_plugin_sdk.h>
#include <vector>
#include <boost/smart_ptr.hpp>

namespace A2O {

/**
 * The ADTFPinMessageEncoder is responsible for mapping the internal effectors to output-pins a an ADTF-Filter.
 * 
 * \author Stefan Glaser
 */
class ADTFPinMessageEncoder {
public:
  typedef boost::shared_ptr<ADTFPinMessageEncoder> Ptr;
  typedef boost::shared_ptr<const ADTFPinMessageEncoder> ConstPtr;
  
  ADTFPinMessageEncoder(IAction::Ptr action,
			ICarMetaModel::ConstPtr carMetaModel);
  virtual ~ADTFPinMessageEncoder();

  virtual int indexOfPin(OutputPin pin) const;
  virtual const std::vector<OutputPin>& getOutputPins();
  virtual bool encode(const OutputPin& pin,
		      adtf::IMediaTypeDescription* mediaTypeDescription,
		      adtf::IMediaSample* mediaSample);
  
protected:
  /** The Action component. */
  IAction::Ptr _action;
  
  /** The outout pins of the encoder. */
  std::vector<A2O::OutputPin> _pins;
};

}
