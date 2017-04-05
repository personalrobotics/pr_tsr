#ifndef PR_TSR_POP_TARTS_HPP
#define PR_TSR_POP_TARTS_HPP

#include <Eigen/Core>
#include <aikido/constraint/TSR.hpp>
#include <dart/math/math.hpp>

namespace pr_tsr
{

/// This creates a TSR that allows you to sample poses on the table.
/// The sampled poses will have z-axis point up, normal to the table top.
/// The xy-plane of the sampled of the sample poses will be parallel to the
/// table surface.
///
/// The samples from this TSR should be used to find points for object
/// placement. They are directly on the table, and thus not suitable as an
/// end-effector pose. Grasp specific calculations are necessary to find a
/// suitable end-effector pose.
aikido::constraint::TSR getDefaultPopTartsTSR()
{
  using Eigen::Isometry3d;
  aikido::constraint::TSR tsr;

  // Transform w.r.t root
  tsr.mT0_w = Eigen::Isometry3d::Identity();

  double length = 0.08;
  double width = 0.08;
  double height = 0.16;
  double lateral_tolerance = 0.02;

  // Transform between end effector and w
  Isometry3d Tw_e = tsr.mT0_w;

  // Top face
  Tw_e.translation() = Eigen::Vector3d{0, 0, height};
  Eigen::Matrix3d rot;
  rot << 0, 1, 0,
        1, 0, 0,
        0, 0, 1;
  Tw_e.linear() = rot;
  tsr.mTw_e = Tw_e;

  // Bw
  Eigen::MatrixXd Bw = Eigen::Matrix<double, 6, 2>::Zero();
  double padding = 0.0;
  // move along x and z directios to get any point on table
  Bw(1, 0) = -lateral_tolerance;   Bw(1, 1) = lateral_tolerance;
  tsr.mBw = Bw;

  // TODO:
  // generate multiple TSRs for multiple faces
  // add wrapper to hand over an array of TSR

  return tsr;

}
}
#endif // PR_TSR_POP_TARTS_HPP