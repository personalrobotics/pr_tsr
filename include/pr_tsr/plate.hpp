#ifndef PR_TSR_PLATE_HPP
#define PR_TSR_PLATE_HPP

#include <Eigen/Core>
#include <aikido/constraint/dart/TSR.hpp>
#include <dart/math/math.hpp>

namespace pr_tsr
{
// The default plate tsr allows you to view the whole 
// plate from a point above
aikido::constraint::dart::TSR getDefaultPlateTSR()
{
  using Eigen::Isometry3d;
  aikido::constraint::dart::TSR tsr;

  // Transform w.r.t root
  tsr.mT0_w = Eigen::Isometry3d::Identity();

  // Transform between end effector and w
  double plate_height = 0.005;
  double plate_radius = 0.125;
  double vertical_offset = 0.15;
  double view_radius = 0.001;

  Isometry3d Tw_e = tsr.mT0_w;
  Tw_e.translation() = Eigen::Vector3d{0, 0, vertical_offset};
  tsr.mTw_e = Tw_e;

  // Rotation around object
  Eigen::MatrixXd Bw = Eigen::Matrix<double, 6, 2>::Zero();
  double vertical_tolerance_low = 0.05;
  double vertical_tolerance_high = 0.06;
  Bw(1, 0) = -view_radius;
  Bw(1, 1) = view_radius;
  Bw(2, 0) = vertical_tolerance_low;
  Bw(2, 1) = vertical_tolerance_high;
  Bw(5, 0) = -M_PI;
  Bw(5, 1) = M_PI;
  tsr.mBw = Bw;

  return tsr;
}
}
#endif // PR_TSR_PLATE_HPP
