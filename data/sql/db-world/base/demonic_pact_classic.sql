-- reduce Internal Cooldown from 20 seconds (20000) to 5 seconds (5000), some sources say 1 second (1000)
SET @ICD:=5000;
UPDATE `spell_proc_event` SET `Cooldown`=@ICD WHERE `entry` IN (53646, 54909);
DELETE FROM `spell_script_names` WHERE `spell_id` = 48090;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (48090, 'spell_warl_demonic_pact_classic');
