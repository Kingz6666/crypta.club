// TESTING.
// PROJECT NOT SDK ITS GIDE FOR NN CODERS.

const auto animstate = player->anim_state();

if (!animstate)
  return;

float new_body_yaw = 0.0f;
auto diff_yaw = math::angle_difference(player->eye_angles().y, player->anim_state()->goal_feet_yaw) -1;

if ( diff_yaw < 2.0f && !new_body_yaw < 0.0f )
{
new_body_yaw = diff_yaw / animstate->pad10[512]; // min body yaw.
}
{
new_body_yaw = diff_yaw / animstate->pad10[516]; // max body yaw.
}

if ( diff_yaw > 58 && diff_yaw == -58 )
{
return new_body_yaw;
}
else
{
 new_body_yaw =  animstate->goal_feet_yaw;
}

if ( animstate->abs_yaw != 0.0 )
{
animstate->goal_feet_yaw = diff_yaw / 2;
}
else
{
animstate->goal_feet_yaw = diff_yaw / 1;//return animstate->abs_yaw;
}
