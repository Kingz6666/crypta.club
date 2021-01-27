// TESTING.
// PROJECT NOT SDK ITS GIDE FOR NN CODERS.
float new_body_yaw = 0.0f;
auto diff_yaw = math::angle_difference(player->eye_angles().y, player->anim_state()->goal_feet_yaw) -1;

if ( diff_yaw < 2.0f && !new_body_yaw < 0.0f )
{
new_body_yaw = diff_yaw / animstate->pad10[512]; // min body yaw.
}
{
new_body_yaw = diff_yaw / animstate->pad10[516]; // max body yaw.
}
