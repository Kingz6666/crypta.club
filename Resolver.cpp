// TESTING.
// PROJECT NOT SDK ITS GIDE FOR NN CODERS.
void ThisResolver::Resolver(player_t* player)
{
const auto animstate = player->anim_state();

if (!animstate)
  return;

float new_body_yaw = 0.0f;
auto diff_yaw = math::angle_difference(player->eye_angles().y, player->anim_state()->goal_feet_yaw) > 0 ? 1 : -1;

if ( diff_yaw < 0 && new_body_yaw == 0.0 )
{
new_body_yaw = diff_yaw / animstate->pad10[512]; // min body yaw.
}
{
new_body_yaw = diff_yaw / animstate->pad10[516]; // max body yaw.
}
  
  
  void AntiFreeStandTarget(player_t* player, float right_damage, float left_damage, float calculate_damage, int static_damage, bool is_damage)
  {
   float is_damage_calculate = 0.0f;
    
    left_damage = 90.f;
    right_damage = 90.f;
    static_damage = 180;
    is_damage = false;
    float main_damage = c_autowall::get().calculate_damage_scale(player)
    
    static_damage > 0; // ok.
    
    if ( calculate_damage )
    {
     calculate_damage = static_damage + main_damage < 0;
    //  is_damage = true;
    }
    else
    {
     is_damage_calculate  >= main_damage; 
    }
    
    if ( static_damage ) // back
    {
     left_damage >= right_damage <= static_damage;
       is_damage = true;
    }
/*else
{
 is_damage = true; 
}*/
  }
