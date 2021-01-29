// TESTING.
// PROJECT NOT SDK ITS GIDE FOR NN CODERS.
void ThisResolver::Resolver(player_t* player)
{
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

/*if ( diff_yaw > 58 && diff_yaw == -58 )
{
return new_body_yaw;
}
else
{
 new_body_yaw =  animstate->goal_feet_yaw;
}*/

if ( animstate->abs_yaw != 0.0 )
{
animstate->goal_feet_yaw = diff_yaw / next_side();
}
}

void next_side()
{
  auto next_side_time = player->m_simulationTime() - player->m_oldsimulationTime();
  Vector body_yaw_zero = ZERO;
  
  if (get_globals()->m_curtime > 2.0f)
  {
   next_side_time = get_globals()->m_crutime; // apply switch desync or break stand lower body yaw. 
  }
  else
  {
  next_side_time = player->lower_body_yaw()/* == animstate->max_yaw && !player->lower_body_yaw()*/;
  }
  
/*  if ( get_globals()->m_curtime < 0.0f )
  {
    next_side_time > body_yaw_zero; /*player->lower_body_yaw() = 0.0; // static update lby.
  }
  else
  {
   player->lower_body_yaw() = 0.0; 
  } */
}
