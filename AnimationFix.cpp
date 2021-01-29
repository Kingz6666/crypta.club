void FrameStageNotify(FrameStage* notify) 
{
  	if (stage != FRAME_NET_UPDATE_END)
		return;

	if (!g_cfg.ragebot.enable && !g_cfg.legitbot.enabled)
		return;

	for (auto i = 1; i < m_globals()->m_maxclients; i++)
	{
		auto e = static_cast<player_t*>(m_entitylist()->GetClientEntity(i));

		if (e == g_ctx.local())
			continue;

		if (!valid(i, e))
			continue;

		auto time_delta = abs(TIME_TO_TICKS(player->m_flSimulationTime()) - get_global()->m_tickcount);

		if (time_delta > 1.0f / get_global()->m_intervalpertick)
			continue;

		auto update = player_records[i].empty() || player->m_flSimulationTime() <= player->m_flOldSimulationTime();

		if (update)
		{
			if (!player_records[i].empty() && (e->m_vecOrigin() - player_records[i].front().origin).LengthSqr() > 4096.0f)
				for (auto& record : player_records[i])
					record.invalid = true;

			player_records[i].emplace_front(adjust_data());
			UpdateAnimations(player);

			while (player_records[i].size() > 32)
				player_records[i].pop_back();
		}
	}
}


void UpdateAnimations(player_t* player)
{
}

CMBackTrack get_record()
{
}
