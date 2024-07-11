-- restore Internal Cooldown to 20 seconds (20000)
SET @ICD:=20000;
UPDATE `spell_proc_event` SET `Cooldown`=@ICD WHERE `entry` IN (53646, 54909);
DELETE FROM `spell_script_names` WHERE `spell_id` = 48090;
