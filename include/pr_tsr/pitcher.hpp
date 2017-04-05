#ifndef PR_TSR_PITCHER_HPP
#define PR_TSR_PITCHER_HPP

#include <Eigen/Core>
#include <aikido/constraint/TSR.hpp>
#include <dart/math/math.hpp>

namespace pr_tsr
{

aikido::constraint::TSR getDefaultPitcherTSR()
{
  using Eigen::Isometry3d;
  aikido::constraint::TSR tsr;

  // Transform w.r.t root
  tsr.mT0_w = Eigen::Isometry3d::Identity();

  // Transform between end effector and w
  Isometry3d Tw_e = tsr.mT0_w;

  Eigen::Matrix4f spout_in_pitcher;
  spout_in_pitcher << -0.7956,  0.6057, 0., -0.0662,
                      -0.6057, -0.7956, 0., -0.0504,
                       0.,      0.,     1.,  0.2376,
                       0.,      0.,     0.,  1.;
  double spout_direction = atan2(
    spout_in_pitcher(0, 1),
    spout_in_pitcher(0, 0));
  double palm_direction = spout_direction - 0.5 * M_PI;

  Eigen::Matrix3d ee_rot;
  ee_rot << 0, 0, 1,
            -1, 0, 0,
            0, -1, 0;

  Eigen::Matrix3d palm_rot;
  palm_rot = Eigen::AngleAxisd(0, Eigen::Vector3d::UnitZ()) *
             Eigen::AngleAxisd(palm_direction, Eigen::Vector3d::UnitY()) *
             Eigen::AngleAxisd(0, Eigen::Vector3d::UnitX()); 

  ee_rot = ee_rot * palm_rot;
  Tw_e.linear() = ee_rot;

  double pitcher_extents[] = {0.07877473, 0.06568845, 0.11882638};
  double push_distance = 0.1;
  double offset = pitcher_extents[0] + 0.18 + push_distance;
  Tw_e(0, 3) = -offset * Tw_e(0, 2);
  Tw_e(1, 3) = -offset * Tw_e(1, 2);
  Tw_e(2, 3) = 0.45 * pitcher_extents[2];

  tsr.mTw_e = Tw_e;

  // Bw
  Eigen::MatrixXd Bw = Eigen::Matrix<double, 6, 2>::Zero();
  Bw(2, 0) = -0.01;   Bw(2, 1) = 0.01;
  tsr.mBw = Bw;

  return tsr;

}
}
#endif // PR_TSR_PITCHER_HPP