// TESTING.

float new_body_yaw = 0.0f;
auto diff_yaw = math::angle_difference(player->eye_angles().y, player->anim_state()->goal_feet_yaw;

if ( diff_yaw < 2.0f && !new_body_yaw < 0.0f )
{
return;
}
