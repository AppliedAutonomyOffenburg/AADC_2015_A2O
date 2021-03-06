#pragma once

#include <chrono>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/PointIndices.h>
#include <pcl/filters/extract_indices.h>


#include "utils/concurrency/Runnable.h"

#include "utils/pcl/utils.h"
#include "utils/geometry/Pose2D.h"
#include "utils/geometry/AlignedBoundingBox3D.h"
#include "IResource.h"




namespace A2O {
  
class PointCloudWorker : public Runnable
{
public:
  PointCloudWorker(IResource *resource);
  ~PointCloudWorker();
  
protected:
  IResource *_resource;
  void run();
  
private:
  /** Retrieve indices from segments in the cloud */
  std::vector <pcl::PointIndices> segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud);
  /** Retrieve an oriented bounding box from given point cloud */
  AlignedBoundingBox3D::Ptr boundingBox(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud);
};
};
