#pragma once

#include "SensorConfig.h"
#include "meta/ICameraConfig.h"


namespace A2O {

/**
 * The CameraConfig represents a Camera sensor configuration.
 * 
 * \author Stefan Glaser
 */
class CameraConfig : public SensorConfig, public virtual ICameraConfig {
public:
  CameraConfig(const std::string& name,
	       const Eigen::Vector3d& position,
	       const Eigen::AngleAxisd& orientation,
	       const unsigned int& widht,
	       const unsigned int& height,
	       const float& focalLengthX,
	       const float& focalLengthY);
  CameraConfig(const std::string& name,
	       const std::string& perceptorName, 
	       const Eigen::Vector3d& position,
	       const Eigen::AngleAxisd& orientation,
	       const unsigned int& widht,
	       const unsigned int& height,
	       const float& focalLengthX,
	       const float& focalLengthY);
  virtual ~CameraConfig();

  virtual const unsigned int& getFrameWidth() const;
  virtual const unsigned int& getFrameHeight() const;
  virtual const float& getFocalLengthX() const;
  virtual const float& getFocalLengthY() const;
  
private:
  /** The width of the camera image. */
  unsigned int _imageWidth;
  
  /** The height of the camera image. */
  unsigned int _imageHeight;
  
  /** The focal length in x direction. */
  float _focalLengthX;
  
  /** The focal length in y direction. */
  float _focalLengthY;
};

}
