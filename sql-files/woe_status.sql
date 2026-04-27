DROP TABLE IF EXISTS `woe_status`;
CREATE TABLE `woe_status` (
  `status` tinyint(1) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM;
INSERT INTO `woe_status` (`status`) VALUES (0);