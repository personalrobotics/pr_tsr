#ifndef PR_TSR_VALVE_HPP
#define PR_TSR_VALVE_HPP

#include <Eigen/Core>
#include <aikido/constraint/TSR.hpp>
#include <dart/math/math.hpp>

namespace pr_tsr
{
aikido::constraint::TSR getDefaultValveTSR()
{
  using Eigen::Isometry3d;
  aikido::constraint::TSR tsr;

  // copied out of valve_turning/valve.hpp
  Eigen::Isometry3d wheel_jnt_tf{Eigen::Isometry3d::Identity()};
  wheel_jnt_tf.linear() =
      dart::math::eulerXYZToMatrix(Eigen::Vector3d(M_PI / 2, 0, 0));
  wheel_jnt_tf.translation() = Eigen::Vector3d{.095, 0, .1};

  Isometry3d T0_w = wheel_jnt_tf;
  T0_w.translation() += Eigen::Vector3d{0, -0.1, 0};
  tsr.mT0_w = T0_w;

  // TODO put this at surface
  Isometry3d Tw_e = Isometry3d::Identity();
  Tw_e.linear() = dart::math::eulerXYZToMatrix(Eigen::Vector3d{M_PI, 0, 0});
  Tw_e.translation() = Eigen::Vector3d{0.1, 0, 0};
  tsr.mTw_e = Tw_e;

  Eigen::MatrixXd Bw = Eigen::Matrix<double, 6, 2>::Zero();
  Bw(5, 1) = 2 * M_PI;
  tsr.mBw = Bw;

  return tsr;
};
}
#endif  // PR_TSR_VALVE_HPP
