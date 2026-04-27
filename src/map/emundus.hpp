#ifndef EMUNDUS_HPP
#define EMUNDUS_HPP

#include "pc.hpp"          // Para map_session_data e sd->bonus
#include "status.hpp"      // Para SC_*
#include "clif.hpp"        // Para clif_changeoption()
#include "itemdb.hpp"      // Para item_db

class map_session_data;

void CheckSetBonus(map_session_data* sd);
void UpdateSmokeStatus(map_session_data* sd);

// 03/03/2026
//void emd_countcombo(map_session_data* sd, item_data* item);
int em_study_combo_item(map_session_data* sd, item_data* item);
//void emd_list_active_combos(map_session_data* sd);

#endif
