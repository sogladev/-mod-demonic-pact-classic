/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellScriptLoader.h"

// 48090 Demonic Pact (spellpower buff)
class spell_warl_demonic_pact_classic : public SpellScript
{
    PrepareSpellScript(spell_warl_demonic_pact_classic);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // remove targets that have stronger DP, unless DP has less than 10 seconds remaining
        int32 amount = GetSpellValue()->EffectBasePoints[EFFECT_0];
        targets.remove_if([&](WorldObject const* target) -> bool
        {
            if (const Unit* unit = target->ToUnit())
            {
                if (Aura* aur = unit->GetAura(48090))
                {
                    if (AuraEffect* aurEff = aur->GetEffect(0))
                    {
                        // do overwrite (do not remove target) if new DP is stronger
                        if (amount >= aurEff->GetAmount())
                        {
                            return false;
                        }
                    }
                    // do not overwrite (do remove target) if DP has more than 10 seconds (10000) remaining
                    if (aur->GetDuration() > 10000)
                    {
                        return true;
                    }
                }
            }
            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_demonic_pact_classic::FilterTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
    }
};

void AddSC_demonic_pact_classic_spell_script()
{
    RegisterSpellScript(spell_warl_demonic_pact_classic);
}
