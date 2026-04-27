// emundus.cpp
// Criado com intuito de aprendizado e estudo!
#include "common/cbasetypes.hpp" // tipos básicos
#include "char/char.hpp"              // CharData, map_session_data (não precisa de char/char.hpp, o include relativo basta)
#include "status.hpp"            // SC_SMOKE_*
#include "itemdb.hpp"            // item_db, std::shared_ptr<item_data>
#include "script.hpp"            // scripts, se usar
#include "pc.hpp"                // pc_isSmokeGear, OPTION_SMOKE, pc_iswearing
#include "clif.hpp"              // clif_changeoption
#include "map.hpp"               // map data se precisar
#include "common/showmsg.hpp"    // mensagens de debug
#include "battle.hpp"            // status_change_end, sc_start
#include "emundus.hpp"          // sua própria header

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

void UpdateSmokeStatus(map_session_data* sd) {
	if (!sd) return;
	CheckSetBonus(sd);  // delega toda a lógica para CheckSetBonus

	/*// Atualiza o COUNT de todos os combos
	int count = 0;

	// percorre todos os combos ativos
	for (auto& combo : sd->em_active_combos) {
		count++;               // incrementa o total
	}

	// agora que temos o total, atualiza o campo count de cada combo
	for (auto& combo : sd->em_active_combos) {
		combo.count = count;
	}

	// retorna o total de combos ativos
	return count;*/

}

// ============================
// 2. Funções de StateIcon / SetBonus
// ============================

struct SetBonus {
	int stateicon_id;      // ID do stateicon
	vector<int> item_ids;  // IDs das peças do conjunto
};

vector<SetBonus> custom_set_bonuses;


//=============== Emundus
// Procurar o combo smoke ativo
// Definir qual SC aplicar(via active_combo_id)
// Limpar os SCs antigos
// Aplicar o SC correto
// Armazena todos combos ativos
void CheckSetBonus(map_session_data* sd)
{
	if (!sd)
		return;
	//ShowDebug("CheckSetBonus chamado. Prog: %d\n", sd->special_state.smoke_gear_prog);
	// 🔹 Remove todos os efeitos primeiro
	clif_status_change(sd, EFST_SMOKE_GODLIKE, 0, 0, 0, 0, 0);
	clif_status_change(sd, EFST_SMOKE_PHOENIX, 0, 0, 0, 0, 0);
	clif_status_change(sd, EFST_SMOKE_AZUR, 0, 0, 0, 0, 0);
	clif_status_change(sd, EFST_SMOKE_ASCENSION, 0, 0, 0, 0, 0);

	int effect = 0;

	// 🔹 Decide qual efeito aplicar baseado no BONUS
	switch (sd->special_state.smoke_gear_prog)
	{
	case 1:
		effect = EFST_SMOKE_GODLIKE;
		break;

	case 2:
		effect = EFST_SMOKE_PHOENIX;
		break;

	case 3:
		effect = EFST_SMOKE_AZUR;
		break;

	case 4:
		effect = EFST_SMOKE_ASCENSION;
		break;

	default:
		effect = 0;
		break;
	}

	// 🔹 Aplica efeito infinito se existir
	if (effect)
		clif_status_change(sd, effect, 1, INFINITE_TICK, 0, 0, 0);
}

// ============================
// 3. Inicialização e hooks
// ============================

// Chamar ao iniciar o servidor
//void InitEmundus() {
	//InitCustomCombos();
	// Você pode adicionar sets manualmente ou criar função que lê do db final se necessário
//}

// Hook após equipar/remover item
//void OnPlayerEquipChange(map_session_data* sd, item_data* item) {
//	CheckSetBonus(sd);
//}

// Converte ScriptCode em Texto
std::string emd_scriptcode_to_text(s_item_combo* combo)
{
	if (!combo) return "";

	// Usa diretamente a string legível salva no combo
	return combo->script_text;
}

// Contagem de ComboItem - Estudo
// ======================================
int em_study_combo_item(map_session_data* sd, item_data* item)
{
	int combos_ativos = 0;

	if (!sd || !item)
		return 0;

	// =====================================
	// 1️⃣ Adiciona combos completos
	// =====================================
	for (const auto& combo_ptr : item->combos) { // combo_ptr é shared_ptr<s_item_combo>
		s_item_combo& combo = *combo_ptr;        // referência direta

		uint16 combo_id = combo.id;

		// Verifica se o jogador possui todos os itens do combo
		bool combo_completed = true;
		for (t_itemid required_id : combo.nameid) {
			bool found = false;
			for (int16 i = 0; i < EQI_MAX; i++) {
				int16 idx = sd->equip_index[i];
				if (idx < 0) continue;

				item_data* equipped_item = sd->inventory_data[idx];
				if (!equipped_item) continue;

				if (equipped_item->nameid == required_id) {
					found = true;
					break;
				}
			}
			if (!found) {
				combo_completed = false;
				break;
			}
		}

		// Procura se o combo já está registrado
		auto it = std::find_if(
			sd->em_active_combos.begin(),
			sd->em_active_combos.end(),
			[combo_id](const em_active_combo_t& ac) { return ac.combo_id == combo_id; }
		);

		// Adiciona se completo e ainda não registrado
		if (combo_completed && it == sd->em_active_combos.end()) {
			sd->em_active_combos.emplace_back();
			auto& novo = sd->em_active_combos.back();
			novo.combo_id = combo_id;
			novo.script_text = combo.script_text;
			combos_ativos++;
		}
		// Remove se não estiver mais completo
		else if (!combo_completed && it != sd->em_active_combos.end()) {
			sd->em_active_combos.erase(it);
			combos_ativos--;
		}
	}
	return combos_ativos;
}

//void emd_countcombo(map_session_data* sd, item_data* item) {
//	// Simplesmente chama a função modular
//	em_study_combo_item(sd, item);
//}

/*void emd_list_active_combos(map_session_data* sd) {
	if (sd->em_active_combos.empty()) {
		clif->message(sd->fd, "Nenhum combo ativo.");
		return;
	}

	clif->message(sd->fd, "=== Combos Ativos ===");
	for (auto& ac : sd->em_active_combos) {
		clif->message(sd->fd, ac.script_text.c_str()); // Exibe o script legível
	}
}*/

// Comandos personalizados
/*ACMD_FUNC(meucomando) {  // Nome da função: ACMD_FUNC(nome_do_comando_sem_o_@)
    // sd = map_session_data* do player que usou o comando
    // fd = file descriptor (para clif_displaymessage)
    // message = o texto após o @comando (parâmetros)

    if (!sd) return 0;  // Segurança: se não tiver player

    clif_displaymessage(fd, "It works! Comando executado com sucesso.");

    // Exemplo de efeito visual no player
    clif_specialeffect(&sd->bl, EF_HEARTCASTING, AREA);

    // Opcional: mensagem no console do map-server (para debug)
    ShowInfo("Player %s usou @meucomando\n", sd->status.name);

    return 0;
}
// Depois coloca ele em atcommand_def.inc
ACMD_DEF(meucomando),  // Isso registra @meucomando
// adiciona ao grupo em groups.yml
*/
