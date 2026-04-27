#
# Table structure for table `mob_db2_re`
#

DROP TABLE IF EXISTS `mob_db2_re`;
CREATE TABLE `mob_db2_re` (
  `id` int(11) unsigned NOT NULL,
  `name_aegis` varchar(24) DEFAULT NULL,
  `name_english` text DEFAULT NULL,
  `name_japanese` text DEFAULT NULL,
  `level` smallint(6) unsigned DEFAULT NULL,
  `hp` int(11) unsigned DEFAULT NULL,
  `sp` mediumint(9) unsigned DEFAULT NULL,
  `base_exp` int(11) unsigned DEFAULT NULL,
  `job_exp` int(11) unsigned DEFAULT NULL,
  `mvp_exp` int(11) unsigned DEFAULT NULL,
  `attack` smallint(6) unsigned DEFAULT NULL,
  `attack2` smallint(6) unsigned DEFAULT NULL,
  `defense` smallint(6) unsigned DEFAULT NULL,
  `magic_defense` smallint(6) unsigned DEFAULT NULL,
  `resistance` smallint(6) unsigned DEFAULT NULL,
  `magic_resistance` smallint(6) unsigned DEFAULT NULL,
  `str` smallint(6) unsigned DEFAULT NULL,
  `agi` smallint(6) unsigned DEFAULT NULL,
  `vit` smallint(6) unsigned DEFAULT NULL,
  `int` smallint(6) unsigned DEFAULT NULL,
  `dex` smallint(6) unsigned DEFAULT NULL,
  `luk` smallint(6) unsigned DEFAULT NULL,
  `attack_range` tinyint(4) unsigned DEFAULT NULL,
  `skill_range` tinyint(4) unsigned DEFAULT NULL,
  `chase_range` tinyint(4) unsigned DEFAULT NULL,
  `size` varchar(24) DEFAULT NULL,
  `race` varchar(24) DEFAULT NULL,
  `racegroup_goblin` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_kobold` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_orc` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_golem` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_guardian` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ninja` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_gvg` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_battlefield` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_treasure` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_biolab` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_manuk` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_splendide` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_scaraba` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ogh_atk_def` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ogh_hidden` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_bio5_swordman_thief` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_bio5_acolyte_merchant` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_bio5_mage_archer` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_bio5_mvp` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_clocktower` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_thanatos` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_faceworm` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_hearthunter` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_rockridge` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_werner_lab` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_temple_demon` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_illusion_vampire` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_malangdo` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ep172alpha` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ep172beta` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ep172bath` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_illusion_turtle` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_rachel_sanctuary` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_illusion_luanda` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_illusion_frozen` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_illusion_moonlight` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_ep16_def` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_edda_arunafeltz` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_lasagna` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_glast_heim_abyss` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_destroyed_valkyrie_realm` tinyint(1) unsigned DEFAULT NULL,
  `racegroup_encroached_gephenia` tinyint(1) unsigned DEFAULT NULL,
  `element` varchar(24) DEFAULT NULL,
  `element_level` tinyint(4) unsigned DEFAULT NULL,
  `walk_speed` smallint(6) unsigned DEFAULT NULL,
  `attack_delay` smallint(6) unsigned DEFAULT NULL,
  `attack_motion` smallint(6) unsigned DEFAULT NULL,
  `damage_motion` smallint(6) unsigned DEFAULT NULL,
  `damage_taken` smallint(6) unsigned DEFAULT NULL,
  `groupid` smallint(6) unsigned DEFAULT NULL,
  `title` text DEFAULT NULL,
  `ai` varchar(50) DEFAULT NULL,
  `class` varchar(50) DEFAULT NULL,
  `mode_canmove` tinyint(1) unsigned DEFAULT NULL,
  `mode_looter` tinyint(1) unsigned DEFAULT NULL,
  `mode_aggressive` tinyint(1) unsigned DEFAULT NULL,
  `mode_assist` tinyint(1) unsigned DEFAULT NULL,
  `mode_castsensoridle` tinyint(1) unsigned DEFAULT NULL,
  `mode_norandomwalk` tinyint(1) unsigned DEFAULT NULL,
  `mode_nocast` tinyint(1) unsigned DEFAULT NULL,
  `mode_canattack` tinyint(1) unsigned DEFAULT NULL,
  `mode_castsensorchase` tinyint(1) unsigned DEFAULT NULL,
  `mode_changechase` tinyint(1) unsigned DEFAULT NULL,
  `mode_angry` tinyint(1) unsigned DEFAULT NULL,
  `mode_changetargetmelee` tinyint(1) unsigned DEFAULT NULL,
  `mode_changetargetchase` tinyint(1) unsigned DEFAULT NULL,
  `mode_targetweak` tinyint(1) unsigned DEFAULT NULL,
  `mode_randomtarget` tinyint(1) unsigned DEFAULT NULL,
  `mode_ignoremelee` tinyint(1) unsigned DEFAULT NULL,
  `mode_ignoremagic` tinyint(1) unsigned DEFAULT NULL,
  `mode_ignoreranged` tinyint(1) unsigned DEFAULT NULL,
  `mode_mvp` tinyint(1) unsigned DEFAULT NULL,
  `mode_ignoremisc` tinyint(1) unsigned DEFAULT NULL,
  `mode_knockbackimmune` tinyint(1) unsigned DEFAULT NULL,
  `mode_teleportblock` tinyint(1) unsigned DEFAULT NULL,
  `mode_fixeditemdrop` tinyint(1) unsigned DEFAULT NULL,
  `mode_detector` tinyint(1) unsigned DEFAULT NULL,
  `mode_statusimmune` tinyint(1) unsigned DEFAULT NULL,
  `mode_skillimmune` tinyint(1) unsigned DEFAULT NULL,
  `mvpdrop1_item` varchar(50) DEFAULT NULL,
  `mvpdrop1_rate` smallint(9) unsigned DEFAULT NULL,
  `mvpdrop1_option` varchar(50) DEFAULT NULL,
  `mvpdrop1_index` tinyint(2) unsigned DEFAULT NULL,
  `mvpdrop2_item` varchar(50) DEFAULT NULL,
  `mvpdrop2_rate` smallint(9) unsigned DEFAULT NULL,
  `mvpdrop2_option` varchar(50) DEFAULT NULL,
  `mvpdrop2_index` tinyint(2) unsigned DEFAULT NULL,
  `mvpdrop3_item` varchar(50) DEFAULT NULL,
  `mvpdrop3_rate` smallint(9) unsigned DEFAULT NULL,
  `mvpdrop3_option` varchar(50) DEFAULT NULL,
  `mvpdrop3_index` tinyint(2) unsigned DEFAULT NULL,
  `drop1_item` varchar(50) DEFAULT NULL,
  `drop1_rate` smallint(9) unsigned DEFAULT NULL,
  `drop1_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop1_option` varchar(50) DEFAULT NULL,
  `drop1_index` tinyint(2) unsigned DEFAULT NULL,
  `drop2_item` varchar(50) DEFAULT NULL,
  `drop2_rate` smallint(9) unsigned DEFAULT NULL,
  `drop2_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop2_option` varchar(50) DEFAULT NULL,
  `drop2_index` tinyint(2) unsigned DEFAULT NULL,
  `drop3_item` varchar(50) DEFAULT NULL,
  `drop3_rate` smallint(9) unsigned DEFAULT NULL,
  `drop3_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop3_option` varchar(50) DEFAULT NULL,
  `drop3_index` tinyint(2) unsigned DEFAULT NULL,
  `drop4_item` varchar(50) DEFAULT NULL,
  `drop4_rate` smallint(9) unsigned DEFAULT NULL,
  `drop4_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop4_option` varchar(50) DEFAULT NULL,
  `drop4_index` tinyint(2) unsigned DEFAULT NULL,
  `drop5_item` varchar(50) DEFAULT NULL,
  `drop5_rate` smallint(9) unsigned DEFAULT NULL,
  `drop5_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop5_option` varchar(50) DEFAULT NULL,
  `drop5_index` tinyint(2) unsigned DEFAULT NULL,
  `drop6_item` varchar(50) DEFAULT NULL,
  `drop6_rate` smallint(9) unsigned DEFAULT NULL,
  `drop6_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop6_option` varchar(50) DEFAULT NULL,
  `drop6_index` tinyint(2) unsigned DEFAULT NULL,
  `drop7_item` varchar(50) DEFAULT NULL,
  `drop7_rate` smallint(9) unsigned DEFAULT NULL,
  `drop7_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop7_option` varchar(50) DEFAULT NULL,
  `drop7_index` tinyint(2) unsigned DEFAULT NULL,
  `drop8_item` varchar(50) DEFAULT NULL,
  `drop8_rate` smallint(9) unsigned DEFAULT NULL,
  `drop8_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop8_option` varchar(50) DEFAULT NULL,
  `drop8_index` tinyint(2) unsigned DEFAULT NULL,
  `drop9_item` varchar(50) DEFAULT NULL,
  `drop9_rate` smallint(9) unsigned DEFAULT NULL,
  `drop9_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop9_option` varchar(50) DEFAULT NULL,
  `drop9_index` tinyint(2) unsigned DEFAULT NULL,
  `drop10_item` varchar(50) DEFAULT NULL,
  `drop10_rate` smallint(9) unsigned DEFAULT NULL,
  `drop10_nosteal` tinyint(1) unsigned DEFAULT NULL,
  `drop10_option` varchar(50) DEFAULT NULL,
  `drop10_index` tinyint(2) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY (`name_aegis`)
) ENGINE=MyISAM;

REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`dex`,`size`,`race`,`racegroup_treasure`,`element`,`element_level`,`class`,`drop1_item`,`drop1_rate`,`drop1_nosteal`,`drop2_item`,`drop2_rate`,`drop2_nosteal`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`,`drop5_item`,`drop5_rate`,`drop5_nosteal`,`drop6_item`,`drop6_rate`,`drop6_nosteal`) VALUES (30002,'CAIXA_SMOKE','Caixa Smoke','Caixa Smoke',99,1199,'Small','Formless',true,'Neutral',1,'Event','nossaCoin',10000,true,'nossaCoin',7000,true,'nossaCoin',6000,true,'nossaCoin',5000,true,'nossaCoin',2000,true,'nossaCoin',1000,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30003,'1_alphoccio','Caminhante da Vida','Caminhante da Vida',45,10000,220,320,35,15,45,40,35,30,45,15,1,3,10,'Small','Demon','Neutral',1,155,160,816,504,'26',true,true,true,true,'smw_rune_frag_life',50,'smw_rune_frag_ancestral',50);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30004,'2_alphoccio','Sentinela da Vida','Sentinela da Vida',55,30000,330,480,50,22,58,52,46,39,58,20,1,4,12,'Medium','Demon','Neutral',2,150,140,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_life',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_life',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop2_nosteal`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30005,'4_alphoccio_r','Protetor da Vida','Protetor da Vida',65,150000,660,960,88,38,80,72,63,54,80,27,2,6,14,'Large','Demon','Neutral',3,145,120,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_life',50,'smw_rune_essence_life',10,true,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30006,'1_chen','Caminhante do Fogo','Caminhante do Fogo',100,80000,520,720,70,35,80,72,65,60,85,30,1,4,11,'Medium','Demon','Neutral',1,155,150,816,504,'26',true,true,true,true,'smw_rune_frag_fire',50,'smw_rune_frag_ancestral',50);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30007,'2_chen','Sentinela do Fogo','Sentinela do Fogo',110,240000,780,1080,100,50,105,95,85,78,110,40,1,5,13,'Large','Demon','Neutral',2,150,135,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_fire',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_fire',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30008,'4_chen','Protetor do Fogo','Protetor do Fogo',120,1200000,1560,2160,180,90,150,135,120,110,155,55,2,7,15,'Large','Demon','Neutral',3,145,115,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_fire',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_fire',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30009,'1_flamel','Caminhante do Gelo','Caminhante do Gelo',160,220000,850,1150,95,55,105,95,90,85,110,40,1,4,12,'Medium','Demon','Neutral',1,155,145,816,504,'26',true,true,true,true,'smw_rune_frag_ice',50,'smw_rune_frag_ancestral',50);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30010,'2_flamel','Sentinela do Gelo','Sentinela do Gelo',170,660000,1275,1725,135,78,135,122,115,108,140,55,1,5,14,'Large','Demon','Neutral',2,150,130,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_ice',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_ice',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30011,'4_flamel','Protetor do Gelo','Protetor do Gelo',180,3300000,2550,3450,220,125,190,170,160,150,195,75,2,7,16,'Large','Demon','Neutral',3,145,110,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_ice',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_ice',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30012,'1_josephina','Caminhante da Morte','Caminhante da Morte',210,500000,1400,1800,140,80,140,125,120,110,145,55,1,4,12,'Medium','Demon','Neutral',1,155,140,816,504,'26',true,true,true,true,'smw_rune_frag_death',50,'smw_rune_frag_ancestral',50);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30013,'2_josephina','Sentinela da Morte','Sentinela da Morte',220,1500000,2100,2700,200,110,180,160,150,140,185,70,1,6,15,'Large','Demon','Neutral',2,150,125,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_death',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_death',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30014,'4_josephina','Protetor da Morte','Protetor da Morte',230,7500000,4200,5400,320,180,250,225,210,195,260,95,2,8,18,'Large','Demon','Neutral',3,145,105,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_death',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_death',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30015,'1_magaleta','Caminhante Ancestral','Caminhante Ancestral',260,1200000,2000,2600,190,110,180,160,155,145,185,70,1,4,13,'Medium','Demon','Neutral',1,155,135,816,504,'26',true,true,true,true,'smw_rune_frag_ancestral',50,'smw_rune_frag_ancestral',50);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30016,'2_magaleta','Sentinela Ancestral','Sentinela Ancestral',270,3600000,3000,3900,270,150,230,205,195,180,235,90,1,6,16,'Large','Demon','Neutral',2,150,120,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`) VALUES (30017,'4_magaleta','Protetor Ancestral','Protetor Ancestral',300,18000000,6000,7800,420,230,320,285,265,245,330,120,2,9,20,'Large','Demon','Neutral',4,145,100,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30018,'1_eremes','Caminhante Divino','Caminhante Divino',280,1600000,2400,3000,220,125,200,180,170,160,205,80,1,4,13,'Medium','Demon','Neutral',2,155,130,816,504,'26',true,true,true,true,'smw_rune_frag_divine',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_divine',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30019,'2_eremes','Sentinela Divino','Sentinela Divino',290,5200000,3600,4500,320,180,260,235,220,205,265,105,1,6,17,'Large','Demon','Neutral',3,150,115,816,504,'21','Boss',true,true,true,true,'smw_rune_frag_divine',50,'smw_rune_frag_ancestral',50,'smw_rune_essence_ancestral',10,true,'smw_rune_essence_divine',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`ai`,`class`,`mode_canmove`,`mode_aggressive`,`mode_canattack`,`mode_mvp`,`mode_detector`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (30020,'4_eremes','Protetor Divino','Protetor Divino',320,32000000,7200,9000,520,280,380,340,320,295,390,150,2,9,21,'Large','Demon','Neutral',4,145,95,816,504,'21','Boss',true,true,true,true,true,'smw_rune_frag_divine',50,'smw_rune_frag_primo',50,'smw_rune_essence_primo',10,true,'smw_rune_essence_divine',10,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop6_item`,`drop6_rate`,`drop7_item`,`drop7_rate`,`drop8_item`,`drop8_rate`,`drop8_nosteal`) VALUES (21948,'HARDROCK_TITAN','Hardrock Titan','Hardrock Titan',263,47874030,1023843,855728,16625,3414,481,186,263,222,209,169,228,219,3,10,12,'Large','Formless','Earth',1,200,1000,500,480,100,'21','Evil_Minded_Ruby',100,'Great_Nature',100,'Stone_Heart',100,'Shadowdecon_Ore',100,'Zelunium_Ore',100,'Zelunium',100,'Shadowdecon',100,'Hardrock_Titan_Card',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop6_item`,`drop6_rate`,`drop7_item`,`drop7_rate`,`drop8_item`,`drop8_rate`,`drop8_nosteal`) VALUES (21949,'DEADWEEN','Deadween','Deadween',264,50482947,1054194,885523,14391,4260,410,231,179,148,171,179,174,171,2,10,12,'Medium','Brute','Poison',3,200,1000,500,480,100,'21','Congealed_Poison',100,'Rotten_Meat',100,'Animal\'s_Skin',100,'Shadowdecon_Ore',100,'Zelunium_Ore',100,'Zelunium',100,'Shadowdecon',100,'Deadween_Card',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop6_item`,`drop6_rate`,`drop7_item`,`drop7_rate`,`drop8_item`,`drop8_rate`,`drop8_nosteal`) VALUES (21946,'BURNING_KNIGHT','Burning Night','Burning Night',265,45319714,1065428,890485,19122,4033,504,195,296,249,235,189,256,246,1,10,12,'Large','Demon','Ghost',2,200,1000,500,480,100,'21','Blaze_Stone',100,'Burning_Heart',100,'Burning_Horse_Shoe',100,'Shadowdecon_Ore',100,'Zelunium_Ore',100,'Shadowdecon',100,'Zelunium',100,'Burning_Knight_Card',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop6_item`,`drop6_rate`,`drop7_item`,`drop7_rate`,`drop8_item`,`drop8_rate`,`drop8_nosteal`) VALUES (21947,'DEDSERA','Deadsera','Deadsera',262,48836035,995893,836550,11841,3569,409,230,180,148,172,180,225,172,7,10,12,'Small','Plant','Undead',2,200,1000,500,480,100,'21','Aromatic_Flower',100,'Sticky_Poison',100,'Root_Of_Maneater',100,'Shadowdecon_Ore',100,'Zelunium_Ore',100,'Zelunium',100,'Shadowdecon',100,'Dedsera_Card',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop6_item`,`drop6_rate`,`drop7_item`,`drop7_rate`,`drop8_item`,`drop8_rate`,`drop8_nosteal`) VALUES (21950,'GAIA_POL','Gaia Pol','Gaia Pol',270,401194387,1953747,1641148,21969,6757,435,247,207,171,197,207,201,197,1,10,12,'Large','Brute','Earth',4,200,1000,500,480,100,'21','Evil_Black_Bid',100,'Evil_Minded_Ruby',100,'Animal\'s_Skin',100,'Shadowdecon_Ore',100,'Zelunium_Ore',100,'Shadowdecon',100,'Zelunium',100,'Gaia_Pol_Card',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop5_nosteal`) VALUES (22395,'MEDJED','Medjed','Medjed',272,23535500,3367462,2345438,374,283,502,233,283,195,225,181,222,345,1,10,12,'Small','Angel','Ghost',2,200,1000,500,480,100,'21','Turn_Yellow_Leaf',100,'Whittling',100,'Amber',100,'Golden_Jewel',100,'aegis_300561',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (22396,'CP_MEDJED','Medjed','Medjed',272,51788960,10102388,7036314,414,323,582,292,323,234,257,216,335,422,1,10,12,'Small','Angel','Ghost',2,200,1000,500,480,100,'21','Whittling',100,'Turn_Yellow_Leaf',100,'Blue_Flame_Heart_Gem',100,'aegis_300561',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (22401,'HEKA','Heka','Heka',273,23207890,3411768,2387048,224,133,282,364,133,137,145,201,220,297,1,10,12,'Large','Demon','Wind',3,200,1000,500,480,100,'21','Slicky_Fluid',100,'Shining_Crystal',100,'Shadowdecon',100,'aegis_300564',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop3_nosteal`) VALUES (22402,'CP_HEKA','Heka','Heka',273,51101790,10235304,7161144,280,189,348,504,189,205,207,300,332,438,1,10,12,'Large','Demon','Wind',3,200,1000,500,480,100,'21','Shining_Crystal',100,'Slicky_Fluid',100,'aegis_300564',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop5_nosteal`) VALUES (22397,'MEDJAY','Medjay','Medjay',274,26708750,3484274,2426796,331,240,474,221,239,165,190,153,188,299,1,10,12,'Medium','DemiHuman','Fire',3,200,1000,500,480,100,'21','Red_Flame_Heart_Gem',100,'Blaze_Stone',100,'Evil_Minded_Ruby',100,'Amber',100,'aegis_300562',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop4_nosteal`) VALUES (22398,'CP_MEDJAY','Medjay','Medjay',274,58768350,10452822,7280390,364,273,547,274,273,198,217,183,289,369,1,10,12,'Medium','DemiHuman','Fire',3,200,1000,500,480,100,'21','Etel_Dust',100,'Evil_Minded_Ruby',100,'Blaze_Stone',100,'aegis_300562',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop3_item`,`drop3_rate`,`drop4_item`,`drop4_rate`,`drop5_item`,`drop5_rate`,`drop5_nosteal`) VALUES (22399,'OPHOIS','Ophois','Ophois',275,27228250,3521528,2452744,336,245,478,223,244,168,194,157,194,304,1,10,12,'Large','Undead','Dark',2,200,1000,500,480,100,'21','Congealed_Poison',100,'Dry_Wind_Leaf_Gem',100,'Evil_Black_Bid',100,'Violet_Jewel',100,'aegis_300563',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop2_item`,`drop2_rate`,`drop2_nosteal`) VALUES (22400,'CP_OPHOIS','Ophois','Ophois',275,60011470,10564584,7358234,371,280,552,277,279,202,222,186,294,375,1,10,12,'Large','Undead','Dark',2,200,1000,500,480,100,'21','Congealed_Poison',100,'aegis_300563',1,true);
REPLACE INTO `mob_db2_re` (`id`,`name_aegis`,`name_english`,`name_japanese`,`level`,`hp`,`base_exp`,`job_exp`,`attack`,`attack2`,`defense`,`magic_defense`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`attack_range`,`skill_range`,`chase_range`,`size`,`race`,`element`,`element_level`,`walk_speed`,`attack_delay`,`attack_motion`,`damage_motion`,`damage_taken`,`ai`,`drop1_item`,`drop1_rate`,`drop1_nosteal`) VALUES (22404,'GUIDE_OF_DEAD','Guide of Dead','Guide of Dead',275,776870690,45014318,31352472,511,420,1312,660,419,303,332,280,243,524,1,10,12,'Large','Undead','Dark',3,200,1000,500,480,100,'21','aegis_300565',1,true);
