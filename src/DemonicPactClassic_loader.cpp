/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */
#include "Config.h"

// From SC
void AddSC_demonic_pact_classic_spell_script();

// Add all
// cf. the naming convention https://github.com/azerothcore/azerothcore-wotlk/blob/master/doc/changelog/master.md#how-to-upgrade-4
// additionally replace all '-' in the module folder name with '_' here
void Addmod_demonic_pact_classicScripts()
{
    if (!(sConfigMgr->GetOption<bool>("DemonicPactClassic.Enable", true)))
            return;
    AddSC_demonic_pact_classic_spell_script();
}

