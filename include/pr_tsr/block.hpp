#ifndef PR_TSR_BLOCK_HPP
#define PR_TSR_BLOCK_HPP

#include <Eigen/Core>
#include <aikido/constraint/TSR.hpp>
#include <dart/math/math.hpp>

namespace pr_tsr
{
aikido::constraint::TSR getDefaultBlockTSR()
{
  using Eigen::Isometry3d;
  aikido::constraint::TSR tsr;

  // Transform w.r.t root
  tsr.mT0_w = Eigen::Isometry3d::Identity();

  // Transform between end effector and w
  double block_height = 0.216; 
  double block_width = 0.05;
  Isometry3d Tw_e = tsr.mT0_w;
  Tw_e.translation() = Eigen::Vector3d{-block_width, 0, block_height/2.0};
  tsr.mTw_e = Tw_e;

  // Rotation around fuze
  Eigen::MatrixXd Bw = Eigen::Matrix<double, 6, 2>::Zero();
  Bw(5,0) = -M_PI;
  Bw(5,1) = M_PI;
  tsr.mBw = Bw;

  return tsr;

}
}
#endif // PR_TSR_BLOCK_HPP